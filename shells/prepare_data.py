# prepare the data: turn the raw data into json format
# created by wei
# April 13, 2023

import json
import os
from tqdm import tqdm

data=[]

def hasData(li):
    if 'source.txt' in li:
        return True
    else:
        return False

def visit(path):
    folder=os.listdir(path)
    if hasData(folder):
        with open(os.path.join(path, 'source.txt'), 'r', encoding='utf-8') as src:
            src_text=src.readlines()
        with open(os.path.join(path, 'target.txt'), 'r', encoding='utf-8') as tgt:
            tgt_text=tgt.readlines()
        for i in range(len(src_text)):
            data.append([src_text[i].rstrip('\n'),tgt_text[i].rstrip('\n')])
    else:
        for dir in folder:
            visit(os.path.join(path,dir))


def addData(path):
    with open(os.path.join(path, 'source.txt'), 'r', encoding='utf-8') as src:
        src_text=src.readlines()
    with open(os.path.join(path, 'target.txt'), 'r', encoding='utf-8') as tgt:
        tgt_text=tgt.readlines()
    for i in range(len(src_text)):
        data.append([src_text[i].rstrip('\n'),tgt_text[i].rstrip('\n')])

if __name__ =="__main__":
    dir_path=r'D:\download\Classical-Modern-main\Classical-Modern-main\azh_mzh_raw'
    data_path='./all.json'
    # get all sentences
    # with open(data_path, 'w', encoding='utf-8') as f:
    #     for document in tqdm(os.listdir(dir_path)):
    #         print(f"-----------{document}-----------")
    #         doc_path=os.path.join(dir_path, document)
    #         visit(doc_path)
    #     print(f'length: {len(data)}')
    #     json.dump(data, f, ensure_ascii=False) 

    # segment the dataset
    dataset=json.load(open(data_path, 'r'))
    with open('./train.json', 'w', encoding='utf-8') as f:
        json.dump(dataset[:-4000],f,ensure_ascii=False)
    with open('./valid.json', 'w', encoding='utf-8') as f:
        json.dump(dataset[-4000:-2000],f,ensure_ascii=False)
    with open('./test.json', 'w', encoding='utf-8') as f:
        json.dump(dataset[-2000:],f,ensure_ascii=False)