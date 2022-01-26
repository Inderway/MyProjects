# July 8, 2021
# for renaming the names of pictures
# -*- coding=utf8 -*-
import os

#dir_path='G:/Philosophy/pic/71/'
#dir_path='G:/Philosophy/pic/cos8/'
#dir_path='G:/Philosophy/comic/CGs/CG16/'
#dir_path='F:/philosophy/temp/'
dir_path='E:/download/image/'
# for i in range(10,11):
#     affix=str(i)+'/'
#     dir_path=path+affix
#     print(i)
for pic in os.listdir(dir_path):
    src_name=pic.split('.')[0]
    index=(src_name.split('(')[1]).split(')')[0]
    # print('>>>>>>>>>>>')
    # print(index)
    if len(index)<3:
        index='0'*(3-len(index))+index
        dst_name=src_name.split('(')[0]+'('+index+').'+pic.split('.')[1]
        os.rename(dir_path+pic,dir_path+dst_name)