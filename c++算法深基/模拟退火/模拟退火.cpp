/**
 * 模拟退火算法（Simulated Annealing）教学模板
 *
 * 核心思想：
 *   模拟固体退火的物理过程——将固体加热至高温，再缓慢冷却。
 *   在优化问题中，"温度"控制接受劣解的概率：
 *     - 高温时：容易接受劣解，进行大范围搜索（全局探索）
 *     - 低温时：不易接受劣解，逐步收敛到局部最优（局部精化）
 *
 * 核心公式（Metropolis准则）：
 *   当新解比当前解更优时：一定接受
 *   当新解更差时：以概率 exp(-ΔE / T) 接受，其中 ΔE = 新解代价 - 当前解代价
 *      - T 越大，exp(-ΔE/T) 越接近 1，越容易接受劣解
 *      - T 越小，exp(-ΔE/T) 越接近 0，越难接受劣解
 *
 * 伪代码：
 *   T = T0                    // 初始温度（要足够高）
 *   x = 随机初始解
 *   while (T > T_min):        // 温度未降到终温
 *       for i in 1..L:        // 每个温度下迭代 L 次（马尔可夫链长度）
 *           x_new = 在 x 的邻域内随机扰动
 *           ΔE = f(x_new) - f(x)
 *           if ΔE < 0:        // 新解更优（假设求最小值）
 *               x = x_new
 *           else if exp(-ΔE/T) > random(0,1):
 *               x = x_new     // 以一定概率接受劣解
 *       T = T * delta         // 降温（delta 通常取 0.95~0.999）
 *   return x
 *
 * 三个关键参数：
 *   1. 初始温度 T0      — 要足够高，保证初期几乎可以接受任何解
 *   2. 降温系数 delta    — 控制降温速度，越接近 1 越慢（搜索越充分）
 *   3. 终止温度 T_min    — 温度降到多低时停止
 *
 * 适用场景：
 *   - NP-hard 问题求近似解（TSP、背包、图着色等）
 *   - 连续函数的全局最优化
 *   - 组合优化问题
 *
 * 优点：能以一定概率跳出局部最优，找到全局最优
 * 缺点：参数调优困难，结果不稳定（需多次运行取最优）
 */

#include <bits/stdc++.h>
using namespace std;

// ============================================================
// 示例：求一元函数 f(x) = (x-2)² + 3sin(5x) 在 [-10, 10] 上的最小值
// 这是一个有多个局部最小值的函数，适合演示模拟退火的全局搜索能力
// ============================================================

// ----------------------- 随机数工具 -----------------------
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// 生成 [l, r] 范围内的随机浮点数
double rand_double(double l, double r) {
    uniform_real_distribution<double> dist(l, r);
    return dist(rng);
}

// 生成 [0, 1) 的随机浮点数
double rand_01() {
    return rand_double(0.0, 1.0);
}

// ----------------------- 目标函数（求最小值） -----------------------
double f(double x) {
    return (x - 2) * (x - 2) + 3.0 * sin(5.0 * x);
}

// ----------------------- 模拟退火主函数 -----------------------
double simulated_annealing() {
    // ====== 超参数 ======
    double T0     = 1000.0;   // 初始温度 — 要足够高
    double T_min  = 1e-8;     // 终止温度 — 要足够低
    double delta  = 0.995;    // 降温系数 — 越接近 1 搜索越充分
    int    L      = 100;      // 每个温度下的迭代次数（马尔可夫链长度）

    double T = T0;

    // 随机初始解
    double x = rand_double(-10.0, 10.0);
    double fx = f(x);

    // 记录全局最优（因为 SA 可能会在接受劣解后丢掉最优）
    double best_x = x, best_fx = fx;

    // ====== 退火主循环 ======
    while (T > T_min) {
        for (int i = 0; i < L; i++) {
            // 1. 在邻域内生成新解（扰动方式取决于问题）
            //    连续变量：加一个与温度相关的高斯/均匀扰动
            double perturbation = (rand_01() * 2 - 1) * T;  // 扰动幅度随温度减小
            double x_new = x + perturbation;

            // 边界处理（夹紧到定义域）
            x_new = max(-10.0, min(10.0, x_new));

            double fx_new = f(x_new);
            double delta_E = fx_new - fx;  // 能量差（正 = 变差）

            // 2. Metropolis 准则
            if (delta_E < 0) {
                // 新解更优 → 一定接受
                x = x_new;
                fx = fx_new;
            } else {
                // 新解更差 → 以概率 exp(-ΔE/T) 接受
                double p = exp(-delta_E / T);
                if (rand_01() < p) {
                    x = x_new;
                    fx = fx_new;
                }
            }

            // 3. 更新全局最优
            if (fx < best_fx) {
                best_fx = fx;
                best_x = x;
            }
        }
        // 4. 降温
        T *= delta;
    }

    cout << "Best x  = " << best_x  << endl;
    cout << "Best fx = " << best_fx << endl;
    return best_x;
}

// ----------------------- 多次运行取最优 -----------------------
void multiple_runs(int times = 5) {
    cout << "===== 模拟退火：多次运行取最优 =====" << endl;
    double best_x = 0, best_fx = 1e18;
    for (int run = 1; run <= times; run++) {
        cout << "--- Run " << run << " ---" << endl;
        double x = simulated_annealing();
        double fx = f(x);
        if (fx < best_fx) {
            best_fx = fx;
            best_x = x;
        }
        cout << endl;
    }
    cout << "===== 最终结果 =====" << endl;
    cout << "Global Best x  = " << best_x  << endl;
    cout << "Global Best fx = " << best_fx << endl;
}

// ============================================================
// 进阶模板：泛型模拟退火框架
// 使用时只需定义 State（状态/解）和三个核心操作即可
// ============================================================

template<typename State>
struct SA {
    // 用户需定义的三个核心函数：
    //   energy(const State&)   — 计算代价（越小越好）
    //   neighbour(const State&, double T) — 在邻域生成新解（扰动幅度与T相关）
    //   clamp(State&)          — 将解约束到合法空间

    double T0, T_min, delta;
    int L;

    SA(double t0 = 1000, double t_min = 1e-8, double d = 0.995, int l = 100)
        : T0(t0), T_min(t_min), delta(d), L(l) {}

    template<typename EnergyFn, typename NeighbourFn, typename ClampFn>
    State run(State init, EnergyFn energy, NeighbourFn neighbour, ClampFn clamp) {
        double T = T0;
        State cur = init;
        State best = init;
        double cur_e = energy(cur);
        double best_e = cur_e;

        while (T > T_min) {
            for (int i = 0; i < L; i++) {
                State nxt = neighbour(cur, T);
                clamp(nxt);
                double nxt_e = energy(nxt);
                double dE = nxt_e - cur_e;

                if (dE < 0 || rand_01() < exp(-dE / T)) {
                    cur = nxt;
                    cur_e = nxt_e;
                }
                if (cur_e < best_e) {
                    best = cur;
                    best_e = cur_e;
                }
            }
            T *= delta;
        }
        return best;
    }
};

// ============================================================
// 演示：用泛型框架求解同一个问题
// ============================================================
void demo_generic_sa() {
    cout << "===== 泛型 SA 框架演示 =====" << endl;
    SA<double> sa(1000, 1e-8, 0.995, 100);

    auto energy = [](double x) -> double {
        return (x - 2) * (x - 2) + 3.0 * sin(5.0 * x);
    };
    auto neighbour = [](double x, double T) -> double {
        return x + (rand_01() * 2 - 1) * T;
    };
    auto clamp = [](double& x) {
        x = max(-10.0, min(10.0, x));
    };

    double init = rand_double(-10.0, 10.0);
    double result = sa.run(init, energy, neighbour, clamp);
    cout << "x = " << result << ", f(x) = " << energy(result) << endl;
}

// ============================================================
// 主函数
// ============================================================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(10);

    // 方式1：直接使用模拟退火
    simulated_annealing();

    cout << endl;

    // 方式2：多次运行取最优（更稳定）
    // multiple_runs(5);

    // 方式3：使用泛型框架
    // demo_generic_sa();

    return 0;
}
