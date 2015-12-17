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
    return intha(a) + int(b)
import cookielib
import urllib, urllib2
from bs4 import BeautifulSoup as BS
cookie = cookielib.CookieJar()
hdl = urllib2.HTTPCookieProcessor()
opener = urllib2.build_opener(hdl, urllib2.ProxyHandler(dict()))
STP = 'http://n.eduyun.cn'
fst = 'http://n.eduyun.cn/index.php?r=portal/register/index'
resp = opener.open(fst)
res = resp.read()
soup = BS(res, 'html.parser')
a = soup.find('form', id='student_email').find('img', title = '看不清，点击换一张')
img_url = STP + a['src']
resp = opener.open(img_url, timeout = 5)
f = open('test.png', 'wb')
f.write(resp.read())
f.close()

vcode = int(raw_input('VCODE => '))
import random
pool = 'qwertyuiopasdfghjklzxcvbnm_'
pw = ''.join(random.sample(pool, 8))
value = {
    'username': ''.join(random.sample(pool, 8)),
    'password': pw,
    'passConfirm': pw,
    'realname': ''.join(random.sample('尊敬的发大水恭喜您注册成功现在可以登录了', 3)),
    'valCode': vcode,
    'type': '0_0',
    'hash': ''
}
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.73 Safari/537.36 OPR/34.0.2036.25',
    'Accept-Language': 'zh-CN,zh;q=0.8'
}
post_data = urllib.urlencode(value)
req = urllib2.Request(fst, post_data, headers = headers)
resp = opener.open(req)
print resp.read()