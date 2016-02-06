# -*- coding: utf-8 -*-

import sys
f = open(sys.argv[1])
new_file = open('dest.txt', 'w')
lines = f.readlines()

for l in lines:
    print(l)
    new_line = l.replace('\t', ' ')
    new_file.writelines(new_line)

new_file.close()
f.close()
