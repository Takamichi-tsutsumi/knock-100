# coding: utf-8

# 00.文字列の逆転
def switch(str):
    length = len(str)
    new_str = ""
    for i in range(length):
        new_str += str[length - 1 - i]
    return new_str

print  switch("stressed")


