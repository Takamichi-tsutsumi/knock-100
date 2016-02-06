# -*- coding: utf-8 -*-

files = list(map(lambda f: open(f, 'r'), ['col1.txt', 'col2.txt']))
new_file = open('merged.txt', 'w')

for i, f in enumerate(files):
    new_file.write(f.read())
    f.close()
    if i == 0:
        new_file.write('\t')

new_file.close()
