import sys
inp = raw_input()
n = int(inp.split(' ')[0])
v = int(inp.split(' ')[1])
arr = [list() for i in xrange(n + 1)]
for i, j in enumerate(arr):
    if i == 0:
        continue
    arr[i] = map(int, raw_input().split(' ')[1:])
    # print arr[i]
    arr[i].sort()

sout = list()
for i, j in enumerate(arr):
    if i > 0:
        if j[0] < v:
            sout.append(i)
    # except BaseException:
    #     print "err"
print len(sout)
if (len(sout) == 0):
    sys.exit(0)
sout.sort()
for i, j in enumerate(sout):
    sys.stdout.write(str(j))
    if (i != len(sout) - 1):
        sys.stdout.write(' ')
print ''