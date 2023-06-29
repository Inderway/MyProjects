# convert json into corpus
# created by wei
# April 26, 2023

import json

data_path='./newstest17.json'
src_path='./en-zh.en'
tgt_path='./en-zh.zh'
src_lines=[]
tgt_lines=[]
corpus=json.load(open(data_path,'r'))
for item in corpus:
    src_lines.append(item[0]+'\n')
    tgt_lines.append(item[1]+'\n')
with open(src_path, "w", encoding="utf-8") as fsrc:
    fsrc.writelines(src_lines)

with open(tgt_path, "w", encoding="utf-8") as ftgt:
    ftgt.writelines(tgt_lines)

print("lines of Source Language: ", len(src_lines))
print("lines of Target Language: ", len(tgt_lines))
print("-------- Get Corpus ! --------")