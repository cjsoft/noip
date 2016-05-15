# coding=utf-8
import sys
import cookielib
import urllib, urllib2
reload(sys)
sys.setdefaultencoding('utf-8')
def cookiestring(a):
    s = ''
    ak = a.keys()
    for i in ak:
        s = s +'%s=%s; '%(i, a[i])
    return s
ld = ''
lstres = ''
fcnt = 0
hcnt = 0
class MyRedirectHandler(urllib2.HTTPRedirectHandler):
    def http_error_302(self, req, fp, code, msg, headers):
        # print str(headers)
        cookiemap = dict()
        setcookie = None
        try:
            setcookie = str(headers["Set-Cookie"])
        except BaseException:
            # pass
            try:
                setcookie = str(headers["set-cookie"])
            except BaseException:
                pass
                # print 'no cookie has been fetched'
        if not setcookie is None:
            cookieTokens = ["Domain","Expires", "Path", "Max-Age"]
            tokens = setcookie.split(";")
            for cookie in tokens:
                cookie = cookie.strip()
                if cookie.startswith("Expires="):
                    cookies = cookie.split(",", 2)
                    if len(cookies) > 2:
                        cookie = cookies[2]
                        cookie = cookie.strip()
                else :
                    cookies = cookie.split(",", 1)
                    if len(cookies) > 1:
                        cookie = cookies[1]
                        cookie = cookie.strip()
                namevalue = cookie.split("=", 1)
                if len(namevalue) > 1:
                    name = namevalue[0]
                    value = namevalue[1]
                    if name not in cookieTokens:
                        cookiemap[name] = value
            newcookie = cookiestring(cookiemap)
            # print newcookie
            req.add_header("Cookie", newcookie)
        try:
            # print headers['location']
            # print opener.open(headers['location']).read()
            global ld
            try:
                ld = headers['Location']
            except KeyError:
                try:
                    ld = headers['location']
                except KeyError:
                    pass
                    print 'sdas'

        except BaseException, e:
            pass
        return urllib2.HTTPRedirectHandler.http_error_302(self, req, fp, code, msg, headers)
while True:
    try:
        from bs4 import BeautifulSoup as BS
        cookie = cookielib.CookieJar()
        hdl = urllib2.HTTPCookieProcessor(cookie)
        opener = urllib2.build_opener(hdl, urllib2.ProxyHandler(dict()), MyRedirectHandler())
        STP = 'http://n.eduyun.cn'
        fst = 'http://n.eduyun.cn/index.php?r=portal/register/index'
        resp = opener.open(fst, timeout = 5)
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
        resp = opener.open(req, timeout = 5)
        f = open('out.txt', 'wb')
        f.write(resp.read())
        # f.write(unicode(resp.read(),'gb18030').encode('utf-8'))
        f.close()
        atp = 'http://n.eduyun.cn/index.php?r=portal/user/login&service=http%3a%2f%2fzgm.eduyun.cn%2fAccount%2fSso%3ftype%3d0ZMW77x3hl0%253D'
        asd = 'http://zgm.eduyun.cn/WorksFrontManage/WorksVideoFrontPlayNew?worksId=5229&from=timeline&isappinstalled=0'
        # resp = opener.open(asd)
        resp = opener.open(atp)
        prev = atp
        while (prev != ld):
            try:
                print ld
                prev = ld
                opener.open(ld)
            except BaseException:
                pass
        # print cookie
        aat = 'http://zgm.eduyun.cn/WorksFrontManage/UpdateVote'
        req = urllib2.Request(aat, urllib.urlencode({'worksId':5229}), headers = headers)
        # print cookie
        resp = opener.open(req)
        lstres = resp.read().decode('utf8')
        hcnt = hcnt + 1
    except BaseException, e:
        fcnt = fcnt + 1