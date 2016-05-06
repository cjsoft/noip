#coding=utf-8
import random
f = open('data.txt', 'w')
n = 10000
q = 1000
f.write('%d\n'%n)
for i in xrange(n):
    f.write('%d '%random.randint(1, 1000))
f.write('\n%d\n'%q)
for i in xrange(q):
    a, b = random.randint(1, n), random.randint(1, n)
    if (a > b):
        a, b = b, a
    if (random.randint(1, 3) == 1):
        f.write('count %d %d\n'%(a, b))
    else:
        f.write('add %d %d %d\n'%(a, b, random.randint(1, 1000)))
f.close()
