# -*- coding: utf-8 -*-
import json
import re

src = open('./jawiki-country.json', 'r')
data = src.readlines()
lines = list(map(lambda l: json.loads(l), data))


''' イギリスの記事の抽出 '''
text_en = next(l['text'] for l in lines if l['title'] == 'イギリス')
print(text_en)

''' 24.メディアファイルの抽出 '''
media_regexp = re.compile('(\w+.)(jpg|JPG|png|PNG|SVG|svg)')
result = re.findall(media_regexp, text_en)
# print(result)

'''
25.テンプレートの抽出
基礎情報を辞書に格納。
'''

re_standard = re.compile('\|(?P<key>\S+) = (?P<value>\S+)\\n')
standard_data = re.findall(re_standard, text_en)
print(standard_data)
standard_data_dict = dict(standard_data)
print(standard_data_dict)
