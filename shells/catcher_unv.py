# Aug 8, 2022
# for catching resources from Internet(universal version)
# -*- coding=utf8 -*-

from urllib import request
import re, time

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
        pages=int(len(re.findall(p,self.html))/2)
        count=1
        #print(self.html)
        idx="n"
        print(pages)
        for i in range(pages):
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
                print(count)
                count+=1
                time.sleep(1)
            if(i==pages-1):
                break
            #get url of next page
            p=r'<a href="([^"]+\.html)">下一页</a>'
            next_url="https://www.jpxgyw.vip/"+re.findall(p, self.html)[0]
            #print(next_url)
            self.open_url(next_url)
            


def main():
    index_url="https://m.swifthart.com/gl/66614514.html"
    catcher=Pics(index_url)
    catcher.open_url(index_url)
    # time.sleep(1)
    catcher.get_img()

if __name__=='__main__':
    main()