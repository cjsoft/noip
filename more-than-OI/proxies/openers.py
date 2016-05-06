# coding=utf-8
import cookielib, urllib2
def buildWithProxies(*args):
    import proxies
    pxy = proxies.getProxiesList()
    rtn = list()
    for i in pxy:
        cookie = cookielib.CookieJar()
        ckhandler = urllib2.HTTPCookieProcessor(cookie)
        opener = urllib2.build_opener(ckhandler, urllib2.ProxyHandler({'http':i}), *args)
        opener.tag = i
        rtn.append(opener)
    return rtn