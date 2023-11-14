# For determining which object to be selected
# created by wei
# Sep 12, 2023
import random
import datetime

# self-made videos
with open('surfing_record.txt','a+') as rcd:
    rcd.seek(0) # Place the cursor at the beginning of the document
    indices=set(rcd.read().split())
    rcd.write(str(datetime.date.today())+' ')
    last=630
    nums=10
    while nums!=0:
        idx=random.randint(1,last)
        if str(idx) not in indices:
            print(idx)
            rcd.write(f'{idx} ')
            nums-=1    
    rcd.write(f'\n')