"""
Kaggle - House Prices: 用你学过的内容完成预测
============================================================

这条流水线把你 machine learning/route 里的知识串起来:

  Day 2-4   线性回归 f=wx+b / 代价函数 J / 梯度下降   -> 第 0 节 (热身)
  Day 5-7   多元回归 / 特征缩放 / 特征工程             -> 第 2-4 节
  Day 12-14 过拟合 / 正则化 (Ridge, Lasso)             -> 第 6 节
  Day 24    训练/验证/测试集, bias-variance, 交叉验证  -> 第 6 节

运行:
    uv run python solve.py

输出:
    submission.csv  (直接上传 Kaggle 的提交文件)
"""

import sys
import warnings
from pathlib import Path

import numpy as np
import pandas as pd
from sklearn.dummy import DummyRegressor
from sklearn.exceptions import ConvergenceWarning
from sklearn.linear_model import Lasso, LinearRegression, Ridge
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.model_selection import GridSearchCV, KFold, cross_val_predict
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler

# Windows 终端默认用 GBK 输出, 这里改成 UTF-8, 避免中文变成乱码
if hasattr(sys.stdout, "reconfigure"):
    sys.stdout.reconfigure(encoding="utf-8")

# Lasso 的坐标下降偶尔差一点点到不了默认精度, 不影响结果, 隐藏这类警告
warnings.filterwarnings("ignore", category=ConvergenceWarning)

DATA_DIR = Path(__file__).resolve().parent
RANDOM_SEED = 42

pd.set_option("display.width", 120)


# ============================================================
# 第 0 节  热身: 用 Day 2-4 的梯度下降, 单特征预测房价
# ============================================================
# 你的笔记:
#   模型    f_w,b(x) = w*x + b
#   代价    J(w,b) = 1/(2m) * Σ(f(x[i]) - y[i])²
#   梯度    ∂J/∂w = 1/m * Σ(f(x[i]) - y[i]) * x[i]
#           ∂J/∂b = 1/m * Σ(f(x[i]) - y[i])
#   更新    w = w - α*∂J/∂w,  b = b - α*∂J/∂b  (同时更新)
#
# 这里用 GrLivArea (地上居住面积) 一个特征, 预测 log(SalePrice)。
# 注意: 训练前先把 x 标准化 (Day 5 的 z-score), 否则梯度下降很难收敛。
# ------------------------------------------------------------
def scratch_gradient_descent_demo(train):
    print("=" * 64)
    print("第 0 节  热身: 单特征线性回归 + 梯度下降 (从零实现)")
    print("=" * 64)

    x = train["GrLivArea"].to_numpy(dtype=float)
    y = np.log1p(train["SalePrice"].to_numpy(dtype=float))

    # 特征缩放: z-score 标准化  x_std = (x - mean) / std
    x = (x - x.mean()) / x.std()

    def predict(w, b):
        return w * x + b

    def compute_cost(w, b):
        return np.sum((predict(w, b) - y) ** 2) / (2 * len(x))

    w, b = 0.0, 0.0
    alpha = 0.01
    iterations = 3000

    print(f"样本数 m = {len(x)}, 学习率 alpha = {alpha}, 迭代 {iterations} 次")
    print(f"初始代价 J = {compute_cost(w, b):.4f}")

    for i in range(iterations):
        error = predict(w, b) - y            # f(x[i]) - y[i]
        dJ_dw = np.mean(error * x)           # 对 w 的偏导, 别忘了乘 x[i]
        dJ_db = np.mean(error)               # 对 b 的偏导
        w = w - alpha * dJ_dw                # 同时更新
        b = b - alpha * dJ_db

        if i % 600 == 0:
            print(f"  iter {i:5d} | J = {compute_cost(w, b):.4f} | w = {w:.4f} | b = {b:.4f}")

    pred = predict(w, b)
    r2 = 1 - np.sum((y - pred) ** 2) / np.sum((y - y.mean()) ** 2)
    print(f"收敛后: w = {w:.4f}, b = {b:.4f}, 训练集 R^2 = {r2:.4f}")
    print("结论: 单特征只能解释一部分房价, 所以下一步要上多元回归。\n")


# ============================================================
# 第 1 节  读数据
# ============================================================
def load_data():
    train = pd.read_csv(DATA_DIR / "train.csv")
    test = pd.read_csv(DATA_DIR / "test.csv")
    print("=" * 64)
    print("第 1 节  读数据")
    print("=" * 64)
    print(f"训练集: {train.shape[0]} 行 x {train.shape[1]} 列")
    print(f"测试集: {test.shape[0]} 行 x {test.shape[1]} 列")
    print(f"目标 SalePrice 偏度 = {train['SalePrice'].skew():.3f} "
          f"(>1 说明右偏严重, 取 log 后更接近正态)")

    # 异常样本: 面积超过 4000 平方英尺, 售价却不到 30 万美元。
    # 这不符合"面积越大越贵"的规律, 通常解释为非正常交易。
    # 线性模型遇到这种点会严重外推 (CV 里会预测出 $300 万),
    # 所以先把它们从训练集中去掉。测试集保持不变。
    outlier_mask = (train["GrLivArea"] > 4000) & (train["SalePrice"] < 300000)
    print(f"\n发现 {outlier_mask.sum()} 个面积/价格矛盾的异常样本, 已从训练集移除:")
    print(train.loc[outlier_mask, ["Id", "GrLivArea", "SalePrice"]].to_string(index=False))
    train = train[~outlier_mask].reset_index(drop=True)
    print(f"清洗后训练集: {train.shape[0]} 行\n")
    return train, test


# ============================================================
# 第 2 节  缺失值处理
# ============================================================
# 关键点: 很多缺失不是"没填", 而是"没有这个设施"。
# 例如 PoolQC 缺失 = 没有游泳池, 应该填 "None" 而不是中位数。
# 这一点必须看 data_description.txt, 不能无脑 fillna(0)。
# ------------------------------------------------------------
NONE_MEANS_NO_FEATURE = [
    "PoolQC", "MiscFeature", "Alley", "Fence", "MasVnrType", "FireplaceQu",
    "GarageType", "GarageFinish", "GarageQual", "GarageCond",
    "BsmtQual", "BsmtCond", "BsmtExposure", "BsmtFinType1", "BsmtFinType2",
]


def fill_missing(all_df):
    for col in NONE_MEANS_NO_FEATURE:
        all_df[col] = all_df[col].fillna("None")

    # LotFrontage 缺失 259 个: 同一街区的房子临街宽度相近,
    # 用"该街区的中位数"填补比全局中位数更合理。
    all_df["LotFrontage"] = all_df.groupby("Neighborhood")["LotFrontage"].transform(
        lambda s: s.fillna(s.median())
    )
    all_df["LotFrontage"] = all_df["LotFrontage"].fillna(all_df["LotFrontage"].median())

    # 没有车库 -> GarageYrBlt 无意义, 用建房年份代替
    all_df["GarageYrBlt"] = all_df["GarageYrBlt"].fillna(all_df["YearBuilt"])
    all_df["MasVnrArea"] = all_df["MasVnrArea"].fillna(0)

    # 兜底: 数值列用中位数, 类别列用众数
    for col in all_df.columns:
        if all_df[col].isna().any():
            if pd.api.types.is_numeric_dtype(all_df[col]):
                all_df[col] = all_df[col].fillna(all_df[col].median())
            else:
                all_df[col] = all_df[col].fillna(all_df[col].mode()[0])


# ============================================================
# 第 3 节  特征工程 (Day 7)
# ============================================================
# "创建新特征, 让预测更准" —— 例如面积 = 长 x 宽。
# 线性模型本身学不到 x1*x2 这种交互, 需要人工造出来。
# ------------------------------------------------------------
def add_features(df):
    df = df.copy()

    # 总面积: 地下室 + 一楼 + 二楼
    df["TotalSF"] = df["TotalBsmtSF"] + df["1stFlrSF"] + df["2ndFlrSF"]
    # 总浴室数 (半个浴室算 0.5)
    df["TotalBath"] = (df["FullBath"] + 0.5 * df["HalfBath"]
                       + df["BsmtFullBath"] + 0.5 * df["BsmtHalfBath"])
    # 门廊总面积
    df["TotalPorchSF"] = (df["OpenPorchSF"] + df["EnclosedPorch"] + df["3SsnPorch"]
                          + df["ScreenPorch"] + df["WoodDeckSF"])
    # 房龄 / 翻新距今年数 (房屋价值与年龄相关)
    df["HouseAge"] = df["YrSold"] - df["YearBuilt"]
    df["RemodAge"] = df["YrSold"] - df["YearRemodAdd"]
    # 是否有某设施 (把 "有没有" 和 "有多少" 分开)
    df["HasPool"] = (df["PoolArea"] > 0).astype(int)
    df["HasGarage"] = (df["GarageArea"] > 0).astype(int)
    df["HasBasement"] = (df["TotalBsmtSF"] > 0).astype(int)
    df["Has2ndFloor"] = (df["2ndFlrSF"] > 0).astype(int)
    df["HasFireplace"] = (df["Fireplaces"] > 0).astype(int)
    # 交互特征: 质量 x 面积 (好质量的大房子往往更贵, 不是简单相加)
    df["QualTimesArea"] = df["OverallQual"] * df["GrLivArea"]
    return df


# ============================================================
# 第 4 节  编码: 有序变量 vs 无序变量
# ============================================================
# 1) 有序类别 (Ex > Gd > TA > Fa > Po): 用数字保留顺序信息
#    这比 one-hot 更省列, 也更符合"质量越高越贵"的直觉。
# 2) 无序类别 (Neighborhood 街区等): 用 one-hot, 因为街区之间没有大小之分。
# ------------------------------------------------------------
QUALITY_MAP = {"Ex": 5, "Gd": 4, "TA": 3, "Fa": 2, "Po": 1, "None": 0}
ORDINAL_MAPS = {
    "ExterQual": QUALITY_MAP, "ExterCond": QUALITY_MAP,
    "BsmtQual": QUALITY_MAP, "BsmtCond": QUALITY_MAP,
    "HeatingQC": QUALITY_MAP, "KitchenQual": QUALITY_MAP,
    "FireplaceQu": QUALITY_MAP, "GarageQual": QUALITY_MAP,
    "GarageCond": QUALITY_MAP,
    "BsmtExposure": {"Gd": 4, "Av": 3, "Mn": 2, "No": 1, "None": 0},
    "BsmtFinType1": {"GLQ": 6, "ALQ": 5, "BLQ": 4, "Rec": 3, "LwQ": 2, "Unf": 1, "None": 0},
    "BsmtFinType2": {"GLQ": 6, "ALQ": 5, "BLQ": 4, "Rec": 3, "LwQ": 2, "Unf": 1, "None": 0},
    "GarageFinish": {"Fin": 3, "RFn": 2, "Unf": 1, "None": 0},
    "Functional": {"Typ": 7, "Min1": 6, "Min2": 5, "Mod": 4,
                   "Maj1": 3, "Maj2": 2, "Sev": 1, "Sal": 0},
    "Street": {"Pave": 2, "Grvl": 1},
    "PavedDrive": {"Y": 2, "P": 1, "N": 0},
    "LotShape": {"Reg": 3, "IR1": 2, "IR2": 1, "IR3": 0},
    "LandSlope": {"Gtl": 2, "Mod": 1, "Sev": 0},
    "CentralAir": {"Y": 1, "N": 0},
}


def encode_features(all_df):
    for col, mapping in ORDINAL_MAPS.items():
        all_df[col] = all_df[col].map(mapping).astype(int)

    # 剩下的文本列就是无序类别 -> one-hot
    nominal_cols = [c for c in all_df.columns
                    if pd.api.types.is_string_dtype(all_df[c])]
    all_df = pd.get_dummies(all_df, columns=nominal_cols, dtype=int)
    return all_df


# ============================================================
# 第 5 节  准备训练数据
# ============================================================
def build_training_data(train, test):
    n_train = len(train)

    # 训练集特征 + 测试集特征拼在一起处理 (统一缺失值/编码/列对齐)。
    # 这里用不到 SalePrice, 所以不算"偷看答案"。
    all_df = pd.concat(
        [train.drop(columns=["SalePrice"]), test], ignore_index=True
    )
    all_df = all_df.drop(columns=["Id", "Utilities"])  # Id 无意义, Utilities 几乎全相同

    fill_missing(all_df)
    all_df = add_features(all_df)
    all_df = encode_features(all_df)

    X = all_df.iloc[:n_train].reset_index(drop=True)
    X_test = all_df.iloc[n_train:].reset_index(drop=True)

    # 去掉常量列 (只有一种取值, 不含任何信息)
    constant_cols = [c for c in X.columns if X[c].nunique() <= 1]
    X = X.drop(columns=constant_cols)
    X_test = X_test.drop(columns=constant_cols)

    y = np.log1p(train["SalePrice"].to_numpy(dtype=float))  # 目标取 log, 缓解右偏

    print("=" * 64)
    print("第 5 节  特征处理完成")
    print("=" * 64)
    print(f"处理后特征数: {X.shape[1]} (原始 79 个列 + 新造特征 + one-hot)")
    print(f"去掉常量列 {len(constant_cols)} 个")
    print(f"训练特征 X: {X.shape}, 测试特征 X_test: {X_test.shape}\n")
    return X, y, X_test


# ============================================================
# 第 6 节  交叉验证 + 模型对比 (Day 12-14, Day 24)
# ============================================================
# Day 24: 把训练集分成 5 折, 轮流拿 1 折当验证集, 其余 4 折训练。
#         这样每个模型都在"没见过的数据"上评估, 比只看训练误差可靠。
#
# Day 12: 特征很多 (几百维) 而样本只有 1460 个, 普通线性回归容易过拟合:
#         训练误差很低, 验证误差却很高 -> 高方差 (variance)。
# Day 13-14: 正则化在代价函数里加 λ*Σw² 惩罚项:
#         - Ridge (L2): 把所有 w 压小, 通常效果最好
#         - Lasso (L1): 能把不重要的 w 压成 0, 相当于自动选特征
#
# 重要: 特征缩放必须放进 Pipeline, 让它在每一折内部只对训练部分 fit。
#       否则验证集的信息会"泄漏"到标准化参数里 (data leakage)。
# ------------------------------------------------------------
def compare_models(X, y):
    print("=" * 64)
    print("第 6 节  5 折交叉验证 + 模型对比")
    print("=" * 64)

    cv = KFold(n_splits=5, shuffle=True, random_state=RANDOM_SEED)

    candidates = {
        "均值基线 (什么都不学)": (DummyRegressor(strategy="mean"), {}),
        "普通线性回归 (无正则化)": (LinearRegression(), {}),
        "Ridge 岭回归 (L2 正则化)": (
            Ridge(),
            {"model__alpha": np.logspace(-3, 3, 25)},
        ),
        "Lasso 套索回归 (L1 正则化)": (
            Lasso(max_iter=50000),
            {"model__alpha": np.logspace(-5, -1, 17)},
        ),
    }

    results = {}
    for name, (estimator, param_grid) in candidates.items():
        pipe = Pipeline([
            ("scaler", StandardScaler()),  # Day 5: z-score 特征缩放
            ("model", estimator),
        ])
        search = GridSearchCV(
            pipe, param_grid, cv=cv,
            scoring="neg_root_mean_squared_error",
            return_train_score=True, n_jobs=-1,
        )
        search.fit(X, y)

        train_rmse = -search.cv_results_["mean_train_score"][search.best_index_]
        val_rmse = -search.best_score_          # 对数尺度上的 RMSE = RMSLE
        results[name] = (search, train_rmse, val_rmse)

        best_params = {k: round(float(v), 6) for k, v in search.best_params_.items()}
        print(f"\n[{name}]")
        if best_params:
            print(f"  最优超参数: {best_params}")
        print(f"  训练集 RMSLE: {train_rmse:.4f}")
        print(f"  验证集 RMSLE: {val_rmse:.4f}")
        if train_rmse > 0:
            print(f"  过拟合程度 (验证/训练 - 1): {(val_rmse / train_rmse - 1) * 100:+.1f}%")

    # 选出验证集误差最小的模型
    best_name = min(results, key=lambda k: results[k][2])
    best_search, best_train_rmse, best_val_rmse = results[best_name]

    print("\n" + "-" * 64)
    print(f"最优模型: {best_name}")
    print(f"  训练 RMSLE = {best_train_rmse:.4f}")
    print(f"  验证 RMSLE = {best_val_rmse:.4f}   <-- Kaggle 用的就是这类误差")

    # 用交叉验证的 out-of-fold 预测换算成"美元"尺度的 RMSE
    oof_log = cross_val_predict(best_search.best_estimator_, X, y, cv=cv, n_jobs=-1)
    oof_price = np.expm1(oof_log)
    real_price = np.expm1(y)
    dollar_rmse = np.sqrt(mean_squared_error(real_price, oof_price))
    r2 = r2_score(real_price, oof_price)
    print(f"  换算成美元: RMSE = ${dollar_rmse:,.0f}, R^2 = {r2:.4f}")
    print("  (R^2 越接近 1 越好, 表示模型解释了房价中多大比例的波动)")

    print("\n怎么读这张表:")
    print("  - 基线误差告诉你: 不学任何东西时有多差")
    print("  - 训练误差低、验证误差高 = 过拟合 (Day 12 的 variance)")
    print("  - 正则化后验证误差下降 = 惩罚项起了作用 (Day 14)\n")

    return best_name, best_search, cv


# ============================================================
# 第 7 节  模型解释: 哪些特征最重要?
# ============================================================
def show_top_features(model, feature_names, top_k=15):
    print("=" * 64)
    print("第 7 节  Ridge/Lasso 学到了什么? (标准化后的系数)")
    print("=" * 64)
    # 系数含义: 该特征增加 1 个标准差, 预测的 log 房价变化多少。
    # 因为 y 取过 log, 系数 0.1 大约对应房价 +10%。
    coefs = model.named_steps["model"].coef_
    order = np.argsort(np.abs(coefs))[::-1][:top_k]

    print(f"{'特征':<28}{'系数':>10}   方向")
    for idx in order:
        direction = "房价上涨" if coefs[idx] > 0 else "房价下跌"
        print(f"{feature_names[idx]:<28}{coefs[idx]:>10.4f}   {direction}")
    print()


# ============================================================
# 第 8 节  预测测试集, 生成提交文件
# ============================================================
def make_submission(model, X_test, test, train):
    print("=" * 64)
    print("第 8 节  预测测试集并生成 submission.csv")
    print("=" * 64)

    pred_log = model.predict(X_test)
    pred_price = np.expm1(pred_log)             # log 预测值还原成房价
    pred_price = np.maximum(pred_price, 0)      # 房价不能为负

    submission = pd.DataFrame({"Id": test["Id"], "SalePrice": pred_price})
    out_path = DATA_DIR / "submission.csv"
    submission.to_csv(out_path, index=False)

    print(f"已保存: {out_path}")
    print(f"预测房价范围: ${pred_price.min():,.0f} ~ ${pred_price.max():,.0f}")
    print(f"预测均值: ${pred_price.mean():,.0f}  "
          f"(训练集真实均值: ${train['SalePrice'].mean():,.0f})")
    print("\n前 5 行:")
    print(submission.head().to_string(index=False))
    print()


# ============================================================
# 主流程
# ============================================================
def main():
    train, test = load_data()

    scratch_gradient_descent_demo(train)              # Day 2-4 的复习
    X, y, X_test = build_training_data(train, test)   # Day 5-7

    best_name, best_search, _ = compare_models(X, y)  # Day 12-14, 24
    best_model = best_search.best_estimator_

    show_top_features(best_model, X.columns)          # 解释模型

    make_submission(best_model, X_test, test, train)  # 生成 Kaggle 提交文件


if __name__ == "__main__":
    main()
