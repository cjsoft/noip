#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int t = exgcd(b, a % b, x, y);
    int tx = x, ty =y;
    x = ty;
    y = tx- a / b * ty;
    return t;
}

int mod_reverse(int a,int p){
    int x,y;
    exgcd(a,p,x,y);
    return (x%p+p)%p;
}
bool check(int n) {
    for (int i = 2; i <= int(sqrt(n)); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
int m;
int k, la, lb, ia, ib, fa, fb;
int main() {
    cin >> k >> l;a >> lb >> ia >> ib >> fa >> fb;
    int ma = ib;
    int mb = ia;
    int x, y;
    int re = exgcd(ia, ib, x, y);
    if (re != 1 || !check(ia) || !check(ib)) {
        puts("no answer");
        return 0;
    }
    int tb = mod_reverse(la, ib);
    int tb = mod_reverse(lb, ia);
    int rrr = tb * ia * lb + ta * ib * la;
}