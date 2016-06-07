import os, sys
ar = 'g++ -g ' + ' '.join(sys.argv[1:])
os.popen(ar)
for i in xrange(1, 11):
    os.popen('a.exe < observer\\observer%s.in > out'%i)
    print os.popen('fc out observer\\observer%s.ans'%i).read()