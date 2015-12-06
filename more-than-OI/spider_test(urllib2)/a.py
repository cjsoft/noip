#coding=utf-8
import urllib2
import Queue
from bs4 import BeautifulSoup
import sys, os
q = Queue.Queue()
STP = 'http://www.dlhs24.com.cn'
s = {'/'}
q.put('/')
# print STP + q.front()
reload(sys)
sys.setdefaultencoding('utf-8')
f = open('sad.txt','w')
while not(q.empty()):
    try:
        tsl = q.get()
        a = urllib2.urlopen(STP + tsl).read()
        # print a
        print os.path.splitext(tsl)
        if (os.path.splitext(tsl)[1] in {'.jpg','.png','.bmp','.zip'}):
            pic = open(tsl.replace('/','_'),'wb')
            pic.write(a)
            pic.close()
            print tsl
        else:
            try:
                soup = BeautifulSoup(a, 'html.parser', from_encoding = 'utf-8')
                res = soup.find_all('a')        
                for i in res:
                    try:
                        if not(i['href'] in s) and str(i['href'])[0] == '/' and not('.php' in str(i['href'])):
                            s.add(i['href'])
                            q.put(i['href'])
                            f.write('%s： %s\n'%(i['href'], i.string))
                            print i.string
                    except BaseException:
                        pass
            except BaseException:
                pass
    except BaseException:
        pass
f.close()
