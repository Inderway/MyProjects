# For removing the extra spaces in the text
# created by chatgpt
# Mar 20, 2023

file_path='D:/documents/___Project___/Dongba/dataset/para/text_d/jlz_'

for i in range(3,22):
    file=file_path+str(i)+'.txt'
    with open(file, 'r', encoding='utf-8') as f:
        text = f.read()
        text = ' '.join(text.split())

    with open(file, 'w', encoding='utf-8') as f:
        f.write(text)

    