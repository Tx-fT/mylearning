# AI 私厨管家 —— 后端 Docker 镜像
# 构建上下文 = 本目录（ai-sichu-guanjia/）
FROM python:3.13-slim

WORKDIR /app

# 先复制依赖清单并安装（利用 Docker 层缓存，代码变了不用重装依赖）
COPY requirements.txt .
RUN pip install --no-cache-dir -i https://pypi.tuna.tsinghua.edu.cn/simple -r requirements.txt

# 复制应用代码（server.py 通过 parents[1] 定位到 /app，正好对应 ai-sichu-guanjia/）
COPY app ./app
COPY src ./src

EXPOSE 8001

# 环境变量由部署平台注入（DASHSCOPE_API_KEY 等），不放进镜像
CMD ["uvicorn", "app.server:app", "--host", "0.0.0.0", "--port", "8001"]
