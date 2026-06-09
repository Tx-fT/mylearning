# choice(seq) - 从序列中随机选择一个元素
lst = [1, 2, 3, 4, 5]
item = random.choice(lst)

# choices(population, k=n) - 从序列中有放回地随机选择 n 个元素
items = random.choices(lst, k=3)  # 可能重复

# sample(population, k=n) - 从序列中无放回地随机选择 n 个元素
items = random.sample(lst, 3)  # 不会重复

# shuffle(x) - 原地打乱序列顺序
random.shuffle(lst)  # lst 被随机打乱
# choice(seq) - 从序列中随机选择一个元素
lst = [1, 2, 3, 4, 5]
item = random.choice(lst)

# choices(population, k=n) - 从序列中有放回地随机选择 n 个元素
items = random.choices(lst, k=3)  # 可能重复

# sample(population, k=n) - 从序列中无放回地随机选择 n 个元素
items = random.sample(lst, 3)  # 不会重复

# shuffle(x) - 原地打乱序列顺序
random.shuffle(lst)  # lst 被随机打乱
