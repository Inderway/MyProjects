# For naming the files on Iwara, Exhentai, pmv
# created by wei
# Dec 26, 2022


format=int(input("命名规范:\n 1. Iwara\n 2. Enhentai\n 3. PMV\n"))
_flag=1
chara=''
artist=''
song=''
while _flag!=0:
    if(format==1):
        print("Iwara: [角色][作者]曲名.mp4")
        chara=input("出场角色: ")
        chara='['+chara+']'
        if(_flag!=2):
            artist=input("作者: ")
            artist='['+artist+']'
            if artist is None:
                artist=""
        song=input("曲名: ")
        if song is None:
            song=""            
        print("-------文件名-------\n%s%s%s.mp4\n------------------"%(chara, artist, song))
        _flag=int(input("继续? 0. 取消 1. 确定 2. 同作者模式\n"))

