# to parse the sgm file
# created by wei 
# April 24, 2023



import xml.etree.ElementTree as ET

def extract_seg_from_sgm(sgm_data):
    seg_contents = []
    # filter invalid tokens

    sgm_data=sgm_data.replace('&', '&amp;')
    
    root = ET.fromstring(sgm_data)

    for seg in root.iter('seg'):
        seg_contents.append(seg.text+'\n')

    return seg_contents

src_lan='de'
tgt_lan='en'
dir_path='D:\\documents\\__study files master\\深度自然语言处理前沿\\datasets\\valid\\'
src_path=dir_path+'newstest2014-deen-src.de.sgm'
tgt_path=dir_path+'newstest2014-deen-ref.en.sgm'
with open(src_path, 'r', encoding='utf-8') as src, \
    open(tgt_path, 'r', encoding='utf-8') as tgt:
    sgm_data = src.read()
    list_src = extract_seg_from_sgm(sgm_data)
    sgm_data = tgt.read()
    list_tgt = extract_seg_from_sgm(sgm_data)

with open(f'./valid.{src_lan}-{tgt_lan}.{src_lan}', 'w', encoding='utf-8') as src,\
    open(f'./valid.{src_lan}-{tgt_lan}.{tgt_lan}', 'w', encoding='utf-8') as tgt:
    src.writelines(list_src)
    tgt.writelines(list_tgt)
    print(f"{src_lan}:{len(list_src)}\n{tgt_lan}:{len(list_tgt)}")




