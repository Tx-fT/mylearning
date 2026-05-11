#大模型
# 大模型应用
# 1.本地部署ollama 训练好的接入本地：用本地算力较低1
# 2.api（应用程序编程接口（Application Programming Interface, API） [1]，也称应用编程接口，是一组为不同软件组件之间交互而创建的定义和协议。API定义了软件模块之间如何相互交互，包括可以调用哪些功能、如何调用、需要提供的数据格式，以及返回结果的形式。通过API，开发者可以复用现有能力，而无需了解或修改底层实现细节。）
#   客户端调用服务端

# 计算机网络

# IP地址：设备在互联网中的地址
# IPv4地址：32位二进制
# 132.12.86.125（0-255）：100001000.00001100.01010110.01111101
# 127.0.0.1：是一个特殊的IP地址，表示的是本机地址（也称本地回环地址）（访问本地某个服务）
# IPv6地址：128位二进制

#域名：
# 是由一串用点隔的英文字母组成。IP地址不方便记忆，因此设计出了域名，并通过DNS（域名解析服务器）来将域名和IP地址互相映射，便于记忆和访问
# 已定位到某个服务器后：要访问那个应用需要用到端口

# 端口：
# 端口号是整数，取值范围在0-65535，它是用来标识计算机设备中运行的程序
# 端口号体现在哪？：采用http协议默认端口号为80，https协议默认端口号为443

# 总结：用IP地址/域名定位设备，再用端口号地位应用程序，这样客户端和服务器端建立连接

# 然后数据传输：数据传输的规则
# 国际IOS组织统一了程序在网络通信中的模型和标准：
# 1.OSI网络模型：七层：从下网上：物理层-数据链路层-网络层-传输层-会话层-表示层应用层
# 2.TCP/IP（可认为OSi简化版）：四层：网络接口层-网络层（）-传输层-应用层
# 应用层：将用户应用程序交互的数据按照协议格式进行封装
# 传输层：负责将数据吹却送到对应程序（端口）
# 网络层：基于IP地址将数据包传给对应设备
# 网络接口层：负责数据在物理网络中的传输，处理与硬件设备的交互


# HTTP协议（超文本传输协议）
# 规定了客户端和服务器端数据传输的规则（应用层）
# 特点：1.基于文本协议：请求和响应的部分的协内容为文本格式，底层通过TCP协议传输，稳定性强
#      2.基于请求响应模型
#      3.无状态：服务端不会记忆与客户端的历史交互信息。，每一次请求响应都是独立的

# HTTP协议-请求数据格式**

# POST /api/courses HTTP/1.1   *请求行（请求方式，资源路径，协议）
# 请求方式：1.get：请求参数在请求行中。如/api/course?name=Python&status=1.GET请求参数大小在浏览器中是有限制的（？后为请求参数）
#          2.post：请求参数在请求体重，POST请求大小是没有限制的
# Accept: application/jsom,text/plain,*/*  *请求头（格式key：value）//能接受的格式资源
# .........
# 空一行
# {"phone":"123456"}  *请求体（请求参数部分，GET方式没有，POST可以有）

# HTTP-响应数据格式**

# HTTP/1.1 200   *响应行（协议，状态码：告诉客户端请求成败）
#   200：客户端请求成功     400：请求参数错误      404：请求资源不存在，url输入错误，或者网站资源被删除了
#   500：服务器发生了不可预期的错误
# Server: nginx/1.24.0 //请求的是哪个服务器     *响应头（格式key：value）
# Data: Tue,16 Dec 2025 12:01:01 GMT //time
# ......
# 空一行
# {code: 1,msg:"success", data:null}  *响应体（存放服务器响应数据）（key：value（json格式））


# apifox测试

# json格式：JSON，是前端的一种对象表示方法。表示形式类似于python中的字典，都是key：value，不过所有的key都必须用双引号，只可以为任意类型
# 对象：用{}表示，{}之间键值形式，键字符串，值可为任意类型     值也可为列表，存放多个元素

# curl https://api.deepseek.com/chat/completions \  *请求行：请求方式+资源路径+协议
#   -H "Content-Type: application/json" \       *请求头：规定
#   -H "Authorization: Bearer ${DEEPSEEK_API_KEY}" \
#   -d '{                                              *请求体：json格式
#         "model": "deepseek-v4-pro",  用啥
#         "messages": [
#           {"role": "system", "content": "You are a helpful assistant."},  系统：你是谁，设置AI设
#           {"role": "user", "content": "Hello!"}                           用户：用户实际提出的问题或指令
#           {"role": "assistant","content": --}                             ai响应
#         ],
#         "thinking": {"type": "enabled"},
#         "reasoning_effort": "high",
#         "stream": false               流式输出：一个字一个字（否）
#       }'
#
# ai大模型本质无状态（无记忆）
# 会话记忆-处理方案（会话历史滚雪球）：把上文再抓一次


# 基于python代码调用deepseek大模型
# Please install OpenAI SDK first: `pip3 install openai`

# URL 是 Uniform Resource Locator（统一资源定位符）的缩写。
# #
# # 通俗来说，URL 就是网站地址，也就是你用来在互联网上找到某个特定网页、图片、视频或文件的那串字符。
# #
# # 一个典型的 URL 例子（比如 https://www.baidu.com）通常包含几个部分：
# #
# # 协议：如 https://，告诉浏览器用什么方式访问。
# #
# # 域名：如 www.baidu.com，指向具体的网站。
# #
# # 路径：如 /s 或 /videos/play，表示网站上的某个具体页面或位置。
# #
# # 参数：如 ?wd=苹果，提供额外信息（比如搜索关键词）。

# import os  # 用os，提取本地环境os.environ.get(变量名)
# from openai import OpenAI
#
# # 创建与AI大模型交互的客户端
# client = OpenAI(
#     api_key=os.environ.get('DEEPSEEK_API_KEY'),  # DEEPSEEK_API_KEY是环境变量的名字，值就是deepseek的API_KEY的//避免api的泄露
#     base_url="https://api.deepseek.com")#从哪来
#
# # 与AI大模型进行交互（）
# response = client.chat.completions.create(
#     model="deepseek-v4-pro",
#     messages=[
#         {"role": "system", "content": "You are a helpful assistant"},#系统提示词
#         {"role": "user", "content": "do you think I'm handsome"},#用户提示词
#     ],
#     stream=False,
#     reasoning_effort="high",
#     extra_body={"thinking": {"type": "enabled"}}
# )
#
# # 输出大模型返回的结果
# print(response.choices[0].message.content)#respose就是返回的全部结果对象

#提示词工程
# 引导AI思考，约束其输出范围，并明确期望结果
# 提示词（prompt）：是引导LLM进行内容生成的命令
# 提示词工程：通过有技巧的编写提示词，使大模型尽可能生成符合预期的内容，这一持续性的过程就是提示词工程
# 1.给AI定人设
# 2.明确请求与任务
# 3.拆解复杂任务
# 4.指定风格语气
# 5.明确输出格式
# 6.示例




























