from sys import stdout
asd = raw_input()
tline = map(int, asd.split(' '))
a, b = tline[0], tline[1]
if (a > b):
    a, b = b, a
asd = raw_input()
tline = map(int, asd.split(' '))
c, d = tline[0], tline[1]
if (c > d):
    c, d = d, c
aa = [(True if ((i >= a and i < b) or (i >= c and i < d)) else False) for i in xrange(101)]
cnt = 0
# print aa
for i, j in enumerate(aa):
    if j:
        # print i
        cnt = cnt + 1
print cnt