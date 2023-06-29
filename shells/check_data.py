# to check the parallel data
# created by wei 
# May 30, 2023

dir_path='D:\\documents\\__study files master\\深度自然语言处理前沿\\datasets\\train\\'
src_lan='ja'
src_path=dir_path+f'train.{src_lan}-en.{src_lan}'
tgt_path=dir_path+f'train.{src_lan}-en.en'
new_src_path=dir_path+f'n_train.{src_lan}-en.{src_lan}'
new_tgt_path=dir_path+f'n_train.{src_lan}-en.en'
empty_lines=[]

# check
with open(src_path, 'r', encoding='utf-8') as src, \
    open(tgt_path, 'r',encoding='utf-8') as tgt:
    src_lines=src.readlines()
    tgt_lines=tgt.readlines()
    src_empty_count=0
    tgt_empty_count=0
    for i in range(len(src_lines)):
        flag= (len(src_lines[i].strip())==0) | ((len(tgt_lines[i].strip())==0)*2)
        if flag==3:
            src_empty_count+=1
            tgt_empty_count+=1
            empty_lines.append(i)
            # print(f"---------src & tgt empty line:{i+1} empty_count:{src_empty_count}, {tgt_empty_count}")
            # for j in range(i-1,i+2):
            #     print(src_lines[j].strip())
            #     print(tgt_lines[j].strip())
        if flag==1:  
            src_empty_count+=1
            empty_lines.append(i)
            print(f">>>------src empty line:{i+1} empty_count:{src_empty_count}")
            for j in range(i-1,i+2):
                print(src_lines[j].strip())
                print(tgt_lines[j].strip())
        if flag==2:
            tgt_empty_count+=1
            empty_lines.append(i)
            print(f"<<<------tgt empty line:{i+1} empty_count:{tgt_empty_count}")
            for j in range(i-1,i+2):
                print(src_lines[j].strip())
                print(tgt_lines[j].strip())

    # modify
    if len(empty_lines)>0:
        src_new=[ele for i,ele in enumerate(src_lines) if i not in empty_lines]
        tgt_new=[ele for i,ele in enumerate(tgt_lines) if i not in empty_lines]

        with open(new_src_path, 'w', encoding='utf-8') as n_src, \
            open(new_tgt_path, 'w',encoding='utf-8') as n_tgt:
            n_src.writelines(src_new)
            n_tgt.writelines(tgt_new)
        print(f'{len(empty_lines)} have(has) been discarded\n src:{len(src_new)} tgt:{len(tgt_new)}')

