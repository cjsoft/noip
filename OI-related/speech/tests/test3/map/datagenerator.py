#!/usr/bin/python
casesize = 1000000
import random
f = open('test.in', 'w')
s = list()
for i in xrange(casesize):
    s.append([i, random.randint(0, casesize - 1)])
for i in xrange(casesize):
    a = random.randint(0, len(s) - 1)
    f.write('%d %d\n'%(s[a][0], s[a][1]))
    s.pop(a)
for i in xrange(casesize / 3):
    f.write('%d\n'%random.randint(0, casesize - 1))
f.close()