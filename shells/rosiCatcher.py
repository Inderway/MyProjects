# Jan 6, 2022
# for catching pictures of ROSI
# -*- coding=utf8 -*-

from selenium import webdriver
import time 
import os 
import random
from urllib import request
import re

class ROSIpics:
    def __init__(self):
        path="E:\Program Files (x86)\chromedriver\chromedriver.exe"
        self.wb=webdriver.Chrome(executable_path=path)
        self.wb.get(
            "http://www.rosimm3.com/disi_mm/2862.html"
        )
        self.pics_url={}


    def getPages(self):
        page_text=self.wb.find_element_by_xpath(
            "/html/body/section/div/div/div[1]/li[1]/a").text
        self.page=int(page_text[1])

    def getPicURL(self):
        article_class=self.wb.find_element_by_xpath(
            "/html/body/section/div/div/article"
        ).text
        print(article_class)


def main():
    rosipic=ROSIpics()
    rosipic.getPages()
    rosipic.getPicURL()

if __name__=='__main__':
    main()
    

