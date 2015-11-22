#coding=utf-8
#Copyright 2015 CJSoft

testSet = {2, 3, 7, 13, 61, 24251}
def qpow(x, y, n):
	resu = 1
	while (y > 0):
		if (y & 1 == 1): resu = (resu * x) % n
		y = y >> 1
		x = (x * x) % n
	return resu

def MillerRabinTest(a, n, d, s):
	# True if it's likely to be a prime.
	if (n == 2 or n == a): return True
	if ((n & 1) == 0): return False
	for r in xrange(s):
		if (qpow(a, d, n) == 1 or (qpow(a, (1 << r) * d, n) in {-1, n - 1})):
			return True
	return False
	
def isPrime(x):
	global testSet
	if (x < 2): return False
	tint = x - 1
	s = 0
	while (tint & 1 == 0):
		tint = tint >> 1
		s = s + 1
	for i in testSet:
		if not(MillerRabinTest(i, x, tint, s)): 
			return False
	return True
if (__name__ == "__main__"):
	import sys
	if (len(sys.argv) > 1):
		for i in sys.argv[1:]:
			print isPrime(int(i))
	else:
		while True:
			try:
				a = int(input(">>> "))
				print isPrime(a)
			except KeyboardInterrupt:
				print "Bye!"
				sys.exit(0)
			except BaseException:
				print "Illegal input"