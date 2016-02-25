import random

f = open('test.in', 'w')
f.write('100000 100000\n')
for i in xrange(100000):
    f.write('%d '%random.randint(0, 10000000))
f.write('\n')
for i in xrange(100000):
    a, b = random.randint(1, 100000), random.randint(1, 100000)
    if (a > b):
        a, b = b, a
    f.write('%d %d %d\n'%(random.randint(1, 2), a, b))
f.close()