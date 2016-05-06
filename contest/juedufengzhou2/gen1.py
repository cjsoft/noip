import random

f = open('idioms.in', 'w')
f.write('3000 2\n')
for i in xrange(3000):
    f.write('%s\n'%''.join(random.sample('qwertyuiopasdfghjklzxcvbnm1234567890', 4)))
f.close()