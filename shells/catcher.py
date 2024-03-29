# Jun 12, 2022
# for catching pictures from Internet
# -*- coding=utf8 -*-


from urllib import request
import re, time
import winsound

class Pics:
    def __init__(self, url):
        self.url=url

    def open_url(self, url):
        req=request.Request(url)#实例化Request对象
        #添加header
        req.add_header('User-Agent', "Mozilla/5.0 (Windows NT 10.0; Win64; x64) \
            AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.110 Safari/537.36")
        #visit url, move the web page's binary data to page
        page=request.urlopen(req)
        #turn content of page into utf-8
        self.html=page.read().decode('utf-8') 

    def get_img(self):
        self.open_url(self.url)
        #get pages
        p=r'>(\d+)</a>'
        pages=int(len(re.findall(p,self.html))/2)
        
        #print(self.html)
        idx="e"
        print("Pages: %d"%pages)
        # TODO 改index
        for i in range(18,pages):
            count=1
            print("---Page index:%d"%i)
            #match images
            p=r'title="[^"]+" src="([^"]+\.jpg)"'
            imglist=re.findall(p,self.html)
            #print(imglist)
            for each in imglist:
                filename=each.split("/")[-1].split(".")[0]
                photo=request.urlopen("https://www.jpxgyw.vip"+each)
                w=photo.read()
                # image address
                f=open("E:\download\image\\"+idx+str(count)+'_'+filename+".jpg",'wb')
                f.write(w)
                f.close()
                print("count: %d"%count)
                count+=1
                #time.sleep(1)
            if(i==pages-1):
                break
            #get url of next page
            time.sleep(1)
            p=r'<a href="([^"]+\.html)">下一页</a>'
            next_url="https://www.jpxgyw.vip/"+re.findall(p, self.html)[0]
            #print(next_url)
            self.open_url(next_url)
            


def main():
    index_url="https://www.xgmn.vip/Xiuren/Xiuren22775.html"
    print(index_url)
    catcher=Pics(index_url)
    catcher.open_url(index_url)
    # time.sleep(1)
    catcher.get_img()
    # 发出长达1s的提示音
    winsound.Beep(2000,1000)
if __name__=='__main__':
    main()
    

