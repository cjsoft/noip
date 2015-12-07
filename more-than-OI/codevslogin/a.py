#coding=utf-8
import urllib2, cookielib
from urllib import urlencode
import sys, re, os
from bs4 import BeautifulSoup
reload(sys)
sys.setdefaultencoding('utf-8')
last_red = ''
DMN = 'http://codevs.cn'
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
r3 = re.compile(r'/(\d{4})/')
r4 = {
    'AC':re.compile(r'\'AC\', data: (\d*) '),
    'WA':re.compile(r'\'WA\', data: (\d*) '),
    'TLE':re.compile(r'\'TLE\', data: (\d*) '),
    'MLE':re.compile(r'\'MLE\', data: (\d*) '),
    'RE':re.compile(r'\'RE\', data: (\d*) ')
}
r5 = re.compile(r'题目等级 :   (青铜|白银|黄金|钻石|大师) ')
r6 = re.compile(r'时间限制: (\d{1,2}) s')
r7 = re.compile(r'空间限制: (\d{1,7}) KB')
cookie = cookielib.CookieJar()
handler = urllib2.HTTPCookieProcessor(cookie)
opener = urllib2.build_opener(handler)#, urllib2.ProxyHandler({'http':'http://192.168.0.201:808'}))
def getUnRedirectUrl(url,timeout=10):
    global handler
    req = urllib2.Request(url)
    debug_handler = urllib2.HTTPHandler()
    opener = urllib2.build_opener(debug_handler, RedirectHandler, handler)#, urllib2.ProxyHandler({'http':'http://192.168.0.201:808'}))
    
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

values = {
'username':'cjsoft',
'password':'safsdf',
'csrfmiddlewaretoken':s,
'next':'',
}
def make_cookie(name, value, dimain):
    return cookielib.Cookie(
        version=0,
        name=name,
        value=value,
        port=None,
        port_specified=False,
        domain=dimain,
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
    # print r.findall(a)[0]
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
# print cookie
# login
req = urllib2.Request(url, postdata, headers)
# resp = opener.open(req)
locate('http://codevs.cn/accounts/')
a=locate('http://account.codevs.com/user/token/?next=http://codevs.cn/accounts/token/login/').read()
# print a
# resp = opener.open('http://codevs.cn/accounts/')
# resp = opener.open('http://account.codevs.com/user/token/?next=http://codevs.cn/accounts/token/login/')
# f.write(a)
# csrf(a)
# print cookie
def fetch(link, path, codeid):
    try:
        print link, path, codeid
        resp = locate(link)
        if (str(resp).find('题目审核未通过或正在审核中') != -1):
            return
        # if int(codeid) == 1030:
        #     f=open('D:\\a.txt','w')
        #     f.write(str(resp))
        #     f.close()
        resp = resp.replace('<br>', 'fnadjsihfinadsiufhasdubfueabfuwebeu')
        soup =BeautifulSoup(resp, 'html.parser', from_encoding = 'utf-8')
        pinfo = soup.find('div', class_='col-lg-9 no-padder ').find_all('div',class_='panel panel-default')
        f = open(path + '\\%s.md'%codeid, 'w')
        n1 = soup.find('h3', class_='m-t m-b-sm', style='display:inline-block').get_text() # class="m-t m-b-sm" style="display:inline-block"
        # print r6.findall(resp)[0],r7.findall(resp)[0],r5.findall(resp)[0]
        f.write('#%s  \n'%n1)
        f.write('### 时间限制： %s s&nbsp;&nbsp;&nbsp;&nbsp;空间限制： %s KB&nbsp;&nbsp;&nbsp;&nbsp;题目等级： %s  \n'%(
            r6.findall(resp)[0],
            r7.findall(resp)[0],
            r5.findall(resp)[0]
            ))
        # print pinfo
        # for i in pinfo:
        #     print i, '\n'
        f.write('## 题目描述：  \n\n<pre>%s</pre>\n  \n  \n'%pinfo[0].find('div',class_='panel-body').get_text().replace('fnadjsihfinadsiufhasdubfueabfuwebeu','  \n'))
        f.write('## 输入描述：  \n\n<pre>%s</pre>\n  \n  \n'%pinfo[1].find('div',class_='panel-body').get_text().replace('fnadjsihfinadsiufhasdubfueabfuwebeu','  \n'))
        f.write('## 输出描述：  \n\n<pre>%s</pre>\n  \n  \n'%pinfo[2].find('div',class_='panel-body').get_text().replace('fnadjsihfinadsiufhasdubfueabfuwebeu','  \n'))
        f.write('## 样例输入：  \n\n<pre>%s</pre>\n  \n  \n'%pinfo[3].find('div',class_='panel-body').get_text().replace('fnadjsihfinadsiufhasdubfueabfuwebeu','  \n'))
        f.write('## 样例输出：  \n\n<pre>%s</pre>\n  \n  \n'%pinfo[4].find('div',class_='panel-body').get_text().replace('fnadjsihfinadsiufhasdubfueabfuwebeu','  \n'))
        f.write('## 数据范围及提示：  \n\n<pre>%s</pre>\n  \n  \n'%pinfo[5].find('div',class_='panel-body').get_text().replace('fnadjsihfinadsiufhasdubfueabfuwebeu','  \n'))
        f.write('***  \n\n##### AC: %s  \n'%r4['AC'].findall(resp)[0])
        f.write('##### WA: %s  \n'%r4['WA'].findall(resp)[0])
        f.write('##### TLE: %s  \n'%r4['TLE'].findall(resp)[0])
        f.write('##### MLE: %s  \n'%r4['MLE'].findall(resp)[0])
        f.write('##### RE: %s  \n'%r4['RE'].findall(resp)[0])
        # print n
        f.close()
    except BaseException:
        pass

for i in xrange(0):
    resp = locate('http://codevs.cn/problem/?problemset_id=1&page=%s'%i)
    # print resp
    soup = BeautifulSoup(resp, 'html.parser', from_encoding = 'utf-8')
    sss = str(soup.find('tbody'))
    ssp = BeautifulSoup(sss, 'html.parser', from_encoding = 'utf-8')
    # print type(ssp)
    coll = ssp.find_all('a', class_ = 'pull-left', title= '')
    for j in coll:
        # print (j.string).encode('gb18030'), j['href']
        codeid = str(r3.findall(j['href'])[0])
        print codeid
        if (not os.path.exists('problems\\'+codeid)):
            os.makedirs(r'problems\\'+codeid)
        fetch(DMN + r'/problem/' + codeid + '/', 'problems\\'+codeid, codeid)
        print 'fetched', codeid
        # break
    # break
for codeid in xrange(1000, 5000):
    if (not os.path.exists('problems\\')):
        os.makedirs(r'problems\\')
    fetch(DMN + r'/problem/' + str(codeid) + '/', 'problems\\', str(codeid))
    print 'fetched', str(codeid)
