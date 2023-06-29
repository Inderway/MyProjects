# For creating multiple files
# created by wei
# Mar 27, 2023

import os

document='jspzy_'
ltr_path=r'D:\documents\___Project___\Dongba\dataset\para\text_l'
fre_path=r'D:\documents\___Project___\Dongba\dataset\para\text_f'

for i in range(1, 13):
    id= '0'+str(i) if i<10 else str(i)
    filename=document+id+'.txt'
    open(os.path.join(ltr_path,filename),'w')
    open(os.path.join(fre_path,filename),'w')
