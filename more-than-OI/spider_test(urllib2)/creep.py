#coding=utf-8
import urllib2
import Queue, re
from bs4 import BeautifulSoup
import sys, os
EEE = True
if len(sys.argv) > 1:
    if sys.argv[1].upper() == 'Y':
        EEE = True
q = Queue.Queue()
STP = 'http://www.dlhs24.com.cn'
s = {'/'}
q.put('/')
# print STP + q.front()
reload(sys)
sys.setdefaultencoding('utf-8')
f = open('links.txt','w')
while not(q.empty()):
    try:
        tsl = q.get()
        if (os.path.splitext(tsl)[1] in {'.jpg','.png','.bmp','.zip'} and not EEE):
            continue
        a = urllib2.urlopen(STP + tsl).read()
        # print a
        # print os.path.splitext(tsl)
        if (os.path.splitext(tsl)[1] in {'.jpg','.png','.bmp','.zip'}):
            pic = open('pics/' + tsl.replace('/','_'),'wb')
            pic.write(a)
            pic.close()
            print 'fetched file', tsl
        else:
            try:
                soup = BeautifulSoup(a, 'html.parser', from_encoding = 'utf-8')
                res = soup.find_all('a')        
                for i in res:
                    try:
                        if not(i['href'] in s) and str(i['href'])[0] == '/' and not('.php' in str(i['href'])):
                            s.add(i['href'])
                            q.put(i['href'])
                            if (str(i.string) != 'None'):
                                f.write('%s： %s\n'%(i['href'], i.string))
                                print 'fetched link %s'%i.string
                    except BaseException:
                        pass
                asd = soup.find('div', class_ = 'title')
                if (len(str(asd)) > 4):
                    doc = open('article\\' + str((soup.title.string).encode('gb18030')) + '.txt', 'w')
                    for j in asd.children:
                        if (len(str(j.string)) > 1):
                            doc.write('%s\n\n'%j.string)
                            print 'fetched article %s'%j.string
                asd = soup.find('div', class_ = 'content')
                if (len(str(asd)) > 4):
                    for j in asd.children:
                        doc.write('%s\n'%str(j).replace('"/', '"%s/'%STP))
                doc.close()
            except BaseException:
                pass
    except BaseException:
        pass
f.close()
