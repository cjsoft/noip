# coding=utf-8
import cookielib
import urllib, urllib2
from bs4 import BeautifulSoup as BS
cookie = cookielib.CookieJar()
hdl = urllib2.HTTPCookieProcessor()
opener = urllib2.build_opener(hdl)
STP = 'http://n.eduyun.cn'
fst = 'http://n.eduyun.cn/index.php?r=portal/register/index'
resp = opener.open(fst)
res = resp.read()
soup = BS(res, 'html.parser')
a = soup.find('img', title = '看不清，点击换一张')
img_url = STP + a['src']
resp = opener.open(img_url)
f = open('test.png', 'wb')
f.write(resp.read())
f.close()
