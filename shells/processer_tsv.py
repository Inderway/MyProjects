# -*- coding=utf8 -*-
# to parse the tsv file
# created by chatgpt
# modified by wei
# May 28, 2023

import csv

file_path=r'D:\documents\__study files master\深度自然语言处理前沿\datasets\train\news-commentary-v16.en-ja.tsv'
# 打开翻译平行数据的tsv文件
with open(file_path, 'r', encoding='utf-8') as tsv_file:
    tsv_reader = csv.reader(tsv_file, delimiter='\t')
    
    # 创建英语和日语文本文件
    with open('train.en', 'w', encoding='utf-8') as english_file, \
         open('train.ja', 'w', encoding='utf-8') as japanese_file:
        length=0
        # 逐行读取tsv文件
        for row in tsv_reader:
            # 将英语文本写入英语文本文件
            english_file.write(row[0] + '\n')
            # 将日语文本写入日语文本文件
            japanese_file.write(row[1] + '\n')
            length+=1
    print(f"Sentences: {length}")