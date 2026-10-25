# -*- coding: utf-8 -*-
"""
Titanic 生存预测 —— 第一个 baseline
跟着注释走，理解每一步在干嘛。

完整流程：读数据 → 探索 → 预处理 → 训练 → 验证 → 预测 → 生成提交文件
"""
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression

# ============ 第 1 步：读数据 ============
train = pd.read_csv("train.csv")   # 训练集（有"是否生还"的答案）
test = pd.read_csv("test.csv")     # 测试集（要预测的，没有答案）

print("训练集大小:", train.shape)
print("测试集大小:", test.shape)

# ============ 第 2 步：看一眼数据 ============
print("\n前 3 行（重点看列名）：")
print(train.head(3))

print("\n各列缺失值数量：")
print(train.isnull().sum())

# ============ 第 3 步：预处理 ============
# 选 6 个最直观的特征
features = ['Pclass', 'Sex', 'Age', 'SibSp', 'Parch', 'Fare']

# Sex 是字符串（male/female），要转成数字：男=0，女=1
train['Sex'] = train['Sex'].map({'male': 0, 'female': 1})
test['Sex'] = test['Sex'].map({'male': 0, 'female': 1})

# 缺失值用「中位数」填（Age 和 Fare 都有缺失）
for col in ['Age', 'Fare']:
    train[col] = train[col].fillna(train[col].median())
    test[col] = test[col].fillna(test[col].median())

X = train[features]        # 特征（输入）
y = train['Survived']      # 标签（答案：0=遇难，1=生还）

# ============ 第 4 步：划分训练集 / 验证集 ============
# 留 20% 的数据当"模拟考试"，用来检验模型准不准
X_train, X_val, y_train, y_val = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# ============ 第 5 步：训练逻辑回归 ============
model = LogisticRegression(max_iter=1000)
model.fit(X_train, y_train)

# ============ 第 6 步：验证准确率 ============
acc = model.score(X_val, y_val)
print(f"\n逻辑回归验证准确率：{acc:.4f}（{acc*100:.2f}%）")

# ============ 第 7 步：预测测试集 + 生成提交文件 ============
X_test = test[features]
pred = model.predict(X_test)

submission = pd.DataFrame({
    'PassengerId': test['PassengerId'],
    'Survived': pred,
})
submission.to_csv('submission.csv', index=False)
print("提交文件已生成：submission.csv（拿去 Kaggle 上传就能得分）")
