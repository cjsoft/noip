
import os, sys
sys.stdout.write(os.popen('g++ %s'%' '.join(sys.argv[1:])).read())
for i in xrange(1, 11):
    os.popen('a.exe < sequence\\sequence%s.in > out'%i)
    print i, os.popen('fc out sequence\\sequence%s.ans'%i).read()