import urllib2
from bs4 import BeautifulSoup
import sys
reload(sys)
sys.setdefaultencoding('utf-8')
a = urllib2.urlopen('http://www.dlhs24.com.cn').read()
f = open('sad.txt','w')
soup = BeautifulSoup(a, from_encoding='utf-8')
res = soup.find_all('a')
for i in res:
    f.write('%s\n'%i.string)
f.close()
print 'as'