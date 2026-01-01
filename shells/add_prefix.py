# Dec 21, 2025
# 给文件加文件夹前缀


import os

# 文件夹内所有文件重名为7z格式

dir_path=r'E:\download\__\Maplestar'
prefix = dir_path.split('\\')[-1]
dir_path = dir_path + '\\'
for file in os.listdir(dir_path):
    if os.path.isfile(dir_path+file):
        os.rename(dir_path+file,dir_path+f'[{prefix}] '+file)

    
