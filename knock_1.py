# -*- coding: utf-8 -*-

# 00.文字列の逆転
# def switch(str):
#     length = len(str)
#     new_str = ""
#     for i in range(length):
#         new_str += str[length - 1 - i]
#     return new_str
#
# print  switch("stressed")
#
str = "stressed"
print str[::-1]


# 01.パタトクカシー
str = u"パタトクカシー"
print str[::2]
# new_str = ""
# for i in range(len(str)/2 + 1):
#     new_str += str[2 * i]
# print new_str


# 02 パトカー + タクシー
pat = u"パトカー"
taxi = u"タクシー"
print(''.join([p + t for (p,t) in zip(pat, taxi)]))
