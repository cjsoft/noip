#coding=utf-8
import sys
import urllib2
from urllib import quote
from bs4 import BeautifulSoup as BS
from ghost import Ghost
import os
import re
reload(sys)

sys.setdefaultencoding('utf-8')
gst = Ghost()
def ifjpg(x):
    data = x[:11]
    if data[:4] != '\xff\xd8\xff\xe0': return False
    if data[6:] != 'JFIF\0': return False
    return True
def fetchhtml(url):
    global searchstr
    tag = False
    global gst
    with gst.start(download_images = False) as sess:
        while not tag:
            try:
                pg, ers = sess.open(url)
                tag = True
            except BaseException:
                print 'failed, retrying'

        sess.wait_for_page_loaded
        sess.wait_for_selector('iframe')
        sess.frame('contentFrame')
        sess.wait_for_text('“%s”'%searchstr)
        del ers
        q = str(sess.content)
    return q
def securefilename(nm):
    return re.sub(r'[\\/\:\*\?\<\>\|]', '_', nm)
def saveimg(nm, url, pth):
    global searchstr
    dir = os.path.split(pth)[0]
    if (os.path.exists(dir) != True):
        os.makedirs(dir)
    x = urllib2.urlopen(url).read()
    if not ifjpg(x):
        pth = os.path.splitext(pth)[0] + '.png'
    f = open(pth, 'wb')
    f.write(x)
    f.close()
    print nm, '->', pth
    return pth
searchstr = ' '.join(sys.argv[1:])
print 'Searching', searchstr

uri = 'http://music.163.com/#/search/m/?s=%s&type=10'%searchstr.decode()#(quote(searchstr.encode('utf-8')))
print uri
f = open('sad.txt', 'w')
z = fetchhtml(uri)
f.write(z)
f.close()
sp = BS(z, 'lxml')
if (z.find('很抱歉，未能找到相关搜索结果') != -1):
    print 'Sorry, No results!'
    sys.exit(0)
import zipfile
f = zipfile.ZipFile('%s.zip'%securefilename(searchstr), 'w' ,zipfile.ZIP_DEFLATED)
for j in sp.find('ul', class_ = 'm-cvrlst m-cvrlst-alb3 f-cb').find_all('li'):
    s = j.find('img')
    if (s):
        pth = searchstr.replace('/', '_').replace('+', '_').replace('\\', '_')
        ur = str(s['src'])
    try:
        nm = j.find('p', class_ = 'dec').find('a')
    except BaseException:
        nm = None
    if (nm):
        name = str(nm['title'])
        name = name.replace('/', '_').replace('&', '_')
        try:
            
            f.write(saveimg(name, ur.replace('?param=180y180', ''), '%s/%s.jpg'%(securefilename(searchstr), securefilename(name))))
        except UnicodeEncodeError:
            pass

f.close()