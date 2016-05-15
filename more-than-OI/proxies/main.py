import openers, urllib2
lst = openers.buildWithProxies()
for i in lst:
    try:
        resp = i.open('http://www.jb51.net/article/37287.htm')
        print len(resp.read())
    except urllib2.URLError:
        print 'err %s'%i.tag