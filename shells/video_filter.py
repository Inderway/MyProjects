# -*- coding=utf8 -*-
# Dec 2, 2024
# 用于筛选视频时记录空号


import json
import heapq as hq

# 读取可用编号

with open('video_filter.json', 'r', encoding='utf-8') as dictFile:
    dict = json.load(dictFile)
    numberHeap = dict["numbers"]
    # 小根堆化
    hq.heapify(numberHeap)
    while 1:
        s = input('--------输入需要存储的编号（q结束，p获取存储编号）\n')
        if s == 'q':
            break
        if s == 'p':
            if len(numberHeap)==0:
                print("列表为空！")
            else:
                print('--------弹出编号：'+str(hq.heappop(numberHeap)))
        else:
            if s.isdigit():
                hq.heappush(numberHeap,int(s))
            else:
                print("非法输入！")

with open('video_filter.json', 'w', encoding='utf-8') as dictFile:
    dict["numbers"] = numberHeap
    json.dump(dict, dictFile)
