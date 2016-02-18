#!/usr/bin/python
import random
casesize = 10000000
f = open('test.in', 'w')
for i in xrange(1, casesize + 1):
    x = random.randint(1, 3)
    if (x == 1 or x == 2):
        f.write('push\n');
    else:
        f.write('pop\n')
f.close()