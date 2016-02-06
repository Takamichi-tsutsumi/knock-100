# -*- coding: utf-8 -*-
import sys

src_file = open(sys.argv[1], "r")
src_lines = src_file.readlines()
new_files = list(map(lambda f: open(f, "w"), ['col1.txt', 'col2.txt']))
print(new_files)

for i in range(0, 2):
    new_files[i].writelines(src_lines[i])

for f in new_files:
    f.close()
