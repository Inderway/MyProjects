# to parse the ALT's data
# created by wei 
# April 9, 2024

import re

work_dir="D:\\datasets\\ALT-Parallel-Corpus-20191206\\"
test_ids=[]
with open(work_dir+"URL-test.txt",'r',encoding='utf-8') as test_file:
    texts=test_file.readlines()
    pattern = r"URL\.(\d+)\s"
    for text in texts:
        id=re.search(pattern, text).group(1)
        test_ids.append(id)


src_path="data_my.txt"
tgt_path="data_en.txt"

src_lan="my_MM"

with open(work_dir+src_path,'r',encoding="utf-8") as src_file,\
    open(f"test.{src_lan}-en_XX.{src_lan}",'w',encoding="utf-8") as src_write:
    texts=src_file.readlines()
    pattern = r"SNT\.(\d+)\."
    pattern2=r"\d+\s+(.*)"
    count=0
    for text in texts:
        id=re.search(pattern, text).group(1)
        if id in test_ids:
            count+=1
            line=re.search(pattern2,text).group(1)
            src_write.write(line+'\n')

    print(f"{src_lan}: {count}")

with open(work_dir+tgt_path,'r',encoding="utf-8") as tgt_file,\
    open(f"test.{src_lan}-en_XX.en_XX",'w',encoding="utf-8") as tgt_write:
    texts=tgt_file.readlines()
    pattern = r"SNT\.(\d+)\."
    pattern2=r"\d+\s+(.*)"
    count=0
    for text in texts:
        id=re.search(pattern, text).group(1)
        if id in test_ids:
            count+=1
            line=re.search(pattern2,text).group(1)
            tgt_write.write(line+'\n')
    print(f"en_XX: {count}")





