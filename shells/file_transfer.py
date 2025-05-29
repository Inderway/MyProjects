# Feb 26, 2025
# 将同一目录不同文件夹下的文件批量转移到同一文件夹
# 注意目标文件夹不要在处理目录之内

import os

dir_path=r'E:\download\download\download'.replace('\\','/')+'/'

target_path = r'E:\download\download\beautyleg'.replace('\\','/')+'/'

file_dirs=[]

for root, dirs, files in os.walk(dir_path):
    file_dirs = dirs
    break

idx = 1
for dir in file_dirs:
    for file in os.listdir(dir_path+dir):
        if not os.path.exists(target_path+file):
            os.rename(dir_path+dir+'/'+file,target_path+file)
        else:
            file_split = file.split('.')
            file_name = file_split[0]
            file_affix = file_split[-1]
            os.rename(dir_path+dir+'/'+file,target_path+file_name+str(idx)+file_affix)
            idx+=1