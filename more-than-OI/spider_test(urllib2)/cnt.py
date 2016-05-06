#coding=utf-8
import os, re, sys, urllib2
reload(sys)
# sys.setdefaultencoding('utf-8')
print r'src="(http://[a-zA-Z\.0-9/\-\?\&\+]*)"'
r = re.compile(r'src="(http://[a-zA-Z\.0-9/\-\?\&\+]*)"')
cnt = 0
for i in os.listdir('article'):
    f = open('article/'+i, 'r')
    sss = f.read()
    # print sss
    ma = r.findall(sss)
    # print ma
    if ma:
        for j in ma:
            cnt = cnt + 1
            # print r.match(j).group()
    f.close()
print cnt