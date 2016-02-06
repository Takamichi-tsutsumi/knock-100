# -*- coding: utf-8 -*-

import sys
src, N = open(sys.argv[1], 'r'), int(sys.argv[2])

src_lines = src.readlines()

for i in range(0, N):
    print(src_lines[len(src_lines) - (N - i)])

src.close()
