# July 8, 2021
# for renaming the names of pictures
# -*- coding=utf8 -*-
import os

#ir_path='H:/Philosophy/comic/CGs/CG33/'
dir_path='H:/Philosophy/pic/126/'
#dir_path='H:/Philosophy/comic/CGs/CG25/'
#dir_path='F:/philosophy/temp/[kurokoshi you]らぶぱい 私のおっぱい好きですか/'
# for i in range(10,11):
#     affix=str(i)+'/'
#     dir_path=path+affix
#     print(i)
for pic in os.listdir(dir_path):
    src_name=pic.split('.')[0]
    type=pic.split('.')[1]
    index=(src_name.split('(')[1]).split(')')[0]
    # jpeg和jpg被系统归为一类，此处分开计数
    if type=='jpeg':
        if len(index)<3:
            index='0'*(3-len(index))+index
        dst_name=src_name.split('(')[0]+'(j'+index+').'+type
        os.rename(dir_path+pic,dir_path+dst_name)
        continue
    # print('>>>>>>>>>>>')
    # print(index)
    if len(index)<3:
        index='0'*(3-len(index))+index
        dst_name=src_name.split('(')[0]+'('+index+').'+type
        os.rename(dir_path+pic,dir_path+dst_name)