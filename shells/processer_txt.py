# For testing codes
# created by wei
# Feb 26, 2023
from datetime import datetime

src_lan='de'
tgt_lan='en'

src_path=r'D:\documents\__study files master\深度自然语言处理前沿\datasets\train\news-commentary-v13.de-en.de'
tgt_path=r'D:\documents\__study files master\深度自然语言处理前沿\datasets\train\news-commentary-v13.de-en.en'

with open(src_path, 'r', encoding='utf-8') as src_file,\
    open(tgt_path, 'r', encoding='utf-8') as tgt_file:
    src_text=src_file.readlines()
    tgt_text=tgt_file.readlines()
    print(f"src_len:{len(src_text)} tgt_len:{len(tgt_text)}")

    # change the file name
    with open(f'train_{src_lan}{tgt_lan}.{src_lan}','w',encoding='utf-8') as src,\
    open(f'train_{src_lan}{tgt_lan}.{tgt_lan}','w',encoding='utf-8') as tgt:
        src.writelines(src_text)
        tgt.writelines(tgt_text)
    print(f"src_len:{len(src_text)} tgt_len:{len(tgt_text)}")