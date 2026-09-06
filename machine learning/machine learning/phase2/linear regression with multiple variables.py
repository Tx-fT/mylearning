#day5
#multiple regression
#gradient descent
#feature scaling:
# min-max归一化：将数据缩放到（0，1】之间，公式：X_norm = (X - X_min) / (X_max - X_min)
# z-score标准化：将数据缩放到均值为0，方差为1，公式：X_std = (X - X_mean) / X_std
# feature scaling is important for multiple regression
#learning curve：横坐标迭代次数，纵坐标损失函数值，用于判断模型是否过拟合或欠拟合
#automatic convergence test（自动收敛检测）：设定一个阈值，当损失函数值的变化小于该阈值时，认为模型已经收敛

#day6
#choose the learning rate:
#with a small enough alpha j decrease on every iteration but j increas mean bug
#smaller more iterations needed:0.001 0.01 0.1 1->*3

#day7
# feature engineering:
# how choose or engineering the most appropriate features for learning algorithm
#creating a new feature to make accurate predictions,example:area=width*length
#combine feature engineering with multiple regression = polynomial regression(多项式回归)：can capture non-linear relationship
#by raising x to the power 2 or 3（x^2, x^3）
#feature scaling becomes increasingly important（指数增长）
#like：fw->,b=w1x+w2x^2+b





