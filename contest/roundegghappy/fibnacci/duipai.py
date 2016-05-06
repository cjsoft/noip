#coding=utf-8
import os, sys
reload(sys)
sys.setdefaultencoding('utf-8')
for i in xrange(1000):
    os.popen('python gen.py')
    os.popen('a.exe < test.in > a.out')
    os.popen('b.exe < test.in > b.out')
    q = os.popen('fc a.out b.out').read()
    s = q.find('找不到差异'.encode('gb18030'))
    if (s == -1):
        print 'Lost synchornization, halting'
        sys.exit()
    else:
        print 'Pattern matched!'