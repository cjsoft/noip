import sys
from sys import stdout
class aaa(object):
    def __init__(self, lll):
        super(aaa, self).__init__()
        self.a = lll[0]
        self.b = lll[1]

tline = map(int, raw_input().split(' '))
n, v = tline[0], tline[1]
dat = dict()
for i in xrange(1, n + 1):
    tmp = aaa(map(int, raw_input().split(' ')))
    dat[tmp.a] = tmp.b
left = 0
resu = 0
prev = 0
ks = dat.keys()
ks.sort()
dat[ks[-1] + 1] = 0
ks.append(ks[-1] + 1)
for i in ks:
    if (i == prev + 1):
        # print left
        if (v >= left):
            resu = resu + left
            if (v - left >= dat[i]):
                resu = resu + dat[i]
                left = 0
            else:
                resu = resu + v - left
                left = left + dat[i] - v
        else:
            resu = resu + v
            left = dat[i]
    else:
        if (v >= dat[i]):
            left = 0
            resu = resu + dat[i]
        else:
            left = dat[i] - v
            resu = resu + v
    prev = i
    # stdout.write('s%dad%s\n'%(i, left))
print resu