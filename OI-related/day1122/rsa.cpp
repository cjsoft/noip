/**
 * Copyright 2015 CJSoft
 * Git repository: https://github.com/cjsoft/noip.git
 */
/**
 * This is not a component, just a experiment.
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

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
    for (int i = 0; i < s; ++i) {
        if (quickPow(a, d, n) == 1 ||
            quickPow(a, (1 << i) * d, n) == n - 1)
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

ll getaPrime(ll lowerBound) {
    while (!isPrime(lowerBound))
        ++lowerBound;
    return lowerBound;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll temp = exgcd(b, a % b, x, y);
    ll tx = x;
    x = y;
    y = tx - a / b * y;
    return temp;
}
ll rsaEnDecrypt(ll raw, ll a, ll b) {
    return quickPow(raw, a, b);
}
void keyGen(ll stp, ll stq,
    ll &publicKeyPow, ll &publicKeyMod,
    ll &privateKeyPow, ll &privateKeyMod) {
    // sugest stp & stq are both no bigger than 2e6
    ll p = getaPrime(stp), q = getaPrime(stq);
    ll n = p * q;
    ll m = (p - 1) * (q - 1);
    ll e = m - 10;
    ll d, y;
    while(exgcd(e, m, d, y) != 1 && !isPrime(e)) --e;
    d += m;
    d %= m;
    publicKeyPow = e;
    publicKeyMod = n;
    privateKeyPow = d;
    privateKeyMod = n;
    return;
}
int main() {
    
}