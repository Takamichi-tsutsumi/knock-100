# -*- coding: utf-8 -*-
import sys
import operator
src_file = open(sys.argv[1])

lines = src_file.readlines()
prefectures = {}


def prefecture_of(line):
    return line.split('\t')[0]

for line in lines:
    prefecture = prefecture_of(line)
    if prefecture in prefectures:
        prefectures[prefecture] += 1
    else:
        prefectures[prefecture] = 1

prefectures = sorted(prefectures.items(),
                     key=operator.itemgetter(1),
                     reverse=True)
print(list(map(lambda item: item[0], prefectures)))

src_file.close()
