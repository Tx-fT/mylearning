# AI 私厨管家 · 部署指南

> 目标：把本地能跑的后端（FastAPI + LangChain Agent）做成公网可访问的服务。

## 一、整体架构

```
浏览器 → 前端(Next.js) ──HTTP──▶ 后端(FastAPI :8001) ──▶ qwen-vl-max(多模态) + Tavily(搜索)
                                    └─ SQLite(checkpoint.db) 记忆
```

## 二、需要的环境变量（部署平台里配置，不要写进代码）

| 变量名 | 作用 | 从哪拿 |
|---|---|---|
| `DASHSCOPE_API_KEY` | 通义千问视觉模型 | 阿里云百炼（DashScope）控制台 |
| `DASHSCOPE_BASE_URL` | 百炼 OpenAI 兼容地址 | 通常 `https://dashscope.aliyuncs.com/compatible-mode/v1` |
| `TAVILY_API_KEY` | 联网搜索工具 | tavily.com 注册 |
| `TAVILY_BASE_URL` | 搜索接口地址（可选） | 默认即可 |

> 后端 `src/.env` 里还留了 `LANGSMITH_*`（追踪）和 `DEEPSEEK_*`（早期用），上线 MVP 阶段先不用管。

## 三、本地用 Docker 验证（上线前先确认镜像能跑）

```bash
cd ai-sichu-guanjia

# 构建镜像
docker build -t sichu-backend .

# 运行（把密钥作为环境变量传入，不依赖 .env 文件）
docker run -d --name sichu -p 8001:8001 \
  -e DASHSCOPE_API_KEY=你的key \
  -e DASHSCOPE_BASE_URL=https://dashscope.aliyuncs.com/compatible-mode/v1 \
  -e TAVILY_API_KEY=你的key \
  sichu-backend

# 验证
curl http://localhost:8001/          # 应返回 {"service":"AI 私厨管家","status":"running"}
```

## 四、部署到 Render（推荐起步，有免费额度）

1. 把项目推到 GitHub（`ai-sichu-guanjia` 目前是 `mylearning` 仓库的子目录，建议**单独开一个仓库**放这个项目，方便 Render 直接读根目录的 Dockerfile）。
2. Render 新建 **Web Service** → 选 "Deploy from Git repo" → 指定 Docker。
3. Root Directory 填 `langchain+langgraph/ai-sichu-guanjia`（若用整个 mylearning 仓库）或项目根目录（若单独开仓库）。
4. 在 Environment 里填上第二节的 4 个环境变量。
5. 部署完成后拿到后端公网 URL，形如 `https://xxx.onrender.com`。

## 五、前端部署（可选，第二步再做）

- 前端在 `私厨-前端源码/`，`lib/api.ts` 已改为读 `NEXT_PUBLIC_API_BASE` 环境变量。
- 部署到 Vercel 时，设 `NEXT_PUBLIC_API_BASE=https://后端公网地址`，前端就会去连云端后端。
- 本地调试前端仍默认连 `localhost:8001`，行为不变。

## 六、上线后要检查的

- [ ] 后端 `/` 返回 running
- [ ] `POST /api/v1/chat/stream` 能流式返回食谱推荐
- [ ] 图片上传后能正确识别食材（多模态链路通）
- [ ] 前端页面能聊天、能传图（如果部署了前端）
