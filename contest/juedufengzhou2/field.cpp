#include <iostream>
#include <cstdio>
#include <cstring>
#define lowbit(x) ((x) & (-x))
using namespace std;
typedef int ll;
const int MXN = 500007;
int prime[MXN];
int dcd[MXN];
bool isprime[MXN];
int cursor = 0;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
/*struct szsz {
    ll d[MXN];
    szsz() {memset(d, 0, sizeof(d));}
    void add(int pos,ll ad){
        while (pos < MXN && pos > 0){
            d[pos] += ad;
            // d[pos] %= MOD;
            pos += lowbit(pos);
        }
    }
    ll sum(int pos){
        ll rtn = 0;
        while (pos > 0){
            rtn += d[pos];
            // rtn %= MOD;
            pos -= lowbit(pos);
        }
        // rtn += MOD;
        // rtn %= MOD;
        return rtn;
    }
} ta;*/
void genPrime(int n) {
    memset(dcd, 0, sizeof(dcd));
    memset(prime, 0, sizeof(prime));
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) {
            // ta.add(i, 1);
            prime[cursor++] = i;
            dcd[i] = 1;
        }
        for (int j = 0; (j < cursor) && (i * prime[j] <= n); ++j) {
            dcd[i * prime[j]] += dcd[i] + 1;
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
    isprime[1] = isprime[0] = false;
}
int t, n, m, p;
int main() {
    freopen("field.in", "r", stdin);
    freopen("field.out", "w", stdout);
    genPrime(500002);
    scanf("%d", &t);
    while (t--) {
        int cbt = 0;
        scanf("%d %d %d", &n, &m, &p);
        // if (p == 0) {
        //     printf("%d\n", ta.sum(n) * ta.sum(m));
        // }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (dcd[gcd(i, j)] <= p) ++cbt;
            }
        }
        printf("%d\n", cbt);
    }
    return 0;
}