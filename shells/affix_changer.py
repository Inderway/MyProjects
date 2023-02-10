# Feb 9, 2023
# for changing the extension of the files

import os

dir_path='E:/download/X-GQMXXM-139/X-GQMXXM-139/'
for file in os.listdir(dir_path):
    src_name=file.split('.')[0]
    type=file.split('.')[1]
    dst_name=src_name+'.'+'7z'
    os.rename(dir_path+file,dir_path+dst_name)
    continue
        