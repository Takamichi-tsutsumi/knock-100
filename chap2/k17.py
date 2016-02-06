# -*- coding: utf-8 -*-
import sys

src_file = open(sys.argv[1], 'r')
line = src_file.readlines()[0]
chars = []

for c in line:
    if c not in chars:
        chars.append(c)

print(len(chars))

src_file.close()
