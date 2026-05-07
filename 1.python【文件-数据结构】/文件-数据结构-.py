#文件读写和异常处理
# 对数据进行持久化的场景
# 指将数据从无法长久保存数据的存储介质（通常是内存）转移到可以长久保存数据的存储介质（通常是硬盘）中
# 最直接简单的方式就是通过文件系统将数据保存到文件中。

# 打开和关闭文件
# Python 内置的open函数来打开文件
# 通过函数的参数指定文件名、操作模式和字符编码等信息
#r:读取 w:写入（会先截断之前的内容） x：写入，如果文件已经存在会产生异常
#a:追加，将内容写到已有文件的末尾 b：二进制 t：文本模式 +：更新（即可读又可写）
# 在使用open函数时，如果打开的文件是字符文件（文本文件），可以通过encoding参数来指定读写文件使用的字符编码。
# file=open('test.txt','r',encoding='utf-8')
# # print(file.read())
# for line in file:
#     print(line)
# file = open('致橡树.txt', 'r', encoding='utf-8')
# for line in file:
#     print(line, end='')
# file.close()
#
# file = open('致橡树.txt', 'r', encoding='utf-8')
# lines = file.readlines()
# for line in lines:
#     print(line, end='')
# file.close()
# file.close()
# 如果要向文件中写入内容，可以在打开文件时使用w或者a作为操作模式，
# 前者会截断之前的文本内容写入新的内容，后者是在原来内容的尾部追加新的内容。
# file =open('test.txt','a',encoding='utf-8')
# file.write('\nhhhh')
# 请注意上面的代码，如果open函数指定的文件并不存在或者无法打开，那么将引发异常状况导致程序崩溃
# Python 中和异常相关的关键字有五个，分别是try、except、else、finally和raise
# file = None
# try:
#     file = open('致橡树.txt', 'r', encoding='utf-8')
#     print(file.read())#try 中的代码没有出现异常时会执行的代码
# except FileNotFoundError:#except块来捕获异常并进行相应的处理。
#     print('无法打开指定的文件!')
# except LookupError:
#     print('指定了未知的编码!')
# except UnicodeDecodeError:
#     print('读取文件时解码错误!')
# else:#而且else中的代码不会再进行异常捕获，也就是说如果遇到异常状况，程序会因异常而终止并报告异常信息。
#     print('111')
# finally:
#     if file:
#         file.close()
# # finally代码块称为“总是执行代码块”，它最适合用来做释放外部资源的操作。
# finally块的代码不论程序正常还是异常都会执行
# class InputError(ValueError):
#     """自定义异常类型"""
#     pass#使用 pass 表示暂时不需要添加新的属性和方法
# def fac(num):
#     """求阶乘"""
#     if num < 0:
#         raise InputError('只能计算非负整数的阶乘')#raise关键字来引发异常（抛出异常对象）
#     if num in (0, 1):
#         return 1
#     return num * fac(num - 1)
# flag = True
# while flag:
#     num = int(input('n = '))
#     try:
#         print(f'{num}! = {fac(num)}')
#         flag = False
#     except InputError as err:#当try中引起此异常，并用as复值
#         print(err)

# 还可以使用with上下文管理器语法在文件操作完成后自动执行文件对象的close方法
# try:
#     with open('致橡树.txt', 'r', encoding='utf-8') as file:
#         print(file.read())
# except FileNotFoundError:
#     print('无法打开指定的文件!')
# except LookupError:
#     print('指定了未知的编码!')
# except UnicodeDecodeError:
#     print('读取文件时解码错误!')
# try:
#     with open('guido.jpg', 'rb') as file1, open('吉多.jpg', 'wb') as file2:
#         data = file1.read(512)#明确指定512字节，分批读取内存占用少
#         while data:
#             file2.write(data)
#             data = file1.read()
# except FileNotFoundError:
#     print('指定的文件无法打开.')
# except IOError:
#     print('读写文件时出现错误.')
# print('程序执行结束.')
#
# try后面的except语句不是必须的，finally语句也不是必须的，但是二者必须要有一个
#
# except语句中还可以通过元组同时指定多个异常类型进行捕获；except语句后面如果不指定异常类型，则默认捕获所有异常；捕获异常后可以使用raise要再次抛出，但是不建议捕获并抛出同一个异常；

# 把一个列表或者一个字典中的数据保存到文件中又该怎么做
# import json
#
# my_dict = {
#     'name': '骆昊',
#     'age': 40,
#     'friends': ['王大锤', '白元芳'],
#     'cars': [
#         {'brand': 'BMW', 'max_speed': 240},
#         {'brand': 'Audi', 'max_speed': 280},
#         {'brand': 'Benz', 'max_speed': 280}
#     ]
# }
# with open('data.json', 'w') as file:
#     json.dump(my_dict, file)
# json模块有四个比较重要的函数，分别是：
#
# dump - 将 Python 对象按照 JSON 格式序列化到文件中
# dumps - 将 Python 对象处理成 JSON 格式的字符串+s:string
# load - 将文件中的 JSON 数据反序列化成对象
# loads - 将字符串的内容反序列化成 Python 对象
#
# 序列化（serialization）在计算机科学的数据处理中，是指将数据结构或对象状态转换为可以存储或传输的形式，这样在需要的时候能够恢复到原先的状态，而且通过序列化的数据重新获取字节时，可以利用这些字节来产生原始对象的副本（拷贝）。
# import json
# with open('data.json','r') as file:
#     my_dict=json.load(file)
#     print(my_dict)
#     print(type(my_dict))

# 包管理工具 pip
# json模块在数据序列化和反序列化时性能并不是非常理想，
# 为了解决这个问题，可以使用三方库ujson来替换json
# 通过 pip 可以查找、安装、卸载、更新 Python 的三方库或工具
# pip install
# pip search命令根据名字查找需要的三方库
# pip list命令来查看已经安装过的三方库。
# pip install -U或pip install --upgrade更新
# pip uninstall删除

#使用网络API获取数据
# 网络数据服务（或称之为网络 API）都是基于 HTTP 或 HTTPS 提供 JSON 格式的数据
# 我们可以通过 Python 程序发送 HTTP 请求给指定的 URL（统一资源定位符），
# 这个 URL 就是所谓的网络 API，如果请求成功，它会返回 HTTP 响应，
# 而 HTTP 响应的消息体中就有我们需要的 JSON 格式的数据。
#互联网协议入门
# 互联网的核心是一系列协议，总称为"互联网协议"（Internet Protocol Suite）。它们对电脑如何连接和组网，做出了详尽的规定。理解了这些协议，就理解了互联网的原理。
# 大家都遵守的规则，就叫做"协议"，互联网的每一层，都定义了很多协议。这些协议的总称，就叫做"互联网协议"（Internet Protocol Suite）
# 1.1这就叫做"实体层"，它就是把电脑连接起来的物理手段。它主要规定了网络的一些电气特性，作用是负责传送0和1的电信号。
# 2.1这就是"链接层"的功能，它在"实体层"的上方，确定了0和1的分组方式。
# 2.2每家公司都有自己的电信号分组方式->‘以太网’协议：
#    以太网规定，一组电信号构成一个数据包，叫做"帧"（Frame）。每一帧分成两个部分：标头（Head）和数据（Data）。
#2.3MAC地址：发送者和接受者是如何标识
#           以太网规定连入网络的所有设备，都必须具有‘网卡’接口。数据包：网卡之间传递
#           网卡的地址，就是数据包的发送地址和接收地址，这叫做MAC地址。
#2.4广播：
# 2.4.1一块网卡怎么会知道另一块网卡的MAC地址
#       有一种ARP协议：以太网数据包必须知道接收方的MAC地址，然后才能发送。
# 2.4.2:就算有了MAC地址，系统怎样才能把数据包准确送到接收方？:
#       在同一个子网络内，每一个计算机都接受，读取‘标头’，找到接收方的mac地址与自己比较，这种发送方式叫‘广播’
#3.1网络层背景：单单依靠MAC地址，一个重大的缺点：不仅效率低，而且局限在发送者所在的子网络。也就是说，如果两台计算机不在同一个子网络，广播是传不过去的。
#           找到一种方法，能够区分哪些MAC地址属于同一个子网络，哪些不是。如果是同一个子网络，就采用广播方式发送，否则就采用"路由"方式发送。
#           （"路由"的意思，就是指如何向不同的子网络分发数据包，这是一个很大的主题，
#  *****： 这就导致了"网络层"的诞生。它的作用是引进一套新的地址，使得我们能够区分不同的计算机是否属于同一个子网络。
#          这套地址就叫做"网络地址"，简称"网址"
#           "网络层"出现以后，每台计算机有了两种地址，一种是MAC地址，另一种是网络地址
#           MAC地址是绑定在网卡上的，网络地址则是管理员分配的，它们只是随机组合在一起。
#           网络地址帮助我们确定计算机所在的子网络，MAC地址则将数据包送到该子网络中的目标网卡。
#           先处理网络地址再处理mca地址
# 3.2IP协议：规定网络地址的协议，叫做IP协议。它所定义的地址，就被称为IP地址
#           地址分成两个部分，前一部分代表网络，后一部分代表主机
#           怎样判断是否属于同一个子网络：
#           子网掩码"，就是表示子网络特征的一个参数。它在形式上等同于IP地址，也是一个32位二进制数字
#           AND运算：方法是将两个IP地址与子网掩码分别进行AND运算（两个数位都为1，运算结果为1，否则为0），然后比较结果是否相同，如果是的话，就表明它们在同一个子网络中，否则就不是。
#           总结一下，IP协议的作用主要有两个，一个是为每一台计算机分配IP地址，另一个是确定哪些地址在同一个子网络
# 3.3IP数据包：根据IP协议发送的数据，就叫做IP数据包，包括IP地址信息。
#              以太网数据包只包含MAC地址：可以把IP数据包直接放进以太网数据包的"数据"部分（互联网分层结构的好处：上层的变动完全不涉及下层的结构。）
#               IP数据包也分为"标头"和"数据"两个部分。
# 3.4ARP协议：我们必须同时知道两个地址，一个是对方的MAC地址，另一个是对方的IP地址：
#               通常情况下，对方的IP地址是已知的（后文会解释），但是我们不知道它的MAC地址。
#             我们需要一种机制，能够从IP地址得到MAC地址。
#             情况一：不在同一子网络->只能把数据包传送到两个子网络的网关
#             情况二：ARP协议也是发出一个数据包（包含在以太网数据包中），其中包含它所要查询主机的IP地址，在对方的MAC地址这一栏
#                   子网络的每一台主机，都会收到这个数据包，从中取出IP地址，与自身的IP地址进行比较。
# 4.1传输层：们已经可以在互联网上任意两台主机上建立通信
#           当一个数据包从互联网上发来的时候，你怎么知道，它是表示网页的内容，还是表示在线聊天的内容？
#           我们还需要一个参数，表示这个数据包到底供哪个程序（进程）使用。
#           这个参数就叫做"端口"（port）：每一个使用网卡的程序的编号
# 4.2"传输层"的功能：就是建立"端口到端口"的通信。相比之下，"网络层"的功能是建立"主机到主机"的通信。
#                   只要确定主机和端口，我们就能实现程序之间的交流。
# 4.3UPD协议：在数据包中加入端口信息，这就需要新的协议。最简单的实现叫做UDP协议，它的格式几乎就是在数据前面，加上端口号。
#              UDP数据包，也是由"标头"和"数据"两部分组成。
#              "标头"部分主要定义了发出端口和接收端口，"数据"部分就是具体的内容。
#              然后，把整个UDP数据包放入IP数据包的"数据"部分（实际都在以太数据包）
# 4.4TCP协议：UDP协议的优点是比较简单，容易实现，但是缺点是可靠性较差，一旦数据包发出，无法知道对方是否收到。
#              为了解决这个问题，提高网络可靠性，TCP协议就诞生了（有确认机制的UDP协议，每发出一个数据包都要求确认）
# 5.1应用层：应用程序收到"传输层"的数据，接下来就要进行解读。由于互联网是开放架构，数据来源五花八门，必须事先规定好格式，否则根本无法解读。
#           "应用层"的作用，就是规定应用程序的数据格式。
#            须有不同协议规定电子邮件、网页、FTP数据的格式，这些应用程序协议就构成了"应用层"。
#           这是最高的一层，直接面对用户。它的数据就放在TCP数据包的"数据"部分。
# 测试用假数据接口（示例）
# import requests
#
# resp = requests.get('https://jsonplaceholder.typicode.com/posts')
# if resp.status_code == 200:
#     for news in resp.json()[:5]:
#         print(news['title'])
#         print(f"https://jsonplaceholder.typicode.com/posts/{news['id']}")
#         print('-' * 60)
# 过requests模块的get函数向天聚数行的国内新闻接口发起了一次请求，
# 如果请求过程没有出现问题，get函数会返回一个Response对象，
# 通过该对象的status_code属性表示 HTTP 响应状态码，如果不理解没关系，
# 你只需要关注它的值，如果值等于200或者其他2字头的值，那么我们的请求是成功的。
# 通过Response对象的json()方法可以将返回的 JSON 格式的数据直接处理成 Python 字典，非常方便。
# ***
# 处理 JSON 格式的数据很显然是程序员必须掌握的一项技能，因为不管是访问网络 API 接口还是提供网络 API 接口给他人使用，
# 都需要具备处理 JSON 格式数据的相关知识。

# HTTP协议入门

#python读写csv文件
# CSV（Comma Separated Values）全称逗号分隔值文件是一种简单、通用的文件格式，
# 被广泛的应用于应用程序（数据库、电子表格等）数据的导入和导出以及异构系统之间的数据交换。
# 因为 CSV 是纯文本文件，不管是什么操作系统和编程语言都是可以处理纯文本的，
# 而且很多编程语言中都提供了对读写 CSV 文件的支持，因此 CSV 格式在数据处理和数据科学中被广泛应用。
# csv文件特点
# 1.纯文本，使用某种字符集（ASCII，Unicode，GB1312等）
# 2.有一条条记录组成，典型的每行一条记录
# 3.每条记录被分割符（如，；\t）分割为字段（列）
# 4.每条记录都有同样的字段序列
# CSV 文件可以使用文本编辑器或类似于 Excel 电子表格这类工具打开和编辑，
# 当使用 Excel 这类电子表格打开 CSV 文件时，你甚至感觉不到 CSV 和 Excel 文件的区别。
# 1.将数据写入csv文件
# import csv
# import random
# with open('scores.csv','w') as file:
#     writer=csv.writer(file)
#     writer.writerow(['name','1','2','3'])
#     names=['1','2','3']
#     for name in names:
#         score=[random.randrange(50,101) for _ in range(3)]
#         score.insert(0,name)
#         writer.writerow(score)
#
# writer函数，除了传入要写入数据的文件对象外，还可以dialect参数，它表示 CSV 文件的方言，默认值是excel。
# 还可以通过delimiter、quotechar、quoting参数来指定分隔符（默认是逗号）、包围值的字符（默认是双引号）以及包围的方式
# 从csv文件中读取数据
# import csv
#
# with open('scores.csv', 'r') as file:
#     reader = csv.reader(file, delimiter='|')#读取全部
#     for data_list in reader:#读取一行
#         print(reader.line_num, end='\t')#行数
#         for elem in data_list:#一行中的元素
#             print(elem, end='\t')
#         print()
# 用Python做数据分析，很有可能会用到名为pandas的三方库
# pandas中封装了名为read_csv和to_csv的函数用来读写 CSV 文件
# read_csv会将读取到的数据变成一个DataFrame对象，而DataFrame就是pandas库中最重要的类型，它封装了一系列用于数据处理的方法（清洗、转换、聚合等）；
# 而to_csv会将DataFrame对象中的数据写入 CSV 文件，完成数据的持久化。
# read_csv函数和to_csv函数远远比原生的csvreader和csvwriter强大。

#python读取excel文件
# import xlrd
#
# # 使用xlrd模块的open_workbook函数打开指定Excel文件并获得Book对象（工作簿）
# wb = xlrd.open_workbook('阿里巴巴2020年股票数据.xls')
# # 通过Book对象的sheet_names方法可以获取所有表单名称
# sheetnames = wb.sheet_names()
# print(sheetnames)
# # 通过指定的表单名称获取Sheet对象（工作表）
# sheet = wb.sheet_by_name(sheetnames[0])
# # 通过Sheet对象的nrows和ncols属性获取表单的行数和列数
# print(sheet.nrows, sheet.ncols)
# for row in range(sheet.nrows):
#     for col in range(sheet.ncols):
#         # 通过Sheet对象的cell方法获取指定Cell对象（单元格）
#         # 通过Cell对象的value属性获取单元格中的值
#         value = sheet.cell(row, col).value
#         # 对除首行外的其他行进行数据格式化处理
#         if row > 0:
#             # 第1列的xldate类型先转成元组再格式化为“年月日”的格式
#             if col == 0:
#                 # xldate_as_tuple函数的第二个参数只有0和1两个取值
#                 # 其中0代表以1900-01-01为基准的日期，1代表以1904-01-01为基准的日期
#                 value = xlrd.xldate_as_tuple(value, 0)
#                 value = f'{value[0]}年{value[1]:>02d}月{value[2]:>02d}日'
#             # 其他列的number类型处理成小数点后保留两位有效数字的浮点数
#             else:
#                 value = f'{value:.2f}'
#         print(value, end='\t')
#     print()
# # 获取最后一个单元格的数据类型
# # 0 - 空值，1 - 字符串，2 - 数字，3 - 日期，4 - 布尔，5 - 错误
# last_cell_type = sheet.cell_type(sheet.nrows - 1, sheet.ncols - 1)
# print(last_cell_type)
# # 获取第一行的值（列表）
# print(sheet.row_values(0))
# # 获取指定行指定列范围的数据（列表）
# # 第一个参数代表行索引，第二个和第三个参数代表列的开始（含）和结束（不含）索引
# print(sheet.row_slice(3, 0, 5))
# python还可处理ppt word pdf等

# python处理图像
# 在计算机中，我们可以将红、绿、蓝三种色光以不同的比例叠加来组合成其他的颜色，因此这三种颜色就是色光三原色
# 计算机系统中，我们通常会将一个颜色表示为一个 RGB 值或 RGBA 值（其中的 A 表示 Alpha 通道，它决定了透过这个图像的像素，也就是透明度）。
# 用Pillow处理图像
# Pillow 是由从著名的 Python 图像处理库 PIL 发展出来的一个分支，通过 Pillow 可以实现图像压缩和图像处理等各种操作。
# Pillow 中最为重要的是Image类，可以通过Image模块的open函数来读取图像并获得Image类型的对象。
# from PIL import Image
# 读取图像获取Image对象
# image =Image.open('xf.jpg')
#通过Image对象的format属性获得对象格式
# print(image.format)
# # size
# print(image.size)
# print(image.mode)
#image.show()#显示图像
# image.crop((80,20,310,360)).show()#裁剪图像
# 通过Image对象的thumbnail方法生成指定尺寸的缩略图
# image.thumbnail((128, 128))
# image.show()
# 读取骆昊的照片获得Image对象
# luohao_image = Image.open('xfxxf.jpg')
# # 读取吉多的照片获得Image对象
# guido_image = Image.open('xf.jpg')
# # 从吉多的照片上剪裁出吉多的头
# guido_head = guido_image.crop((80, 20, 310, 360))
# width, height = guido_head.size
# # 使用Image对象的resize方法修改图像的尺寸
# # 使用Image对象的paste方法将吉多的头粘贴到骆昊的照片上
# luohao_image.paste(guido_head.resize((int(width / 1.5), int(height / 1.5))), (172, 40))
# luohao_image.show()
# image = Image.open('guido.jpg')
# # 使用Image对象的rotate方法实现图像的旋转
# image.rotate(45).show()
# # 使用Image对象的transpose方法实现图像翻转
# # Image.FLIP_LEFT_RIGHT - 水平翻转
# # Image.FLIP_TOP_BOTTOM - 垂直翻转
# image.transpose(Image.FLIP_TOP_BOTTOM).show()
# for x in range(80, 310):
#     for y in range(20, 360):
#         # 通过Image对象的putpixel方法修改图像指定像素点
#         image.putpixel((x, y), (128, 128, 128))
# image.show()

#类型注解
# 例：name: list[str|int]=['A','B','C','D','E','F']
#变量：数据类型
# 常见类型int float bool str None list set tuple dict and str|int....
#函数
# def calc(scores:list[int])->float:
#     return sum(scores)/len(scores)

# 模块：一个.py文件就是一个模块，基本组织单位，在模块例可以定义变量函数类以及可执行代码
#random，time等标准模块+自定义模块

#教务管理系统案例
# class student:
#     def __init__(self,name,s):
#         self.name=name
#         self.scores=s
#     def update(self,s):
#         self.scores=s
# #添加成绩
# class edumanagement:
#     def __init__(self):
#         self.stu_list=[]
#     #添加
#     def add(self):
#         name=input()
#         #判断学生姓名是否存在
#         for s in self.stu_list:
#             if s.name==name:
#                 print("-1")
#                 return
#         scores=int(input())
#         if 0<=scores<=100:
#             stu=student(name,scores)
#             self.stu_list.append(stu)
#         else:
#             print("-1")
#     #修改
#     def update(self):
#         name=input()
#         for s in self.stu_list:
#             if s.name==name:
#                 print(s.scores)
#                 t=int(input())
#                 if 0<=t<=100:
#                     s.update(t)
#                     return
#                 else:
#                     print("-1")
#     #删除
#     def remove(self):
#         name=input()
#         for s in self.stu_list:
#             if s.name==name:
#                 self.stu_list.remove(s)
#                 return
#             else:
#                 print("-1")
#     #find
#     def find(self):
#         name=input()
#         for s in self.stu_list:
#             if s.name==name:
#                 print(s.scores)
#                 return
#             else:
#                 print("-1")
#     def display(self):
#         for s in self.stu_list:
#             print(f'{s.name}:{s.scores:>10.2f}')
#
# edu=edumanagement()
# while(True):
#     print('123456')
#     print()
#     ch=int(input())
#     match ch:
#         case 1:
#             edu.add()
#         case 2:
#             edu.update()
#         case 3:
#             edu.remove()
#         case 4:
#             edu.find()
#         case 5:
#             edu.display()
#         case 6:
#             print('ok')
#             break
# try:
#     print('######')
#     #可能出现异常的代码
# except NameError as e: #[异常类型（捕获特定异常） as 变量名（得到具体信息）]:
#     #出现异常时的预案
#     print(e)
# else:
#     print(111)#no problem
#
# finally:#都会执行的代码(不论出错)
#     print('ok')



















