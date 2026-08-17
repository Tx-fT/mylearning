



import os
import io
import base64
import httpx
from dotenv import load_dotenv
from PIL import Image
from langchain.agents import create_agent
from langchain_core.messages import HumanMessage
from langchain.chat_models import init_chat_model
from langchain_tavily import TavilySearch
from langgraph.checkpoint.sqlite import SqliteSaver
import sqlite3

load_dotenv("../../src/.env")

# 禁用 langchain-openai 的 TCP keepalive 注入（它会覆盖自定义 http_client 导致连接断开）
os.environ["LANGCHAIN_OPENAI_TCP_KEEPALIVE"] = "0"

# 自定义 HTTP 客户端：禁用系统代理 + 延长超时
http_client = httpx.Client(trust_env=False, timeout=httpx.Timeout(120.0))

# 视觉模型（支持图片多模态输入）
model = init_chat_model(
    model="qwen-vl-max",  # 视觉模型，支持图片输入（qwen-3.7-plus 是纯文本模型，不支持图片）
    model_provider="openai",
    base_url=os.getenv("DASHSCOPE_BASE_URL"),
    api_key=os.getenv("DASHSCOPE_API_KEY"),
    http_client=http_client,
    http_socket_options=(),  # 阻止 langchain-openai 注入自定义 transport
)

web_search = TavilySearch(
    max_results=5,
    topic="general"
)

# 数据库连接
db_connection = sqlite3.connect("../../resources/checkpoint.db", check_same_thread=False)
checkpointer = SqliteSaver(db_connection)
checkpointer.setup()

system_prompt = """你是顶级电影摄影指导兼AI视觉提示词工程师。收到图片后按以下结构输出：

一、画面分析：视觉风格、光线氛围、色彩基调、构图方式
二、主体描述：核心主体细节、背景环境与空间关系
三、电影级提示词：中文+English（含镜头规格/光线/构图/风格/氛围/主体细节，可用于Midjourney/SD/DALL·E/Sora）
四、拍摄参数：镜头焦段、光圈建议、1-2部风格相近的参考电影
五、变体灵感：3个同场景不同风格变体（如雨天/霓虹夜景/复古胶片）
"""

agent = create_agent(
    model=model,
    tools=[],  # 图片分析不需要工具调用，同时减小请求体
    system_prompt=system_prompt,
    checkpointer=checkpointer
)

# ===== 读取图片、压缩并编码 =====
image_path = "法国大革命.png"  # ← 改成你的图片文件名

# 1. 用 Pillow 打开图片，压缩到合理尺寸
img = Image.open(image_path)
original_size = os.path.getsize(image_path)
original_w, original_h = img.size
print(f"原始图片: {original_w}x{original_h}, {original_size / 1024:.1f} KB")

# 如果图片长边超过 1024 像素，等比缩放（严控体积）
max_dim = 1024
if max(original_w, original_h) > max_dim:
    ratio = max_dim / max(original_w, original_h)
    new_w, new_h = int(original_w * ratio), int(original_h * ratio)
    img = img.resize((new_w, new_h), Image.LANCZOS)
    print(f"已缩放至: {new_w}x{new_h}")

# 2. 转为 JPEG 格式（PNG 通常很大，JPEG 压缩率高）
buffer = io.BytesIO()
# 如果原图有透明通道，先转 RGB
if img.mode in ("RGBA", "P", "LA"):
    img = img.convert("RGB")
img.save(buffer, format="JPEG", quality=60)
image_bytes = buffer.getvalue()
print(f"压缩后: {len(image_bytes) / 1024:.1f} KB")

image_base64 = base64.b64encode(image_bytes).decode("utf-8")
print(f"base64 后: {len(image_base64) / 1024:.1f} KB")

# 图片格式统一为 JPEG（MIME: image/jpeg）
mime_type = "jpeg"

# 构建多模态消息：文本 + 图片
multimodel_message = HumanMessage(
    content=[
        {
            "type": "text",
            "text": "请分析这张图片，按照你的系统提示词输出完整的电影质感 AI 生成提示词。"
        },
        {
            "type": "image_url",
            "image_url": {
                "url": f"data:image/{mime_type};base64,{image_base64}"
            }
        }
    ]
)

config = {"configurable": {"thread_id": "1"}}
response = agent.invoke(
    {"messages": [multimodel_message]},
    config
)

for message in response["messages"]:
    message.pretty_print()