#!/usr/bin/python
import random
casesize = 10000000
f = open('test.in', 'w')
for i in xrange(casesize):
    f.write('%s\n'%random.randint(1, casesize))
f.close()