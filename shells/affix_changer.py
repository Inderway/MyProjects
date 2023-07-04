# Feb 9, 2023
# for changing the extension of the files

import os

dir_path=r'e:\download\X-CZMJ-065\X-CZMJ-065'
dir_path=dir_path.replace('\\','/')+'/'
for file in os.listdir(dir_path):
    dst_name=file[0:-1]
    # src_name=file.split('.')[0]+'.'+file.split('.')[1]
    # type=file.split('.')[-1]
    # dst_name=src_name+'.'+'7z'
    os.rename(dir_path+file,dir_path+dst_name)
    
