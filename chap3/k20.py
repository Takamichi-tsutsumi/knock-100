# -*- coding: utf-8 -*-

import json
src = open('./jawiki-country.json', 'r')
data = src.readlines()

england = {}
for line in data:
    line_data = json.loads(line)
    if line_data['title'] == 'イギリス':
        england = line_data['text']

print(england)

src.close()
