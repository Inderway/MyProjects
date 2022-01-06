# -*- coding:utf-8 -*-
import unittest
from selenium import webdriver
import time
import random
import string
from selenium.webdriver.common.by import By

# # create a new Chrome session
# driver = webdriver.Chrome(executable_path="C:\Program Files (x86)\Google\Chrome\Application\chromedriver.exe")
# driver.implicitly_wait(10)  # 设置超时时间
# driver.maximize_window()  # 窗口最大化显示
#
# #  navigate to the application home page
# #访问应用网页
# driver.get("http://www.baidu.com/")
#
# # get the search textbox
#
# search_field = driver.find_element_by_id("kw")  # 定位搜索输入框，该方法会返回第一个id属性值与输入参数匹配的元素
# search_field.clear()  # 清空当前输入内容
#
# # enter search keyword and submit
#
# search_field.send_keys("测试")  # 重新这是搜索关键字
# search_field.submit()  # 提交进行搜索
#
# # get all the anchor elements which have product names displayed
# #  currently on result page using find_ elements_ by_ xpath method
# #获取路径满足class='c-abstract'的所有div标签，它将返回多于一个的元素列表
# products = driver.find_elements_by_xpath("//div[contains(@class, 'c-abstract')]")
#
# # get the number of anchor elements found
#
# print("Found " + str(len(products)) + "products:")
#
# # iterate through each anchor element and print the text that is
# #  name of the product
#
# for product in products:
#     print(product.text)
#
# #  close the browser window
#
# driver.quit()

class Test(unittest.TestCase):
    driver = None

    @classmethod
    def setUpClass(cls):
        cls.driver = webdriver.Chrome(executable_path="C:\Program Files (x86)\Google\Chrome\Application\chromedriver.exe")
        cls.driver.implicitly_wait(3)
        #cls.driver.maximize_window()
        cls.driver.get("http://127.0.0.1:8089")

    def login(self,un,pw):
        self.driver.find_element_by_link_text('登录').click()
        get_username = self.driver.find_element_by_xpath('//*[@id="username"]')
        get_username.clear()
        get_username.send_keys(un)
        get_pw = self.driver.find_element_by_xpath('//*[@id="password"]')
        get_pw.clear()
        get_pw.send_keys(pw)
        self.driver.find_element_by_xpath('//*[@id="login"]').click()
        time.sleep(1)

    def register(self,username='test',password='123',confirm_password='123'):
        self.driver.find_element_by_link_text('注册').click()
        time.sleep(1)
        un = self.driver.find_element_by_xpath('// *[ @ id = "username"]')
        un.clear()
        un.send_keys(username)
        pw1 = self.driver.find_element_by_xpath('//*[@id="password"]')
        pw1.clear()
        pw = self.generate_random_str(8)
        pw1.send_keys(password)
        pw2 = self.driver.find_element_by_xpath('//*[@id="confirm_password"]')
        pw2.clear()
        pw2.send_keys(confirm_password)

    def send_and_check_mail(self,code):
        em = self.driver.find_element_by_xpath('//*[@id="email"]')
        em.clear()
        email = self.generate_random_str(8)+ '@q.com'
        em.send_keys(email)
        send=self.driver.find_element_by_xpath('//*[@id="send_mail"]')
        send.click()
        send.click()
        time.sleep(5)
        vc = self.driver.find_element_by_xpath('//*[@id="check_code"]')
        vc.send_keys(code)
        time.sleep(0.5)
        tel=self.driver.find_element_by_xpath('//*[@id="phoneNumber"]')
        tel.clear()
        tel.send_keys('8848')



    def logout(self):
        self.driver.find_element_by_link_text('退出').click()

    def generate_random_str(self,randomlength=16):
        """
        生成一个指定长度的随机字符串，其中
        string.digits=0123456789
        string.ascii_letters=abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
        """
        str_list = [random.choice(string.digits + string.ascii_letters) for i in range(randomlength)]
        random_str = ''.join(str_list)
        return random_str


    def test_login_0001(self):
        self.login('yin','123')
        time.sleep(1)
        title=self.driver.title
        self.assertEqual(title,'主页','未进入主页！')


    def test_login_0002(self):
        self.logout()
        self.login('none','')
        msg=self.driver.find_element_by_xpath('//*[@id="message"]').text
        self.assertEqual(msg,'用户名或密码为空！','提示消息错误！')

    def test_login_0003(self):
        self.login('none','none')
        msg=self.driver.find_element_by_xpath('//*[@id="message"]').text
        self.assertEqual(msg,'用户不存在！','提示消息错误！')

    def test_login_0004(self):
        self.login('yin', '')
        msg = self.driver.find_element_by_xpath('//*[@id="message"]').text
        self.assertEqual(msg, '用户名或密码为空！', '提示消息错误！')

    def test_login_0005(self):
        self.login('yin', 'none')
        msg = self.driver.find_element_by_xpath('//*[@id="message"]').text
        self.assertEqual(msg, '用户名或密码错误！', '提示消息错误！')

    def test_login_0006(self):
        self.login('', '')
        msg = self.driver.find_element_by_xpath('//*[@id="message"]').text
        self.assertEqual(msg, '用户名或密码为空！', '提示消息错误！')

    def test_login_0007(self):
        self.login('', 'none')
        msg = self.driver.find_element_by_xpath('//*[@id="message"]').text
        self.assertEqual(msg, '用户名或密码为空！', '提示消息错误！')

    def test_login_0008(self):
        self.login('admin','admin')
        title=self.driver.title
        self.assertEqual(title,'管理员','未进入管理员界面！')
        self.driver.find_element_by_link_text('退出登录').click()

    def test_sendMail_0002(self):
        self.register()
        self.driver.find_element_by_xpath('//*[@id="send_mail"]').click()
        time.sleep(0.5)
        msg = self.driver.find_element_by_xpath('//*[@id="message"]').text
        self.assertEqual(msg, '好像有些错误..邮件没有发出去..', '提示消息错误！')

    def test_sendMail_0003(self):
        self.register()
        em = self.driver.find_element_by_xpath('//*[@id="email"]')
        em.clear()
        em.send_keys('none')
        self.driver.find_element_by_xpath('//*[@id="send_mail"]').click()
        time.sleep(0.5)
        msg = self.driver.find_element_by_xpath('//*[@id="message"]').text
        self.assertEqual(msg, '好像有些错误..邮件没有发出去..', '提示消息错误！')

    def test_sendMail_0004(self):
        self.register()
        em = self.driver.find_element_by_xpath('//*[@id="email"]')
        em.clear()
        em.send_keys('1040214708@qq.com')
        self.driver.find_element_by_xpath('//*[@id="send_mail"]').click()
        time.sleep(0.5)
        msg = self.driver.find_element_by_xpath('//*[@id="message"]').text
        self.assertEqual(msg, '邮箱已注册', '提示消息错误！')

    def test_checkMail_0001(self):
        self.register()
        self.send_and_check_mail('test')
        re_bt=self.driver.find_element_by_xpath('//*[@id="register"]')
        time.sleep(5)
        self.assertTrue(re_bt.is_enabled(),'不能正常注册！')

    def test_checkMail_0002(self):
        self.register()
        self.send_and_check_mail('tesf')
        re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
        self.assertFalse(re_bt.is_enabled(),'非法注册！')

    def test_checkMail_0003(self):
        self.register()
        self.send_and_check_mail('')
        re_bt=self.driver.find_element_by_xpath('//*[@id="register"]')
        self.assertFalse(re_bt.is_enabled(),'非法注册！')

    def test_register_0001(self):
        un=self.generate_random_str(8)
        pw1=self.generate_random_str(8)
        pw2=pw1
        self.register(un,pw1,pw2)
        self.send_and_check_mail('test')
        time.sleep(2)
        re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
        self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
        re_bt.click()
        time.sleep(1)
        title=self.driver.title
        self.assertEqual(title,'登录','未成功注册！')

    # def test_register_0002(self):
    #     un=''
    #     pw1=self.generate_random_str(8)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     try:
    #         msg=self.driver.find_element_by_xpath('//*[@id="message"]')
    #     except:
    #         self.assertTrue(False,'无提示消息！')
    #     title=self.driver.title
    #     self.assertEqual(title,'注册','非法注册！')
    #
    # def test_register_0003(self):
    #     un=self.generate_random_str(129)
    #     pw1=self.generate_random_str(8)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     try:
    #         msg=self.driver.find_element_by_xpath('//*[@id="message"]')
    #     except:
    #         self.assertTrue(False,'无提示消息！')
    #     title=self.driver.title
    #     self.assertEqual(title,'注册','非法注册！')
    #
    # def test_register_0004(self):
    #     un=self.generate_random_str(1)
    #     pw1=self.generate_random_str(8)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     title=self.driver.title
    #     self.assertEqual(title,'登录','未完成注册！')
    #
    # def test_register_0005(self):
    #     un=self.generate_random_str(2)
    #     pw1=self.generate_random_str(8)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     title=self.driver.title
    #     self.assertEqual(title,'登录','未完成注册！')
    #
    # def test_register_0006(self):
    #     un=self.generate_random_str(128)
    #     pw1=self.generate_random_str(8)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     title=self.driver.title
    #     self.assertEqual(title,'登录','未完成注册！')
    #
    # def test_register_0007(self):
    #     un=self.generate_random_str(127)
    #     pw1=self.generate_random_str(8)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     title=self.driver.title
    #     self.assertEqual(title,'登录','未完成注册！')
    #
    # def test_register_0008(self):
    #     un=self.generate_random_str(8)
    #     pw1=self.generate_random_str(8)
    #     pw2=self.generate_random_str(8)
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     try:
    #         msg=self.driver.find_element_by_xpath('//*[@id="message"]').text
    #     except:
    #         self.assertTrue(False,'无提示消息！')
    #     else:
    #         self.assertEqual(msg,'两次密码','提示消息错误！')
    #     title=self.driver.title
    #     self.assertEqual(title,'注册','非法注册！')
    #
    # def test_register_0009(self):
    #     un=self.generate_random_str(8)
    #     pw1=''
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     try:
    #         msg=self.driver.find_element_by_xpath('//*[@id="message"]').text
    #     except:
    #         self.assertTrue(False,'无提示消息！')
    #     title=self.driver.title
    #     self.assertEqual(title,'注册','非法注册！')
    #
    # def test_register_0010(self):
    #     un=self.generate_random_str(8)
    #     pw1=self.generate_random_str(257)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     try:
    #         msg=self.driver.find_element_by_xpath('//*[@id="message"]').text
    #     except:
    #         self.assertTrue(False,'无提示消息！')
    #     title=self.driver.title
    #     self.assertEqual(title,'注册','非法注册！')
    #
    # def test_register_0011(self):
    #     un=self.generate_random_str(8)
    #     pw1=self.generate_random_str(1)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     title = self.driver.title
    #     self.assertEqual(title,'登录','未完成注册！')
    #
    # def test_register_0012(self):
    #     un=self.generate_random_str(8)
    #     pw1=self.generate_random_str(2)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     title = self.driver.title
    #     self.assertEqual(title,'登录','未完成注册！')
    #
    # def test_register_0013(self):
    #     un=self.generate_random_str(8)
    #     pw1=self.generate_random_str(255)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     title = self.driver.title
    #     self.assertEqual(title,'登录','未完成注册！')
    #
    # def test_register_0014(self):
    #     un=self.generate_random_str(8)
    #     pw1=self.generate_random_str(256)
    #     pw2=pw1
    #     self.register(un,pw1,pw2)
    #     self.send_and_check_mail('test')
    #     time.sleep(1)
    #     re_bt = self.driver.find_element_by_xpath('//*[@id="register"]')
    #     self.assertTrue(re_bt.is_enabled(), '不能正常注册！')
    #     re_bt.click()
    #     time.sleep(1)
    #     title = self.driver.title
    #     self.assertEqual(title,'登录','未完成注册！')



    @classmethod
    def tearDownClass(cls):
        cls.driver.quit()

if __name__=='__main__':
    unittest.main(verbosity=2)


