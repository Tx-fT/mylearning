#AI通识和基础
#AI是机器向人类一样思考，学习和解决问题的技术
# from langsmith.integrations.strands_agents import exporter

#神经网络的结构：神经网络架构，本质就是在模拟人类大脑神经元。将千千万万个神经元连接起来，这就组成了深度神经网络
#深度神经网络分为很多层，是神经网络基本的计算单元：
#输入层：入口，接收数据
#隐藏层：信息处理和学习。可以有很多层（每一个隐藏层的每一个神经元都类似人脑神经元细胞）
#输出层：出口，产生结果

# 公式：y=g(sigma(i=1-n)wi*xi-b)
#xi：值  wi：权重->求和->偏置量b修正达到阈值->求和->g()：激活函数
# 设置权重决定性作用
# 反向传播：
#  1.前向传播：数据逐层加工，直到输出层产生结果
#  2.计算误差：计算产出结果与正确结果的误差
#  3.反向追责：倒退计算每一层每个连接对误差的贡献
#  4.调整权重

#大语言模型
#词向量：就是把词转为多维空间向量的一种技术
#首先，将人类自然语言文字拆分为一个个片段，token
#每个token都经过模型计算转为一个浮点数数组，作为向量坐标
#transformer-注意力机制
#自注意力机制：是模型更高效的根据上下文信息处理token，理解token含义
#word embedding(token->词向量)->Attention(进一步上下文向量方向微调)->MLP(多层感知机：进一步深度推理分析)->重复
#->softmax(将向量转为token：unembedding)—>与前文拼接再次输入；
#softmax：会根据计算出的向量结果得出下一个token的概率分布，然后基于概率随机“采样方式”（都看概率）挑选一个作为结果。
#这个概率模型受temperature参数影响，值越大，概率分布越均匀，模型生成结果的随机性越强；反之，结果越确定
#当模型规模和训练数据量突破到某个临界点，“涌现”（量变引起质变）->大语言模型

#GPT（generative pre-trained transformer）
#生成式：根据上文预测紧跟着的下一个token，从而形成连续的文本输出
#预训练：大规模文本数据训练
#transformer：神经网络结构
#对话机器人（chatbot）：可以与用户聊天答疑，具有记忆的大模型应用
#大模型应用：基于大模型的推理分析生成能力，结合传统编程精确计算控制能力，开发出的各种应用，有需要大模型的调用api
# ai：模糊，概念，预测 传统：精确
#gpt：大院一年模型
#chatgpt：大模型应用

#大模型接口
#请求行，请求头，请求体（modle，message，stream，temperature：随机读正相关……）

#环境准备
# pycharm+uv

#langchain
#认识langchain用于开发智能体的平台
#agent：（智能体，可以执行任务，并调用其他工具，或代理）是一种能感知环境，进行推理，自主决策并采取行动以实现目标的智能系统
#tool：工具，可以调用外部资源，如数据库，api，文件，网络，等等
#memory：记忆，记录智能体执行过的任务，并记住结果
#prompt：提示，描述智能体的任务，并给出输入输出的例子
#llm：大语言模型，如gpt-3，gpt-4，llama，mistral，starcoder，alpaca，llama2，bloom，gpt-j，gpt-neox，gpt-2，gpt-1，gpt-0，gpt-s,gpt-l,gpt-xl,gpt-xxl,gpt-xxxl
#vectorstore：向量数据库，将文本数据转换为向量，并保存在数据库中，用于检索
#textsplitter：文本分割，将长文本分割成短文本，如：将长文档分割成段落，将长文本分割成句子，将长文本分割成单词
#textloader：文本加载，将文本数据加载到数据库中
#embedding：嵌入，将文本数据转换为向量。
#retriever：检索，从向量数据库中检索向量，并返回结果
#chain：链，将多个工具组合在一起，实现一个完整的任务

#agent怎么做到
#llm只是“缸中之恼”+传统编程“手脚”=agent（1.任务规划（llm）2.调用工具3.感知反馈）

#案例
#天气查询智能体
#若直接询问llm，只会到最近更新，所以用传统编程拉取投喂

#1.加载环境变量
#2.定义工具
#3.定义agent
#4.调用agent

#agent执行流程
#1.用户提问（input）->2.modle（1.是否需要调用工具2.调用那个工具3.工具执行结果是否足以回答用户问题）
#->3.若调用工具，返回工具结果给agent->2->4.output

#agent怎么知到tool：langchain可以把response和工具函数（其中有description）一起打包给llm来判断，这样就知道工具信息的存在
#agent怎么调用tool：模型的回应tool_calls会告诉你想调哪个工具，然后langchain用tool编程调用工具，返回结果给agent

#总结：input->langchain打包->modle抉择返回想要用啥tool->langchain调用tool->modle分析调用结果，决定是否输出->output

#modle:langchain支持现在市面上大部分常见的大语言模型，并提供了各个模型的依赖库
# from langchain.chat_models import init_chat_model
# model = init_chat_model()

# #配置库
# #配置环境

# import os
# from dotenv import load_dotenv
#
# load_dotenv()
#
# # 检查 API Key
# api_key = os.getenv('DEEPSEEK_API_KEY')
# print(f"API Key 存在: {api_key is not None}")
# print(f"API Key 前缀: {api_key[:10]}..." if api_key else "未配置")
#
# # 测试模型调用
# from langchain.chat_models import init_chat_model
# model = init_chat_model(model='deepseek-v4-pro')
#
# # 简单测试
# response = model.invoke("你好")
# print(response.content)

# import os
# from dotenv import load_dotenv
# load_dotenv()
# #导入langchain的初始化模型函数
# from langchain.chat_models import init_chat_model
# #初始化模型
# #参数model用来指定模型名称，langchain会根据模型名字自动设定base_url，从环境变量中获取api_key
# model = init_chat_model(
#     model='deepseek-v4-pro',
    #tempreture=0.1,控制文本的随机性值越小约随机
    #stream=True,控制是否流式返回结果
    #max_tokens=1024,控制返回结果的最大长度
    #top_p=0.9,控制文本的生成概率，文本多样性，值越小越确定
    #n=1,控制一次请求返回的结果数量
    #model_provider='deepseek',控制模型提供者，目前支持deepseek和openai(模板)
#)init_chat_model()里可以自定义api-key和base-url
#调用
#阻塞模型调用
# response = model.invoke("今天天气如何")
# print(response.content)
#流式模型调用
# respose = model.stream("")
# for chunk in response:
#     print(chunk.content,end="",flush=True)

#在智能体中使用模型
#创建智能体
#langchain：creat_agent():1使用初始化好的模型对象2使用模型名称，让langchain自动初始化模型
# from langchain.agents import create_agent
# #使用初始化好的
# agent=create_agent(model=model)
# agent=create_agent(model='deepseek-v4-pro')
# #调用智能体
# response=agent.invoke({
#     "message":[{"role":"user","content":"今天天气如何"}]
# })
# print(response)
#流式模型调用
# response = agent.stream({
#     "message":[{"role":"user","content":"今天天气如何"}]},
#     stream_mode="messages"#流的模式
# )
# for token,metadata in response:
#     if token.content:
#         print(token,end="",flush=True)

#message
# 在langchain中，发送给模型的消息，和模型返回的消息都统一封装为basemessage，并且准备了多个basemessage的子类对应不同角色类型的消息
# import os
# from dotenv import load_dotenv
# from langchain.agents import create_agent
# from langchain.tools import tool
# from langchain_core.messages import SystemMessage,HumanMessage,AIMessage
# from langchain.chat_models import init_chat_model
# load_dotenv()
# @tool
# def get_weather(city: str) -> str:
#     """Get the weather in a given city"""
#     return "It's sunny in %s" % city
# # agent=create_agent(model='deepseek-v4-pro',tools=[get_weather])
# #多模态model伪装成openai
# model = init_chat_model(
#     model='deepseek-v4-pro',
#     model_provider='openai',
#     api_key=os.getenv('DEEPSEEK_API_KEY'),
#     base_url=os.getenv('DEEPSEEK_BASE_URL')
# )
# agent=create_agent(model=model)
# #准备多模态内容
# # 直接字典存要输入内容
# message = HumanMessage([
#     # 消息格式是列表
#         {"type":"text","text":"描述以下图片内容"},
#         {"type":"image-url","url":"https://c-ssl.duitang.com/uploads/blog/202502/20/XxS9aNgBuQXb4Jw.jpg"}#在线图片
#         #要想本地要加组件
#     #deepseek暂不支持图片识别
# ])
# #流式
# stream=agent.stream({"messages":[message]},stream_mode="messages")
# for chunk,metadata in stream:
#     if chunk.content:
#         print(chunk.content,end="",flush=True)
#大字典存messages列表存字典对话呢容
# response=agent.invoke({
#     "messages":[
#         # 2 ways,字典设定
#         {"role":"system","content":"你叫小A，是一个智能助手"},
#         SystemMessage(content="请使用工具来获取天气"),
#         HumanMessage("你好我是xf"),
#         AIMessage("你好，很高兴认识你"),
#         {"role":"user","content":"今天%s的天气如何" % "北京"}
#     ]
# })
# #lanchain自带让agent流程更加直观
# for message in response['messages']:
#     message.pretty_print()
#多模态消息
#不仅有文本消息，langchain也支持向模型发送多模态消息，比如图片、音频、视频等等。但前提是必须是多模态模型才行

#prompts
#就是发送给模型的消息，其中SystemMessage是系统提示词（system prompt），可以给模型设定角色，聊天的背景，任务说明，对模型生成的内容有很大影响

#如何设定系统提示词
# agent=create_agent(
#     model='deepseek-v4-pro',
#     system_prompt="""
#     你是一个智能助手，你的任务是帮助用户完成任务
#     """
#     #提示词工程（prompt engineering），就是通过优化提示词使模型的输出结果更符合业务需求的过程
#     #1.设定角色和指令
#     #2.对话示例（few-shot example）(言传身教)
#     #3.结构化输出（json格式输出）
#     #langchain里自带的结构化输出：
#     # class capitalinfo(BaseModel):
#     #     capital: str
#     #     country: str
#     #     population: int
#     #     area: int
# )

#tool
# 1.自定义工具：本质上是一个可调用的函数，但是是给模型调用，因此除了定义函数外，我们还需要清晰猫叔这个工具，仍模型知道工具如何使用
#工具名+工具的作用+工具需要的参数
# @tool#("square_root",description="calculate the square root of a number")
# def square_root(number: float) -> float:
#     """Calculate the square root of a number"""
#     return number ** 0.5
# 当参数比较复杂时
# 定义pydantic model描述参数
# class WeatherInput(BaseModel):
#     """查询天气输入参数"""
#     location:str=Field(description="city name or  coordinate")
#     units:Literal["celsius","fahrenheit"]=Field(
#         default="celsius",
#         description="Temprature unit performance"
#     )
#     include_forcast:bool=Field(
#         default=False,
#         description="whether to include forcast"
#     )
# @tool(args_schema=WeatherInput)#参数约束，langchain就能提取信息作为参数的描述
# def get_weather(location:str,units:str="celsius",include_forcast:bool=False)->str:
#     """Get current weather and optional forcast"""
#     temp=22 if units=="celsius" else 72
#     result = f"Current weather in {location} : {temp} degrees {units[0].upper()}"
#     if include_forcast:
#         result += "\nForcast: Sunny"
#     return result
# agent=create_agent(
#     model='deepseek-v4-pro',
#     tools=[get_weather]
# )
# response=agent.invoke({
#     "messages":[
#         SystemMessage("请使用工具来获取天气"),
#         HumanMessage("今天%s的天气如何" % "北京")
#     ]
# })
# for message in response['messages']:
#     message.pretty_print()
#预定义工具
#有些工具langchain已经定义好了，比如搜索、翻译、计算器等等
#Tavily search API，给模型的搜索工具
import os
from dotenv import load_dotenv
load_dotenv()
from langchain.agents import create_agent
from langchain.tools import tool
from langchain_core.messages import SystemMessage,HumanMessage,AIMessage
from langchain.chat_models import init_chat_model
from pydantic import BaseModel,Field#model，描述
from typing import Literal#枚举
from langchain_tavily import TavilySearch
from langgraph.checkpoint.memory import InMemorySaver

search_tool=TavilySearch(#本质就一工具
    api_key=os.getenv('TAVILY_API_KEY'),
    max_results=5,
    safe_search=True,
    language="en"
)
#结构化输出的限制
#agent回答内容引用的网页信息
class reference(BaseModel):
    title:str=Field(description="the title of the web page cited in the answer")
    url:str=Field(description="the url of the web page cited in the answer")
#agent的回答内容
class answerinfo(BaseModel):
    answer:str=Field(description="the answer to the user's question")
    references:list[reference]=Field(description="the web pages cited in the answer")
# message=search_tool.invoke("古月方源是谁")
# print(message)
#自己封装为tool
@tool
def web_search(query:str):
    """search the web for information"""
    return search_tool.invoke(query)
agent =create_agent(
    model='deepseek-v4-pro',
    tools=[web_search],
    checkpointer=InMemorySaver(),#记忆
    system_prompt="你是一个智能助手，你使用工具来解决用户问题",
    response_format=answerinfo#设置智能体格式
)
config ={"configurable":{"thread_id":"111"}}
response=agent.invoke(
    {"messages":[
        HumanMessage("古月方源是谁")
    ]},
    config
)
for message in response['messages']:
    message.pretty_print()
#目前的搜索智能体存在两个问题：
# 1.官方默认的tavily工具过于复杂
# 2.结果不包含网页数据源，可信度低
#解决思路：
# 1.自定义tavily工具
# 2.结构化输出

#短期记忆
#langchain中记忆工具，与对话大模型记忆不同，agent记忆分为两类：（记忆的作用域）
#短期记忆：当前任务或会话的上下文
#长期记忆：跨任务与会话的经验与知识
#短期记忆：
#在langchain短期记忆是通过Agentstate实现的，而会话历史（消息列表）是AgentState的一部分
#langchain提供了checkpoiter对象来保存agentstate，每一次用户与AI交互都会生成一个快照，记录为一个checkpoiter
#同一会话的多个checkpoint形成一个组，用同一个thread_id来表示（区分会话）























