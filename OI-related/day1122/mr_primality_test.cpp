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
int main() {

    return 0;
}