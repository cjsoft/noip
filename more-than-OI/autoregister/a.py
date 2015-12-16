# coding=utf-8
def proce(resStr):
    print resStr
    a = ''
    b = ''
    tag = 0
    for i in resStr:
        print a, b
        if i in ['0','1','2','3','4','5','6','7','8','9']:
            if tag == 0:
                a = a + i
            elif tag == 1:
                b = b + i
        if i  in ['+','f','\'']:
            tag = 1
            continue
        if (i == '=' or len(b) >= 2):
            break
    return int(a) + int(b)
try:
    import Image
except ImportError:
    from PIL import Image
import pytesseract
print pytesseract.image_to_string(Image.open('test.png'))
print proce('i5+8')
print proce(pytesseract.image_to_string(Image.open('test.png')))
import sys
sys.exit(0)
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
a = soup.find('form', id='student_email').find('img', title = '看不清，点击换一张')
img_url = STP + a['src']
resp = opener.open(img_url)
f = open('test.png', 'wb')
f.write(resp.read())
f.close()
import time
time.sleep(0.5)
