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

#异常





















