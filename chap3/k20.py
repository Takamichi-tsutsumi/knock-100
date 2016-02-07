# -*- coding: utf-8 -*-

import json
import re
src = open('./jawiki-country.json', 'r')
data = src.readlines()

england = {}
for line in data:
    line_data = json.loads(line)
    if line_data['title'] == 'イギリス':
        england = line_data['text']

print(england)
# regexp = re.compile(r'[[Category:' '\S+' r']]')
regexp = re.compile(
    '(?P<prefix>\[\[Category\:)(?P<category>\S+)(?P<suffix>\]\])'
)
result = re.findall(regexp, england)

if result:
    for line in result:
        print(line[1])
    # print(result)

re_section = re.compile(
        '(=+)(?P<section>\w+)(=+)'
        )
sections = re.findall(re_section, england)
if sections:
    for section in sections:
        print(section[1], len(section[0]) - 1)


src.close()
