#coding=utf-8
import os, re, sys, urllib2
reload(sys)
# sys.setdefaultencoding('utf-8')
print r'src="(http://[a-zA-Z\.0-9/\-\?\&\+]*)"'
r = re.compile(r'src="(http://[a-zA-Z\.0-9/\-\?\&\+]*)"')
for i in os.listdir('article'):
    f = open('article/'+i, 'r')
    sss = f.read()
    # print sss
    ma = r.findall(sss)
    # print ma
    if ma:
        for j in ma:
            try:
                if (os.path.isfile('articlepics\\' +j.replace(':',';').replace('/','_'))):
                    continue
                f = open('articlepics\\' +j.replace(':',';').replace('/','_'),'wb')
                f.write(urllib2.urlopen(j).read())
                print 'fetched', j
            except BaseException:
                try:
                    f.close()
                except BaseException:
                    pass
            # print r.match(j).group()
    f.close()