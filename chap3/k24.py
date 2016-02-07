# -*- coding: utf-8 -*-
import json
import re

src = open('./jawiki-country.json', 'r')
data = src.readlines()
lines = list(map(lambda l: json.loads(l), data))

text_en = next(l['text'] for l in lines if l['title'] == 'イギリス')
print(text_en)

media_regexp = re.compile('(\w+.)(jpg|JPG|png|PNG|SVG|svg)')
result = re.findall(media_regexp, text_en)
print(result)
