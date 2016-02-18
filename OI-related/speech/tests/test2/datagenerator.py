#!/usr/bin/python
import random
casesize = 10000000
f = open('test.in', 'w')
for i in xrange(1, casesize + 1):
    x = random.randint(1, casesize)
    while (x == i):
        x = random.randint(1, casesize)
    f.write('%s\n'%x)
f.close()