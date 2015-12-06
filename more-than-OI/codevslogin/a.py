#coding=utf-8
import urllib2, cookielib
from urllib import urlencode
import sys, re
reload(sys)
sys.setdefaultencoding('utf-8')
last_red = ''
class RedirectHandler(urllib2.HTTPRedirectHandler):
    def http_error_301(self, req, fp, code, msg, headers):
        global last_red
        last_red = r2.findall(str(headers))[0]
        # print headers
    def http_error_302(self, req, fp, code, msg, headers):
        global last_red
        # print str(headers)
        last_red = r2.findall(str(headers))[0]
        # print last_red
        # print headers
r = re.compile(r"csrfmiddlewaretoken: '([a-zA-Z0-9]*)'")
r2 = re.compile(r'Location: (http://[a-zA-Z\.0-9/\-\?\&\+\=]*)')
cookie = cookielib.CookieJar()
handler = urllib2.HTTPCookieProcessor(cookie)
opener = urllib2.build_opener(handler)
opener.open('http://www.baidu.com')
def getUnRedirectUrl(url,timeout=10):
    global handler
    req = urllib2.Request(url)
    debug_handler = urllib2.HTTPHandler()
    opener = urllib2.build_opener(debug_handler, RedirectHandler, handler)
    
    html = None
    response = None
    try:
        response = opener.open(url,timeout=timeout)
        html = response.read()
    except urllib2.URLError as e:
        if hasattr(e, 'code'):
            error_info = e.code
        elif hasattr(e, 'reason'):
            error_info = e.reason
        # print '\n\n\n\n\n'
        # print e
    finally:
        if response:
            response.close()
    if html:
        return html
    else:
        return error_info
opener = urllib2.build_opener(handler)
url = r'http://account.codevs.com/api/user/login/'
user_agent = 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.86 Safari/537.36'
headers = { 
'User-Agent' : user_agent,
'Referer':'http://account.codevs.com/user/login/',
'Connection':'keep-alive'#,
# 'Host':'account.codevs.com',
# 'Origin':'http://account.codevs.com',
# 'Content-Type':'application/x-www-form-urlencoded; charset=UTF-8',
# 'Accept':r'*/*'
}
resp = opener.open('http://account.codevs.com/user/login/')
# print resp.headers
for j in cookie:
    s = j.value

print s
values = {
'username':'cjsoft',
'password':'sadwqre',
'csrfmiddlewaretoken':s,
'next':'',
}
def make_cookie(name, value):
    return cookielib.Cookie(
        version=0,
        name=name,
        value=value,
        port=None,
        port_specified=False,
        domain="account.codevs.com",
        domain_specified=True,
        domain_initial_dot=False,
        path="/",
        path_specified=True,
        secure=False,
        expires=None,
        discard=False,
        comment=None,
        # comment_url=None,
        rest=None
    )
def csrf(a):
    global cookie
    print r.findall(a)[0]
    cookie.set_cookie(make_cookie('csrftoken',r.findall(a)[0]))
def locate(a):
    global last_red, opener
    s = getUnRedirectUrl(a)
    tsu = last_red
    last_red = ''
    if (len(tsu)>0):
        return opener.open(tsu)
    else:
        return s
    # print last_red,'sad'
    # print r2.findall(str(getUnRedirectUrl(a)))
postdata = urlencode(values)
print cookie
# login
req = urllib2.Request(url, postdata, headers)
resp = opener.open(req)
locate('http://codevs.cn/accounts/')
a=locate('http://account.codevs.com/user/token/?next=http://codevs.cn/accounts/token/login/').read()
# print a
# resp = opener.open('http://codevs.cn/accounts/')
# resp = opener.open('http://account.codevs.com/user/token/?next=http://codevs.cn/accounts/token/login/')
f= open('adsf.txt', 'w')
# f.write(a)
# csrf(a)
# print cookie

resp = locate('http://codevs.cn/submission/?ismine=1')
f.write(resp)
f.close()
