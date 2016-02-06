# -*- coding: utf-8 -*-
import sys
src_file = open(sys.argv[1])

lines = src_file.readlines()


def column3(line):
    return float(line.split('\t')[2])

sorted_lines = sorted(lines, key=column3, reverse=True)

for l in sorted_lines:
    print(l.replace('\n', ''))

src_file.close()
