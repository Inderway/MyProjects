# Oct 17, 2023
# for renaming the names of pictures
# 由于文件夹下的图片重名导致阅览时另存为冲突，故重命名
# -*- coding=utf8 -*-
import os

count=0

def visit(path:str):
    global count
    if os.path.isfile(path):
        os.rename(path, '.'.join(path.split('.')[:-1])+str(count)+'.'+path.split('.')[-1])
        count+=1
    else:
        for subpath in os.listdir(path):
            visit(path+'/'+subpath)
    
dir_path='D:\\download\\__未阅待同步\\xiaoze\\小泽\\小泽\\xiaoze(新白莉)'
visit(dir_path)

