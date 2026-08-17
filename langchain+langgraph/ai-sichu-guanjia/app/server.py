# -*- coding: utf-8 -*-
"""
AI 私厨管家 —— 后端服务

与 Next.js 前端（私厨-前端源码）对接，提供：
  1. 图片上传（本地存储，模拟 OSS 预签名上传）
  2. 流式聊天（原始文本流，前端直接拼接）
  3. 聊天历史查询（基于 checkpointer 的会话记忆）
  4. 清空聊天历史

启动：
  .venv/Scripts/python.exe app/server.py
  或
  uvicorn app.server:app --host 0.0.0.0 --port 8001
"""
import os
import io
import base64
import mimetypes
from pathlib import Path
from contextlib import asynccontextmanager
from urllib.parse import urlparse

import httpx
from PIL import Image
from dotenv import load_dotenv

from fastapi import FastAPI, Request
from fastapi.middleware.cors import CORSMiddleware
from fastapi.responses import StreamingResponse, JSONResponse
from fastapi.staticfiles import StaticFiles
from pydantic import BaseModel

from langchain.agents import create_agent
from langchain.chat_models import init_chat_model
from langchain_core.messages import (
    HumanMessage,
    AIMessage,
    SystemMessage,
    ToolMessage,
    AIMessageChunk,
)
from langchain_tavily import TavilySearch
from langgraph.checkpoint.sqlite.aio import AsyncSqliteSaver

# ============ 1. 加载环境变量 ============
# .env 位于项目根目录下的 src/.env 中（相对本文件的 parents[1]）
PROJECT_ROOT = Path(__file__).resolve().parents[1]
load_dotenv(PROJECT_ROOT / "src" / ".env")

# ============ 2. 模型与工具 ============
# 禁用 langchain-openai 的 TCP keepalive 注入（它会覆盖自定义 http_client 导致连接断开）
os.environ["LANGCHAIN_OPENAI_TCP_KEEPALIVE"] = "0"

# 自定义 HTTP 客户端：禁用系统代理 + 延长超时
http_client = httpx.Client(trust_env=False, timeout=httpx.Timeout(120.0))
http_async_client = httpx.AsyncClient(trust_env=False, timeout=httpx.Timeout(120.0))

# 视觉模型（支持图片多模态输入 + 工具调用），通过 DashScope 的 OpenAI 兼容接口访问
model = init_chat_model(
    model="qwen-vl-max",
    model_provider="openai",
    base_url=os.getenv("DASHSCOPE_BASE_URL"),
    api_key=os.getenv("DASHSCOPE_API_KEY"),
    http_client=http_client,
    http_async_client=http_async_client,
    http_socket_options=(),  # 阻止 langchain-openai 注入自定义 transport
)

# 食谱检索工具
web_search = TavilySearch(
    max_results=5,
    topic="general",
)

# ============ 3. 系统提示词（AI 私厨管家） ============
system_prompt = """
1.识别和评估食材：若用户提供照片，首先辨识所有可见食材。基于食材的外观形状，评估其新鲜度与可用量，整理出一份“当前可用食材清单”。
2.智能食谱检索：优先调用web_search工具，以“可用食材清单”为核心关键词，查找可行菜谱。
3.多维度评估与排序：从营养价值和制作难度两个维度对检索到的候选食谱进行量化打分，并根据得分排序，制作简单且营养丰富的排名靠前。
4.结构化方案输出：把排序后的食谱整理为一份结构清晰的建议报告，要包含食谱信息、得分、推荐理由、食谱的参考图片，帮助用户快速做出决策。
请严格按照流程，优先调用web_search工具搜索食谱，搜索不到的情况下才能自己发挥。
"""

# ============ 4. 上传目录与数据库 ============
UPLOAD_DIR = PROJECT_ROOT / "resources" / "uploads"
UPLOAD_DIR.mkdir(parents=True, exist_ok=True)

DB_PATH = PROJECT_ROOT / "resources" / "checkpoint.db"


# ============ 5. 智能体（在 FastAPI 生命周期内创建） ============
agent = None  # 在 lifespan 中初始化


@asynccontextmanager
async def lifespan(app: FastAPI):
    """应用启动时创建智能体，退出时释放资源"""
    global agent
    async with AsyncSqliteSaver.from_conn_string(str(DB_PATH)) as checkpointer:
        await checkpointer.setup()
        agent = create_agent(
            model=model,
            tools=[web_search],
            system_prompt=system_prompt,
            checkpointer=checkpointer,
        )
        yield
    await http_async_client.aclose()


app = FastAPI(title="AI 私厨管家", lifespan=lifespan)

# 跨域：允许前端（Next.js 默认 3000 端口）访问
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_methods=["*"],
    allow_headers=["*"],
)

# 静态图片访问（前端 <img> 需要加载已上传图片）
app.mount("/uploads", StaticFiles(directory=str(UPLOAD_DIR)), name="uploads")


# ============ 6. 请求/响应模型 ============
class ChatRequest(BaseModel):
    message: str = ""
    image_url: str | None = None
    thread_id: str | None = None


# ============ 7. 工具函数 ============
def _compress_image_to_base64(image_bytes: bytes) -> str:
    """压缩图片（长边 <= 1024、转 JPEG），返回 base64 data URL，用于多模态输入"""
    img = Image.open(io.BytesIO(image_bytes))
    max_dim = 1024
    if max(img.size) > max_dim:
        ratio = max_dim / max(img.size)
        new_size = (int(img.width * ratio), int(img.height * ratio))
        img = img.resize(new_size, Image.LANCZOS)
    if img.mode in ("RGBA", "P", "LA"):
        img = img.convert("RGB")
    buf = io.BytesIO()
    img.save(buf, format="JPEG", quality=60)
    return "data:image/jpeg;base64," + base64.b64encode(buf.getvalue()).decode("utf-8")


async def _load_image_as_data_url(image_url: str) -> str:
    """把图片 URL 转为 base64 data URL。
    - 本地已上传图片（/uploads/）直接从磁盘读取；
    - 远程图片用 httpx 下载。
    """
    # 本地图片：从磁盘读取，避免自己请求自己
    if "/uploads/" in image_url:
        filename = Path(urlparse(image_url).path).name
        local_path = UPLOAD_DIR / filename
        if local_path.exists():
            return _compress_image_to_base64(local_path.read_bytes())

    # 远程图片：下载
    async with httpx.AsyncClient(trust_env=False, timeout=30.0) as client:
        resp = await client.get(image_url)
        resp.raise_for_status()
    return _compress_image_to_base64(resp.content)


def _serialize_message(msg) -> dict | None:
    """把 LangChain 消息转为前端约定的 {role, content} 格式。
    ToolMessage 不返回（工具中间结果不展示给用户）。
    """
    if isinstance(msg, ToolMessage):
        return None
    if isinstance(msg, HumanMessage):
        role = "user"
    elif isinstance(msg, AIMessage):
        role = "assistant"
    elif isinstance(msg, SystemMessage):
        role = "system"
    else:
        role = "assistant"

    content = msg.content
    if isinstance(content, str):
        return {"role": role, "content": content}

    if isinstance(content, list):
        parts = []
        for part in content:
            ptype = part.get("type") if isinstance(part, dict) else None
            if ptype == "text":
                parts.append({"type": "text", "text": part.get("text", "")})
            elif ptype == "image_url":
                url = part.get("image_url", {}).get("url", "")
                # base64 data URL 过大，不返回给前端；仅返回真实的 http 图片地址
                if not url.startswith("data:"):
                    parts.append({"type": "image", "url": url})
        if len(parts) == 1 and parts[0]["type"] == "text":
            return {"role": role, "content": parts[0]["text"]}
        return {"role": role, "content": parts}

    return {"role": role, "content": str(content)}


# ============ 8. 接口 ============
@app.get("/")
def root():
    return {"service": "AI 私厨管家", "status": "running"}


@app.get("/api/v1/oss/presign")
def get_presign_url(request: Request, filename: str):
    """返回上传地址（本地存储，模拟 OSS 预签名 URL）。
    前端拿到 uploadUrl 后，用 PUT 上传文件；accessUrl 用于展示与后续发给模型。
    """
    filename = Path(filename).name  # 防止路径穿越
    base = str(request.base_url).rstrip("/")
    content_type = mimetypes.guess_type(filename)[0] or "image/jpeg"
    return {
        "uploadUrl": f"{base}/api/v1/upload/{filename}",
        "accessUrl": f"{base}/uploads/{filename}",
        "contentType": content_type,
    }


@app.put("/api/v1/upload/{filename}")
async def upload_image(filename: str, request: Request):
    """保存前端 PUT 上来的图片字节"""
    filename = Path(filename).name
    data = await request.body()
    (UPLOAD_DIR / filename).write_bytes(data)
    return {"url": f"/uploads/{filename}"}


@app.post("/api/v1/chat/stream")
async def chat_stream(req: ChatRequest):
    """流式对话。返回原始文本流，前端逐段拼接显示。"""
    thread_id = req.thread_id or "default"
    config = {"configurable": {"thread_id": thread_id}}

    # 构建多模态消息：文本 + （可选）图片
    content_parts = []
    if req.image_url:
        try:
            data_url = await _load_image_as_data_url(req.image_url)
            content_parts.append(
                {"type": "image_url", "image_url": {"url": data_url}}
            )
        except Exception as e:
            # 图片加载失败不阻断对话，仅把错误追加到输出
            content_parts.append(
                {"type": "text", "text": f"\n[图片加载失败]: {e}"}
            )

    text = req.message or "这是我冰箱里的食物，帮我看看能做什么佳肴？"
    content_parts.append({"type": "text", "text": text})

    human = HumanMessage(content=content_parts)

    async def generate():
        try:
            async for chunk, _metadata in agent.astream(
                {"messages": [human]},
                config=config,
                stream_mode="messages",
            ):
                # 只输出助手的文本内容，跳过工具调用/工具结果
                if isinstance(chunk, AIMessageChunk):
                    content = chunk.content
                    if isinstance(content, str) and content:
                        yield content
        except Exception as e:
            yield f"\n[错误]: {e}"

    return StreamingResponse(generate(), media_type="text/plain; charset=utf-8")


@app.get("/api/v1/chat/messages")
async def get_messages(thread_id: str):
    """查询某个会话的历史消息"""
    config = {"configurable": {"thread_id": thread_id}}
    state = await agent.aget_state(config)
    messages = []
    if state.values and "messages" in state.values:
        for msg in state.values["messages"]:
            serialized = _serialize_message(msg)
            if serialized is not None:
                messages.append(serialized)
    return {"messages": messages}


@app.delete("/api/v1/chat/messages")
async def clear_messages(thread_id: str):
    """清空某个会话的历史记录（删除该 thread 的所有 checkpoint）"""
    try:
        await agent.checkpointer.adelete_thread(thread_id)
    except Exception:
        pass
    return {"ok": True}


if __name__ == "__main__":
    import uvicorn

    uvicorn.run(app, host="0.0.0.0", port=8001)
