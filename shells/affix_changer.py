# Feb 9, 2023
# for changing the extension of the files
# 文件格式改为7z格式用于解压

import os

# 文件夹内所有文件重名为7z格式

dir_path=r'E:\download\download'
dir_path=dir_path.replace('\\','/')+'/'
index=1
for file in os.listdir(dir_path):
    # src_name=file.split('.')[0]+'.'+file.split('.')[1]
    # type=file.split('.')[-1]
    # dst_name=src_name+'.'+'7z'
    if os.path.isfile(dir_path+file):
        os.rename(dir_path+file,dir_path+str(index)+'.7z')
        index+=1
    
