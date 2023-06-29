# to parse the xml file
# created by chatgpt
# modified by wei 
# May 29, 2023

import xml.etree.ElementTree as ET

src_lan='ja'
tgt_lan='en'
dir_path='D:\\documents\\__study files master\\深度自然语言处理前沿\\datasets\\test\\'
file_path=dir_path+'newstest2021.ja-en.xml'

# 解析XML文件
tree = ET.parse(file_path,parser=ET.XMLParser(encoding="utf-8"))
root = tree.getroot()

list_src=[]
list_tgt=[]
# 遍历<doc>标签
for doc in root.findall('doc'):
    # 查找包含<src>和<ref>标签的<doc>标签
    if doc.findall('src') and doc.findall('ref'):
        # 遍历<src>标签中的<seg>标签
        for seg in doc.find('src').iter('seg'):
            list_src.append(seg.text+'\n')
        # 遍历<ref>标签中的<seg>标签
        for seg in doc.find('ref').iter('seg'):
            list_tgt.append(seg.text+'\n')
        with open(f'./test.{src_lan}-{tgt_lan}.{src_lan}', "w", encoding='utf-8') as src_file, \
            open(f'./test.{src_lan}-{tgt_lan}.{tgt_lan}',"w",encoding='utf-8') as tgt_file:
            src_file.writelines(list_src)
            tgt_file.writelines(list_tgt)

print(f"{src_lan}:{len(list_src)}\n{tgt_lan}:{len(list_tgt)}")




