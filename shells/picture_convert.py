# For converting the format of pictures
# created by wei
# Aug 8, 2023

from PIL import Image
import os

# ！！！运行此脚本前按更改时间排序并重命名webp文件
# 重命名为1即可

# path='E:/philosophy/normal/'
path = 'E:/download/tmp/'
for pic in os.listdir(path):
    format=pic.split('.')[-1]
    if format=='webp':
        idx=pic.split('(')[-1].split(')')[0]
        if len(idx)<3:
            if len(idx)<2:
                idx='00'+idx
            else:
                idx='0'+idx
        os.rename(path+pic,path+'webp'+idx+'.webp')
for pic in os.listdir(path):
    format=pic.split('.')[-1]
    name=pic.split('.')[0]
    print(name)
    if format=='webp':
        idx=pic.split('(')[-1].split(')')[0]
        im = Image.open(path+pic).convert("RGB")
        im.save(f"{path}{name}.jpg", "jpeg")