# 非确定性算法  
***
虽然在OI中并不实用，但是这种算法本身具有非常大的实用价值。事实上，一些非确定性算法在现实中的应用比对应的确定性算法要广泛的多。  
下面介绍两种非确定性算法。  
## 1. Miller Rabbin Primality Test  
MR素性测试是一个常用的非确定性素数检查算法，在OI中也有一定的应用，它的复杂度是O(log(n))，远远小于确定性的AKS，复杂度为O(log(n)^6 )，和朴素枚举，复杂度为O(sqrt(n))。  
MR素性测试的失误率取决于测试集。当随机选取测试集时，它的错误率为4^(-len(testSet))，一个精心选取的测试集可以保证一定范围内的测试的结果的完全正确，这也是他被广泛应用的原因。  
下面给出一个Python 2.7的MR测试样例代码，其中使用的测试集保证1到1e16范围内结果无误。  

```python
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
            try:
    			print isPrime(int(i))
            except BaseException:
                print "Illegal input"
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
```

```c++
/**
 * Copyright 2015 CJSoft
 * This piece of code have somethings to
 * do with primality test.
 */
#include <iostream>
#include <cstdio>
typedef long long ll; //NOLINT
ll quickPow(ll x, ll y, ll MOD) {
    ll resu = 1;
    while (y > 0) {
        if (y & 1) resu = (resu * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return resu;
}
bool MillerRabbinTest(ll a, ll n, ll d, ll s) {
    if (n == 2 || n == a) return true;
    if (!(n & 1)) return false;
    if (quickPow(a, d, n) == 1) return true;
    for (int i = 0; i < s; ++i) {
        if (quickPow(a, (1 << i) * d, n) == n - 1)
            return true;
    }
    return false;
}
bool isPrime(ll x) {
    const ll testCase[] = {2, 3, 7, 13, 61, 24251};
    if (x < 2) return false;
    ll tint = x - 1;
    ll s = 0;
    while (!(tint & 1)) {
        tint >>= 1;
        ++s;
    }
    for (int i = 0; i < sizeof(testCase) / sizeof(ll); ++i)
        if (!MillerRabbinTest(testCase[i], x, tint, s))
            return false;
    return true;
}
int main() {

    return 0;
}

```
## 2. Bloom Filter  
Bloom Filter算法非常简单易懂，他被广泛的应用在爬虫技术中。  
它的功能是确定一个元素是否在集合之中，优势在于只使用非常少的空间，就可以维护数额巨大的元素的信息。**它只能确定一个元素是否在一个集合中**。然而内存、时间、准确性三者往往在一定程度上是守恒的，使用越少的内存，BF的准确性就越低。它的复杂度是O(1)的。  
下面说一下它的原理。  
**他就是个hash加强版。**  
1. 当我们查询一个元素是否在集合中，我们使用少至几个多至几十个的不同的hash函数得出许多元素的hash值（要实现的话hash函数可以使用几个固定的，外加一些随机生成的hash函数，这个在第一次使用BF之前就要做，除此之外还要准备相应数目的bitset），检查每个函数对应的bitset的对应位上是否为1，如果所有对应位的值都为1的话，说明这个元素有可能在这个集合中，反之一定不再这个集合中。  
2. 当我们将一个元素加入到集合中的话，我们算出那些hash值，set一下每个hash函数对应的bitset上hash值对应位即可（也就是赋成1）  
3. 关于元素的移除。  
BF有个变种叫做Counting Bloom Filter，看了名字大概就明白怎么回事了吧=w=。  
详情请去问问神奇海螺吧、 
