# to extract sentences from sgm files
# created by wei 
# April 24, 2023



# import xml.etree.ElementTree as ET

# def extract_seg_from_sgm(sgm_data):
#     seg_contents = []
#     # filter invalid tokens

#     sgm_data=sgm_data.replace('&', '&amp;')
    
#     root = ET.fromstring(sgm_data)

#     for seg in root.iter('seg'):
#         seg_contents.append(seg.text+'\n')

#     return seg_contents

# src_lan='ja'
# tgt_lan='en'
# dir_path='D:\\datasets\\newstest20\\'
# src_path=dir_path+'newstest2020-jaen-ref.en.sgm'
# tgt_path=dir_path+'newstest2020-jaen-src.ja.sgm'
# with open(src_path, 'r', encoding='utf-8') as src, \
#     open(tgt_path, 'r', encoding='utf-8') as tgt:
#     print(f"Process {src_lan}")
#     sgm_data = src.read()
#     list_src = extract_seg_from_sgm(sgm_data)
#     print(f"Process {tgt_lan}")
#     sgm_data = tgt.read()
#     list_tgt = extract_seg_from_sgm(sgm_data)

# with open(f'./valid.{src_lan}-{tgt_lan}.{src_lan}', 'w', encoding='utf-8') as src,\
#     open(f'./valid.{src_lan}-{tgt_lan}.{tgt_lan}', 'w', encoding='utf-8') as tgt:
#     src.writelines(list_src)
#     tgt.writelines(list_tgt)
#     print(f"{src_lan}:{len(list_src)}\n{tgt_lan}:{len(list_tgt)}")

import re


mode=['train','valid','test'][1]
# zh_CN, de_DE, fi_FI, es_XX, ru_RU, hi_IN
src_lan='gu_IN'
tgt_lan='en_XX'
src='gu'
year='19'
dir_path=f'D:\\datasets\\newsdev{year}\\'
# dir_path='D:\\datasets\\newsdev14\\enhi_v1\\'

src_path=dir_path+f'newsdev20{year}-{src}en-src.{src}.sgm'
tgt_path=dir_path+f'newsdev20{year}-{src}en-ref.en.sgm'
pattern = r"<seg id=\"\d+\">(.*)<\/seg>"
with open(src_path, 'r', encoding='utf-8') as src, \
    open(tgt_path, 'r', encoding='utf-8') as tgt:
    with open(f'./{mode}.{src_lan}-{tgt_lan}.{src_lan}', 'w', encoding='utf-8') as src_w,\
    open(f'./{mode}.{src_lan}-{tgt_lan}.{tgt_lan}', 'w', encoding='utf-8') as tgt_w:
        print(f"Process {src_lan}")
        count_src=0
        count_tgt=0
        for line in src:
            sent=re.search(pattern, line)
            if sent:
                src_w.write(sent.group(1)+'\n')
                count_src+=1
        print(f"Process {tgt_lan}")
        for line in tgt:
            sent=re.search(pattern, line)
            if sent:
                tgt_w.write(sent.group(1)+'\n')
                count_tgt+=1
        print(f"{src_lan}:{count_src}\n{tgt_lan}:{count_tgt}")








