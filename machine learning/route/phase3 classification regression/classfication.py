#day8
#classification:
#logistic regression
#answer y is 0(negative class) or 1(positive class)(binary classification)
#want outputs between 0 and 1
#mathematical function:sigmoid function(logistic function)
#g(z)=1/(1+e^-z),z=wx+b; probability between 0 and 1(y只能是0 1)
#given input x->,parameters w->,b;

#day9
#decision boundary(how logistic regression is computing its predictions):
#1.f(x):z=w->x+b
#2.g(z):1/(1+e^-z)
#set threshold（阈值）：y hat(predict 0 or 1)
#y hat>0.5:predict 1,y hat<=0.5:predict 0
#代回f(x)找x阈值
#decision boundary: z=w->x->+b=0
#example:z=x1+x2-3: decision boundary: x1+x2-3=0
#non-linear decision boundary:
#polynomial features(多项式特征)
#        z=x1^2+x2^2-4: decision boundary: x1^2+x2^2-4=0

#day10
#cost function for logistic regression：
#training set:
# x_j=1......x_j=n,y
#i=1
#2
#...
#n
#i training example,j features
#target y is 0 or 1
#how to choose w-> and b;
#recap(回顾)：
#squared error cost function:
#J(w,b)=1/2m*(y^[i]-f_w,b(x^[i]))^2->gradient descent:convex(凹形)
#if apply it to logistic regression:non-convex(非凹形)
#loss function（很好的拟合y（真实值））:
#L(f_w->,b(x^i),y^i):-log(f_w,b(x^i)) if y^i=1;
#                    -log(1-f_w,b(x^i)) if y^i=0
#                    feature scaling 0-1（只看横坐标0-1）（近似差）
#J(w,b)=-1/m*sum(from i=1 to m)(y^[i]*log(f_w,b(x^[i]))+(1-y^[i])*log(1-f_w,b(x^[i])))
#find w,b that minimize J(w,b)

#day11
#simplified cost function
#L(fw->,bxi,yi)=-y^[i]*log(f_w,b(x^[i]))-(1-y^[i])*log(1-f_w,b(x^[i]))#等价
#J(w,b)=-1/m*sum(from i=1 to m)(y^[i]*log(f_w,b(x^[i]))+(1-y^[i])*log(1-f_w,b(x^[i])))
#gradient descent implementation:
#梯度下降推导见图

#day12
#the problem of overfitting(过拟合)
#将训练集分为验证集和测试集：在测试集训练效果显著高于验证集则说明过拟合
#how address overfitting：
#1.collect more training data
#2.select features to include/exclude
#     disad：useful features could be lost
#3.regularization(正则化)：
#if parameter is large:reduce the size of parameters(wj)
#eliminate large parameter values(wj):encourage learning algorithm to shrink parameter values(缩小参数值)
#保留尽可能多的特征，防止参数过大导致过拟合

#day13
#cost function with regularization：
#if you want to make w small: add a penalty to the cost function:
#   like:J(w,b)=-1/m*sum(from i=1 to m)(y^[i]*log(f_w,b(x^[i]))+(1-y^[i])*log(1-f_w,b(x^[i]))) + (lambda/2m)*sum(from j=1 to n)(wj^2)
#   消除wi所携带的数据xi的影响
#simple model less likely overfit
#if dont know which wj is important: penalize all：+ (lambda/2m)*sum(from j=1 to n)(wj^2)
#   lambda is a regularization parameter
#1.mean squared error:fit data 2.regularization:keep wj small (防止过拟合)
#lambda balance both goal:underfit(small)->overfit(large)

#day14
#regularized linear regression:
#repeat{
#wj:=wj-alpha/m*sum(from i=1 to m)((h_w(x^[i])-y^[i])*x^[i]_j)+lambda/m*wj
#b:=b-alpha/m*sum(from i=1 to m)((h_w(x^[i])-y^[i]))
#}
#regularized logistic regression:
#wj:=wj-alpha/m*sum(from i=1 to m)((h_w(x^[i])-y^[i])*x^[i]_j)+lambda/m*wj
#b:=b-alpha/m*sum(from i=1 to m)((h_w(x^[i])-y^[i]))
#虽然式子一样但推导过程不同：见图












