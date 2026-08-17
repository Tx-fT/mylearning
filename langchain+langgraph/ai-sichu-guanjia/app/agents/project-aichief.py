# 基于langsmith开发
# 基于langsmith一键部署的不需要自己做checkpointer，只需要把agent创建好就行
#
# 我们使用langgraph命令行在本地部署，先安装langgraph的依赖
# 要告诉langsmith自带的智能体：项目在哪个文件：要写个json文件
# 图片完整的数据会浪费大量token
# 方法：把上传图片的动作提前完成，地址给agent，oss（暂存）
# langchain入门实战——AI私厨管家
import os
from multiprocessing import connection
from pathlib import Path
from dotenv import load_dotenv
from langgraph.channels import topic
from tornado import web
load_dotenv(Path(__file__).resolve().parents[2] / "src" / ".env")
from langchain.agents import create_agent
from langchain.tools import tool
from langchain_core.messages import SystemMessage,HumanMessage,AIMessage
from langchain.chat_models import init_chat_model
from pydantic import BaseModel,Field#model，描述
from typing import Literal#枚举
from langchain_tavily import TavilySearch
from langgraph.checkpoint.memory import InMemorySaver
import sqlite3
from langgraph.checkpoint.sqlite import SqliteSaver#导入依赖
from langchain.agents.middleware import SummarizationMiddleware
from langchain_core.runnables import RunnableConfig#config的数据类型

# 需求分析
# AI私厨管家是一个基于langchain和多模态的食谱多模态应用。用户可以拍摄自家冰箱或厨房的食物照片，管家会自动识别图片中的食材，根据食材搜索相关食谱推荐给用户
# ... existing code ...
# 需求分析
# AI私厨管家是一个基于langchain和多模态的食谱多模态应用。用户可以拍摄自家冰箱或厨房的食物照片，管家会自动识别图片中的食材，根据食材搜索相关食谱推荐给用户

model=init_chat_model(
    model="qwen3.7-plus",
    model_provider="openai",
    base_url=os.getenv("DASHSCOPE_BASE_URL"),
    api_key=os.getenv("DASHSCOPE_API_KEY")
)
web_search=TavilySearch(
    max_results=5,
    topic="general"
)
# connection=sqlite3.connect("../../resources/checkpoint.db", check_same_thread=False)
# checkpointer=SqliteSaver(connection)
# checkpointer.setup()

system_prompt="""
1.识别和评估食材：若用户提供照片，首先辨识所有可见食材。基于食材的外观形状，评估其新鲜度与可用量，整理出一份“当前可用食材清单”。
2.智能食谱检索：优先调用web_search工具，以“可用食材清单”为核心关键词，查找可行菜谱。
3.多维度评估与排序：从营养价值和制作难度两个维度对检索到的候选食谱进行量化打分，并根据得分排序，制作简单且营养丰富的排名靠前。
4.结构化方案输出：把排序后的食谱整理为一份结构清晰的建议报告，要包含食谱信息、得分、推荐理由、食谱的参考图片，帮助用户快速做出决策。
请严格按照流程，优先调用web_search工具搜索食谱，搜索不到的情况下才能自己发挥。
"""

agent=create_agent(
    model=model,
    tools=[web_search],
    system_prompt=system_prompt
    # checkpointer=checkpointer
)

multimodel_message=HumanMessage(
    [
        {"type":"text","text":"看看图片把然后按系统提示词输出"},
        {"type":"image_url","image_url":{"url":"https://img95.699pic.com/photo/50764/1552.jpg_wh860.jpg"}}
    ]
)

config={"configurable":{"thread_id":"1"}}

response=agent.invoke(
    {
        "messages":[multimodel_message],
    },
    config
)

for message in response["messages"]:
    message.pretty_print()
