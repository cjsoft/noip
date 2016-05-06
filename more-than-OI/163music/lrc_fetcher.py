#coding=utf-8
from __future__ import unicode_literals
import sys, io
import re
import urllib, urllib2
from bs4 import BeautifulSoup as BS
from ghost import Ghost, TimeoutError
reload(sys)
sys.setdefaultencoding('utf-8')
# sys.stdout.encoding = io.TextIOWrapper(sys.stdout.buffer,encoding='gb18030')    
ghost = Ghost(log_level = 0)
def parse_time(tm):
    minu = int(tm / 60)
    sec = tm - minu * 60.0
    return minu, sec
def securefilename(nm):
    return re.sub(r'[\\/\:\*\?\<\>\|]', '_', nm)

s = ghost.start(download_images = False)
# s.show()
for j in sys.argv[1:]:
    try:
        asd = int(j)
        a, b = s.open('http://music.163.com/#/song?id=%d'%asd)
        s.frame()
        s.wait_for_selector('iframe#g_iframe.g-iframe[name="contentFrame"]', 0.5)
        s.frame('contentFrame')
        s.wait_for(lambda : s.content.find('<a data-res-action="play"') != -1, 0, 0.5)
        dom = BS(s.content, 'html.parser')
        # s.evaluate('$(\'a.u-btn2.u-btn2-2.u-btni-addply.f-fl\').click()')
        # s.evaluate('document.getElementsByTagName("u-btn2 u-btn2-2 u-btni-addply f-fl")[0].click();')
        s.fire('a.u-btn2.u-btn2-2.u-btni-addply.f-fl', 'click')
        nm = dom.find('div', class_ = 'tit').get_text().strip(' \n\r')
        # s.click('a.u-btn2.u-btn2-2.u-btni-addply.f-fl', 0)
        s.frame()
        s.fire('#g_player > div.ctrl.f-fl.f-pr.j-flag > span > a', 'click')
        s.wait_for_selector('div.listlyric.j-flag > p', 0.8)
        f = open(securefilename(nm) + '.lrc', 'w')
        DOM = BS(s.content, 'html.parser')
        lyriclst = DOM.find('div', class_ = 'listlyric j-flag')
        for j in lyriclst.find_all('p'):
            m, ss = parse_time((float(j['data-time'])))
            lrc = j.get_text().strip(' \r\n')
            f.write('[%s:%s]%s\n'%(m, round(ss, 2), lrc))
        f.close()
    except TimeoutError:
        print 'failed', j
    except LookupError:
        print 'failed', j
        # print s.content
        # print s.content.encode('gb18030')
