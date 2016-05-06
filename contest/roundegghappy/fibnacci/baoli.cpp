#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

const int MXN = 100007;
const ll MOD = 1000000001;
ll fib[MXN];
ll raw[MXN];
int n, m;
int main() {
    // freopen("fibnacci.in", "r", stdin);
    // freopen("fibnacci.txt", "w", stdout);
    fib[1] = 1;
    for (int i = 2; i < MXN - 4; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= MOD;
    }
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", raw + i);
    }
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            for (int j = b; j <= c; ++j) {
                raw[j] += fib[j];
                raw[j] %= MOD;
            }
        } else {
            ll cnt = 0;
            for (int j = b; j <= c; ++j) {
                cnt += raw[j];
                cnt %= MOD;
            }
            printf("%I64d\n", cnt);
        }
    }
    return 0;
}