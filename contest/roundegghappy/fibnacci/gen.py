import random

f = open('test.in', 'w')
f.write('10000 10000\n')
for i in xrange(10000):
    f.write('%d '%random.randint(0, 10000000))
f.write('\n')
for i in xrange(10000):
    a, b = random.randint(1, 10000), random.randint(1, 10000)
    if (a > b):
        a, b = b, a
    f.write('%d %d %d\n'%(random.randint(1, 2), a, b))
f.close()