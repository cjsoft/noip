# coding=utf-8
def getProxiesList():
    import urllib2, urllib
    from bs4 import BeautifulSoup as BS
    if __name__ == '__main__':
        print '正获取代理列表...'
    resp = urllib2.urlopen('http://www.proxy360.cn/default.aspx')
    source = resp.read()
    soup = BS(source, 'html.parser')
    lst = soup.find_all('div', class_ = 'proxylistitem')
    rtn = list()
    for i in lst:
        ip = i.find('span', style = 'width:140px;').text.strip('\n\r ')
        port = int(i.find('span', style = 'width:50px;').text.strip('\n\r '))
        rtn.append('http://%s:%d'%(ip, port))
    return rtn