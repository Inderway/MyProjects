# for processing the data in excel and calculate spearman correlation
# created by wei
# April 13, 2024
import pandas as pd
from scipy.stats import spearmanr

path="D:\\documents\\毕业\\"
file_name="experiment-3.xlsx"
new_file_name="experiment-3-new.xlsx"

distance_types=['eling','l2v_syn','l2v_pho','l2v_inv','l2v_fea','xlmr','chatgpt']
# 'ar_AR','cs_CZ','et_EE','fr_XX','gu_IN','it_IT','ja_XX','kk_KZ','ko_KR','lt_LT','lv_LV' ,'my_MM','ne_NP','nl_XX','ro_RO','si_LK','tr_TR','vi_VN'


df=pd.read_excel(path+file_name,header=None)
distances=[]
# for i in range(18):
#     distances.append(df.values[i*10+3:i*10+9,1])
#     distances.append(df.values[i*10+3:i*10+9,2])
#     distances.append(df.values[i*10+3:i*10+9,3])
#     distances.append(df.values[i*10+3:i*10+9,4])
#     distances.append(df.values[i*10+3:i*10+9,5])
#     distances.append(df.values[i*10+3:i*10+9,6])
#     distances.append(df.values[i*10+3:i*10+9,7])
#     result=df.values[i*10+3:i*10+9,8]
#     for j in range(7):
#         rho,p=spearmanr(distances[j],result)
#         df.values[i*10+9,j+1]=rho


# writer=pd.ExcelWriter(path+new_file_name)
# #使用to_excel将之前读取的工作簿中工作表的数据写入到新建的工作簿的工作表中
# df.to_excel(writer)
# #保存并且关闭工作簿
# writer.save()

# 计算平均值
# sum=[0]*7
# for i in range(2):
#     for j in range(7):
#         if j==4:
#             if(df.values[i*10+9,j+1]=='/'):
#                 continue
#             else:
#                 sum[j]+=float(df.values[i*10+9,j+1])
#         else:
#             sum[j]+=float(df.values[i*10+9,j+1])
# for j in range(7):
#     if(j==4):
#         print(sum[j]/15)
#     else:
#         print(sum[j]/18)

# 生成tex表格格式

for i in range(2,9):
    for j in range(10,29):
        print('\\underline{'+str(df.values[i,j])+'}',end=' & ')
    print('\\\\')


