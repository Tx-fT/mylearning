#day 1
#supervised learning:used most,rapid advancements
#unsupervised learning
#recommender systems
#reinforcement learning（强化学习）

#supervised learning
    #x->y or input to output mapping algorithm，being given “right answers”(y)->learning->be given x predict y
    #regression(回归)：predict a number from infinitely many possible outputs
    #classification(分类)：predict a category from finitely possible outputs（0 or 1，有限类阳性 or 阴性）
    #             2 or more inputs：更多维度来学习size，age：to find malignant（边界）以区分

#unsupervised learning
#data 没有标签，目的是找到：结构或其他一些特征
#不要求监督某特定数据，而是自行找出答案
#clustering(聚类)：find finitely many categories（族） from infinitely many unsigned data（未标签分类）
#           key words clustering in internet，DNA microarray：将个体分成不同类别的人，grouping customers（客户分组）
#association(关联)：find associations between inputs（输入之间的关联）

#day 2
#线性回归模型
#training set：data used to train the model
#（x,y）=single training example （x^[i],y^[i]）=ith training example
#process of supervised learning:
#training set(features,targets)->learning algorithm->f(function:x(feature)->f(model)->y^(估计预测)(y-hat)(predictio))
#f?: f_w,b(x)=wx+b(帮助过度到更复杂) linear regression with 1 variable(univariate regression)

#cost function：
#y^-y(error)(衡量预测值和目标值的偏差)->calculate the square of error->sum up->average(/2*num)->J(w,b)(cost function平方误差代价函数)
#J(w,b)=1/2m*sum(from i=1 to m)(y^[i]-f_w,b(x^[i]))^2  regression problems
#how find the best w,b:
#model:f_w,b(x)=wx+b
#parameters:w,b(变量)
#j cost function->minimize_w,b J(w,b)(测量预测值与目标值之间的差异)
#可以得到j(w,b)图像（把w，b试）:
#   1.设一个j
#   2.图像三维（j,w,b）(凹进去的就是min)
#gradient descent(梯度下降)

#day 3
#自动找到成本函数J：w,b:algorithm:gradient descent(梯度下降)(多维亦可)
#gradient descent:
#f:J(w,b)
#target:min_J(w,b)
#initial guess（start with some w,b/set 0）->
#keep changing w,b to reduce J(w,b)->
#until J(w,b)converges(收敛)(at or near a minimum)

#squared error cost f:bowl shape,liner regression,most other f:like hills and valleys

#process:spin around 360 degrees and look around,find the quick drop in J(w,b) than moving in that direction
#get lots of local minimum

#day 4
#w=w-alpha(learning rate derivative)*dJ/dw
#b=b-alpha(learning rate derivative)*dJ/db
#learning rate:control step when updating
#repeat until convergence
#update w,b simultaneously:
    # tmp_w=w-alpha*dJ_dw
    # tmp_b=b-alpha*dJ_db
    # w=tmp_w
    # b=tmp_b
#learning rate:
# control step when updating
#learning regression algorithm：
#linear regression model:y=wx+b
#cost function:1/2m*sum(from i=1 to m)(y^[i]-f_w,b(x^[i]))^2
#gradient descent algorithm:
#  repeat until convergence(收敛){
    # w=w-alpha(learning rate derivative)*dJ/dw
    # b=b-alpha(learning rate derivative)*dJ/db
    # dJ/dw=1/m*sum(from 1 to m)(f_w,b(x[i])-y[i])*x[i]
    # db同理少*x[i]
#  }
#convex function（凸函数）->bowl-shaped->single minimum
#"Batch" (批量)gradient descent:
#compute gradient using the whole training set(使用整个训练集)







