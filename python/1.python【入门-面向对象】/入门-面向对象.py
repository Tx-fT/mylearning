# import random
#
# class card:
#     def __init__(self,suite,face):
#         self.suite=suite
#         self.face=face
#     def __repr__(self):
#         suites='♠♥♣♦'
#         faces=['','A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
#         return f'{suites[self.suite]}{faces[self.face]}'
#     def __lt__(self,other):
#         if self.face==other.face:
#             return self.suite<other.suite
#         else:
#             return self.face<other.face
#
# class poker:
#     def __init__(self):
#         self.cards=[card(suite,face)#创建对象
#                     for suite in range(4)
#                     for face in range(1,14)]
#         self.current=0
#     def shuffle(self):
#         self.current=0
#         random.shuffle(self.cards)
#     def deal(self):
#         card= self.cards[self.current]
#         self.current+=1
#         return card
#     @property
#     def ok(self):
#         return self.current<=52
# class player:
#     def __init__(self,name):
#         self.name=name
#         self.hands=[]
#     def get(self,card):
#         self.hands.append(card)
#     def arrange(self):
#         self.hands.sort()
# poker=poker()
# poker.shuffle()
# t=input().split()
# players=[player(name) for name in t]
# for _ in range(13):
#     for p in players:
#         p.get(poker.deal())
# for p in players:
#     p.arrange()
#     print(f'{p.name}:',end=' ')
#     print(p.hands)

# ... existing code ...

#类型函数
#type(变量)：返回变量的数据类型，如 type(123) -> <class 'int'>
#isinstance(变量, 类型)：判断变量是否为指定类型，如 isinstance("hello", str) -> True
#str()：转换为字符串，如 str(123) -> "123"
#int()：转换为整数，如 int("123") -> 123
#float()：转换为浮点数，如 float("3.14") -> 3.14
#bool()：转换为布尔值，如 bool(0) -> False, bool(1) -> True
#list()：转换为列表，如 list((1,2,3)) -> [1, 2, 3]
#tuple()：转换为元组，如 tuple([1,2,3]) -> (1, 2, 3)
#dict()：创建字典，如 dict(a=1, b=2) -> {'a': 1, 'b': 2}
#set()：转换为集合，如 set([1,2,2,3]) -> {1, 2, 3}

#字符串(str)常用方法
#长度：len(s)
#大小写：upper()(转大写)，lower()(转小写)，capitalize()(首字母大写)，title()(每个单词首字母大写)
#查找：find(子串)(返回索引，未找到返回-1)，index(子串)(返回索引，未找到报错)，count(子串)(出现次数)
#判断：isdigit()(是否全数字)，isalpha()(是否全字母)，isalnum()(是否全字母或数字)，isspace()(是否全空白)
#替换：replace(旧,新)(替换子串)，strip()(去两端空白)，lstrip()(去左端空白)，rstrip()(去右端空白)
#分割：split(分隔符)(分割成列表)，splitlines()(按行分割)，join(列表)(列表拼接成字符串)
#格式化：format()，f-string

#列表(list)常用方法
#长度：len(lst)
#最值：max(lst)，min(lst)，sum(lst)
#添加：append(元素)(加到末尾)，insert(位置,元素)(插入)，extend(列表)(扩展列表)
#删除：pop(位置)(删除并返回，默认末尾)，remove(元素)(删除第一个匹配)，clear()(清空)，del lst[位置]
#排序：sort()(原地排序)，reverse()(反转)，sorted(列表)(返回新列表)
#统计：count(元素)(出现次数)，index(元素)(首次出现位置)
#拷贝：copy()(浅拷贝)

#元组(tuple)常用方法
#长度：len(tup)
#统计：count(元素)(出现次数)，index(元素)(首次出现位置)
#注意：元组不可修改，无增删改方法
# a=((1,2,3),(4,5,6))
# print(a.index((4,5,6)))

#字典(dict)常用方法
#长度：len(dic)
#获取：keys()(所有键)，values()(所有值)，items()(所有键值对)，get(键,默认值)(安全获取)
#添加/更新：dic[键]=值，update(字典)(合并字典)
#删除：pop(键)(删除并返回值)，popitem()(删除最后一个)，clear()(清空)，del dic[键]
#遍历：for k in dic，for v in dic.values()，for k,v in dic.items()

#集合(set)常用方法
#长度：len(st)
#添加：add(元素)，update(集合)(添加多个)
#删除：remove(元素)(不存在报错)，discard(元素)(不存在不报错)，pop()(随机删除)，clear()(清空)
#运算：union(集合)(并集|)，intersection(集合)(交集&)，difference(集合)(差集-)，symmetric_difference(集合)(对称差集^)
#判断：issubset(集合)(是否子集)，issuperset(集合)(是否超集)，isdisjoint(集合)(是否无交集)

#数字类型常用函数
#绝对值：abs(-5) -> 5
#幂运算：pow(底,指数) 或 **
#四舍五入：round(数字,小数位数)
#取整：int()(向下取整)，math.ceil()(向上取整)，math.floor()(向下取整)
#最大最小：max(a,b,c)，min(a,b,c)

# import random
#
# # randint(a, b) - 生成 [a, b] 范围内的随机整数（包含两端）
# num = random.randint(1, 10)  # 生成 1-10 之间的随机整数
#
# # randrange(start, stop[, step]) - 从范围内随机选择一个数
# num = random.randrange(0, 10, 2)  # 从 0,2,4,6,8 中随机选择一个
# # random() - 生成 [0.0, 1.0) 之间的随机浮点数
# num = random.random()  # 如 0.374829
#
# # uniform(a, b) - 生成 [a, b] 范围内的随机浮点数
# num = random.uniform(1.5, 10.5)  # 生成 1.5-10.5 之间的随机浮点数
# # choice(seq) - 从序列中随机选择一个元素
# lst = [1, 2, 3, 4, 5]
# item = random.choice(lst)
#
# # choices(population, k=n) - 从序列中有放回地随机选择 n 个元素
# items = random.choices(lst, k=3)  # 可能重复
#
# # sample(population, k=n) - 从序列中无放回地随机选择 n 个元素
# items = random.sample(lst, 3)  # 不会重复
#
# # shuffle(x) - 原地打乱序列顺序
# random.shuffle(lst)  # lst 被随机打乱
# # seed(a) - 设置随机种子，使结果可复现
# random.seed(42)
# print(random.random())  # 每次运行都得到相同结果
# # gauss(mu, sigma) - 高斯分布（正态分布）
# num = random.gauss(0, 1)  # 均值0，标准差1
#
# # normalvariate(mu, sigma) - 正态分布
# num = random.normalvariate(0, 1)

# global保留字在函数内部声明全局变量

#finally对应语句块4一定执行
#else对应语句块3在不发生异常时执行






















