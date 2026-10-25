"""
Linear Regression 练习模板
===========================
基于学习内容涵盖：
  1. 模型：f_w,b(x) = wx + b
  2. 代价函数：J(w,b) = 1/(2m) * Σ(f_w,b(x[i]) - y[i])²
  3. 梯度下降：w = w - α * ∂J/∂w,  b = b - α * ∂J/∂b
  4. Batch Gradient Descent（使用整个训练集）

使用方法：修改下方 CONFIG 区参数，直接运行即可。
"""

import numpy as np
import matplotlib.pyplot as plt

# ============================================================
# CONFIG —— 修改这里的参数来实验
# ============================================================
LEARNING_RATE = 0.01        # 学习率 α（试试: 0.0001, 0.01, 0.1, 1.0）
ITERATIONS   = 10000         # 迭代次数
INIT_W       = 0.0          # w 初始值
INIT_B       = 0.0          # b 初始值
PRINT_EVERY  = 100         # 每 N 次迭代打印一次 cost
RANDOM_SEED  = 42           # 随机种子（保证结果可复现）
N_SAMPLES    = 100          # 训练样本数量
NOISE_STD    = 1.0          # 数据噪声标准差（试试 0, 2, 10）


# ============================================================
# 1. 生成 / 加载训练数据
# ============================================================
def generate_data(n_samples=N_SAMPLES, noise_std=NOISE_STD, seed=RANDOM_SEED):
    """
    生成模拟数据：y = wx + b + noise
    你之后可以把这里替换成真实数据集的加载逻辑（如 pd.read_csv）
    """
    np.random.seed(seed)
    x = np.random.uniform(-10, 10, n_samples)          # feature（特征）
    true_w, true_b = 2.5, 0.0                           # 真实参数（我们试图逼近它）
    noise = np.random.normal(0, noise_std, n_samples)   # 正态分布噪声
    y = true_w * x + true_b + noise                     # target（目标值）
    return x, y, true_w, true_b


# ============================================================
# 2. 模型（Model）
# ============================================================
def predict(x, w, b):
    """
    线性回归模型: f_w,b(x) = w*x + b
    x: 特征（标量 or 数组）
    w, b: 模型参数
    """
    return w * x + b


# ============================================================
# 3. 代价函数（Cost Function）
# ============================================================
def compute_cost(x, y, w, b):
    """
    J(w,b) = 1/(2m) * Σ(f_w,b(x[i]) - y[i])²
    均方误差代价函数（平方误差代价函数）
    """
    m = len(x)
    predictions = predict(x, w, b)
    cost = (1 / (2 * m)) * np.sum((predictions - y) ** 2)
    return cost


# ============================================================
# 4. 梯度计算（Compute Gradient）
# ============================================================
def compute_gradient(x, y, w, b):
    """
    计算偏导数：
      ∂J/∂w = (1/m) * Σ(f_w,b(x[i]) - y[i]) * x[i]
      ∂J/∂b = (1/m) * Σ(f_w,b(x[i]) - y[i])
    """
    m = len(x)
    predictions = predict(x, w, b)
    error = predictions - y                      # f(x[i]) - y[i]

    dJ_dw = (1 / m) * np.sum(error * x)          # 别忘了乘以 x[i]
    dJ_db = (1 / m) * np.sum(error)              # b 的偏导没有 x[i]

    return dJ_dw, dJ_db


# ============================================================
# 5. 梯度下降（Gradient Descent）—— Batch
# ============================================================
def gradient_descent(x, y, w_init, b_init, alpha, iterations, print_every=PRINT_EVERY):
    """
    Batch Gradient Descent —— 每次用整个训练集计算梯度

    算法：
      repeat until convergence {
          w = w - α * ∂J/∂w
          b = b - α * ∂J/∂b
      }
    """
    w, b = w_init, b_init
    cost_history = []        # 记录每次迭代的 cost，用于画收敛曲线

    for i in range(iterations):
        # 计算梯度
        dJ_dw, dJ_db = compute_gradient(x, y, w, b)

        # 同时更新 w 和 b（注意要同时！）
        w = w - alpha * dJ_dw
        b = b - alpha * dJ_db

        # 记录 cost
        cost = compute_cost(x, y, w, b)
        cost_history.append(cost)

        # 定期打印
        if i % print_every == 0:
            print(f"  Iteration {i:6d} | cost = {cost:.6f} | w = {w:.4f} | b = {b:.4f}")

    return w, b, cost_history


# ============================================================
# 6. 评估（Evaluation）
# ============================================================
def evaluate(x, y, w, b):
    """计算 MSE, MAE, R² 等指标"""
    m = len(x)
    predictions = predict(x, w, b)

    mse = (1 / m) * np.sum((predictions - y) ** 2)       # Mean Squared Error
    mae = (1 / m) * np.sum(np.abs(predictions - y))      # Mean Absolute Error
    ss_res = np.sum((y - predictions) ** 2)               # 残差平方和
    ss_tot = np.sum((y - np.mean(y)) ** 2)                # 总平方和
    r2 = 1 - ss_res / ss_tot                              # R² Score

    return {"MSE": mse, "MAE": mae, "R2": r2}


# ============================================================
# 7. 可视化
# ============================================================
def plot_results(x, y, w, b, cost_history, true_w=None, true_b=None):
    """画图：散点 + 拟合直线 + 代价函数收敛曲线"""
    fig, axes = plt.subplots(1, 2, figsize=(14, 5))

    # --- 左图：数据 + 拟合直线 ---
    ax = axes[0]
    ax.scatter(x, y, alpha=0.5, label="Training Data", s=30)

    # 画出学到的直线
    x_line = np.linspace(x.min(), x.max(), 100)
    y_line = predict(x_line, w, b)
    ax.plot(x_line, y_line, color="red", linewidth=2,
            label=f"Fitted: y = {w:.3f}x + {b:.3f}")

    # 画出真实直线（如果有的话）
    if true_w is not None:
        y_true_line = predict(x_line, true_w, true_b)
        ax.plot(x_line, y_true_line, color="green", linestyle="--",
                linewidth=1.5, label=f"True: y = {true_w:.1f}x + {true_b:.1f}")

    ax.set_xlabel("x (Feature)")
    ax.set_ylabel("y (Target)")
    ax.set_title("Linear Regression Fit")
    ax.legend()
    ax.grid(True, alpha=0.3)

    # --- 右图：Cost 下降曲线 ---
    ax = axes[1]
    ax.plot(cost_history, color="blue", linewidth=1)
    ax.set_xlabel("Iteration")
    ax.set_ylabel("Cost J(w, b)")
    ax.set_title(f"Cost Convergence (final cost = {cost_history[-1]:.4f})")
    ax.grid(True, alpha=0.3)

    plt.tight_layout()
    plt.show()


# ============================================================
# 8. 动手实验区 —— 自己写练习代码
# ============================================================
def experiment():
    """
    在这里自由实验！
    建议尝试：
      - 改 LEARNING_RATE（看收敛速度 & 是否发散）
      - 改 ITERATIONS（看是否收敛到位）
      - 改 INIT_W / INIT_B（不同起点是否影响结果？—— 凸函数不会）
      - 改 NOISE_STD（噪声越大拟合越难）
      - 对比不同 learning rate 的收敛曲线画在一起
    """
    # TODO: 你的实验代码

    pass


# ============================================================
# MAIN
# ============================================================
if __name__ == "__main__":
    print("=" * 60)
    print("Linear Regression — From Scratch")
    print("=" * 60)

    # Step 1: 生成数据
    print("\n[1] Generating data...")
    x, y, true_w, true_b = generate_data()
    print(f"    Samples: {len(x)}, True w = {true_w}, True b = {true_b}")

    # Step 2: 初始 cost
    print(f"\n[2] Initial cost (w={INIT_W}, b={INIT_B}):")
    print(f"    J(w,b) = {compute_cost(x, y, INIT_W, INIT_B):.4f}")

    # Step 3: 梯度下降
    print(f"\n[3] Running Gradient Descent "
          f"(α={LEARNING_RATE}, iters={ITERATIONS})...")
    w_final, b_final, cost_history = gradient_descent(
        x, y, INIT_W, INIT_B, LEARNING_RATE, ITERATIONS
    )

    # Step 4: 结果
    print(f"\n[4] Final parameters:")
    print(f"    Learned: w = {w_final:.4f}, b = {b_final:.4f}")
    print(f"    True:    w = {true_w:.4f}, b = {true_b:.4f}")
    print(f"    Error:   Δw = {abs(w_final - true_w):.4f}, "
          f"Δb = {abs(b_final - true_b):.4f}")

    # Step 5: 评估
    print(f"\n[5] Evaluation:")
    metrics = evaluate(x, y, w_final, b_final)
    for k, v in metrics.items():
        print(f"    {k}: {v:.4f}")

    # Step 6: 可视化
    print(f"\n[6] Plotting...")
    plot_results(x, y, w_final, b_final, cost_history, true_w, true_b)

    # Step 7: 动手实验
    print(f"\n[7] Running your experiment()...")
    experiment()
