# Jan 6, 2022
# for catching pictures of ROSI
# -*- coding=utf8 -*-


from urllib import request, parse
import re
from selenium import webdriver
import time

class ROSIpics:
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
        p=r'<a>共(\d+)页: </a>'
        pages=int(re.findall(p,self.html)[0])
        count=1
        #print(self.html)
        for i in range(pages):
            #match images
            p=r'<img class="img-responsive" src="([^"]+\.jpg)"'
            imglist=re.findall(p,self.html)
            #print(imglist)
            if(len(imglist)==0 and i!=pages-1):
                p=r'<img src=\'([^\']+\.jpg)\' alt='
                imglist=re.findall(p,self.html)
            if(len(imglist)==0 and i!=pages-1):
                p=r'src="([^"]+\.jpg)" style='
                imglist=re.findall(p,self.html)
            if(len(imglist)==0 and i!=pages-1):
                p=r'border="0" src="([^"]+\.jpg)" />'
                imglist=re.findall(p,self.html)
            if(len(imglist)==0 and i!=pages-1):
                break
            for each in imglist:
                filename=each.split("/")[-1]
                photo=request.urlopen("http://www.rosimm3.com"+each)
                w=photo.read()
                # image address
                f=open("E:\download\image8\\"+str(count)+filename,'wb')
                f.write(w)
                f.close()
                print(count)
                count+=1
                time.sleep(1)
            if(i==pages-1):
                break
            #get url of next page
            time.sleep(1)
            p=r'<a href=\'([^\']+\.html)\'>下一页</a>'
            next_url="http://www.rosimm3.com/disi_mm/"+re.findall(p, self.html)[0]
            print(next_url)
            self.open_url(next_url)
            


def main():
    index_url="http://www.rosimm3.com/disi_mm/list_7_1.html"
    rosi=ROSIpics(index_url)
    rosi.open_url(index_url)
    time.sleep(1)
    p=r'<a href="([^"]+\.html)">'
    urls=re.findall(p, rosi.html)
    length=len(urls)
    for i in range(0,length):
        print("now i is %d"%(i))
        url="http://www.rosimm3.com"+urls[i]
        rosipic=ROSIpics(url)
        rosipic.get_img()
        time.sleep(1)

    #rosipic=ROSIpics("http://www.rosimm3.com/disi_mm/1491.html")
    #rosipic.get_img()

if __name__=='__main__':
    main()
    

