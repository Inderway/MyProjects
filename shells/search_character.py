# For searching needed character in a director
# created by wei
# Mar 30, 2023

import os

target_dir=r'D:\documents\___Project___\Dongba\dataset\para\text_l'
target='沟'

for file_name in os.listdir(target_dir):
    with open(os.path.join(target_dir, file_name), 'r', encoding='utf-8') as f:
        text=f.read()
        if target in text:
            print(file_name)

