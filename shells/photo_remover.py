# Feb 26, 2025
# 按照JPG文件夹中经过筛选的照片，删除RAW格式照片

import os
from send2trash import send2trash # 将文件删除至回收站

date = '20250521'
jpg_path=f'D:\\photos\\tmp_jpg\\{date}\\'
raw_path = f'D:\\photos\\tmp_raw\\{date}\\'

jpg_files = []

for p in os.listdir(jpg_path):
    jpg_files.append(p.split('.')[0])
    
for p in os.listdir(raw_path):
    p_name = p.split('.')[0]
    print(p_name)
    if p_name not in jpg_files:
        send2trash(raw_path+p)