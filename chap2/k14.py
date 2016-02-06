# -*- coding: utf-8 -*-
import sys

src_file = open(sys.argv[1], 'r')
lines = src_file.readlines()
N = int(sys.argv[2])

i = 0
while i < N:
    print(lines[i])
    i += 1

src_file.close()
