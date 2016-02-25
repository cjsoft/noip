#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
#define mid(l, r) ((l + r) >> 1)
#define update(x) stree[x] = (stree[x << 1] + stree[x << 1 | 1]) % MOD
using namespace std;
typedef long long ll;
const int MXN = 100007;
const ll MOD = 1000000001;
ll fib[MXN];
struct nsegtree {
    ll rawdata[MXN];
    ll stree[MXN * 8 + 7];
    nsegtree() {memset(rawdata, 0, sizeof(rawdata)); memset(stree, 0, sizeof(stree));}
    void build(int root, int l, int r) {
        if (l == r) {
            stree[root] = rawdata[l];
            return;
        }
        build(lson(root), l, mid(l, r));
        build(rson(root), mid(l, r) + 1, r);
        update(root);
    }
    ll query(int root, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && qr >= r) 
            return stree[root];
        return (
            query(lson(root), l, mid(l, r), ql, qr)
            + query(rson(root), mid(l, r) + 1, r, ql, qr)
        ) % MOD;
    }
} arrseg, fibseg;
struct fsegstree {
    ll stree[MXN * 8 + 7];
    int tag[MXN * 8 + 7];
    fsegstree() {memset(stree, 0, sizeof(stree)); memset(tag, 0, sizeof(tag));}
    inline void pushdown(int root, int l, int r) {
        if (tag[root]) {
            stree[lson(root)] += fibseg.query(1, 1, MXN - 5, l, mid(l, r)) * tag[root] % MOD;
            stree[lson(root)] %= MOD;
            stree[rson(root)] += fibseg.query(1, 1, MXN - 5, mid(l, r) + 1, r) * tag[root] % MOD;
            stree[rson(root)] %= MOD;
            tag[lson(root)] += tag[root];
            tag[rson(root)] += tag[root];
            tag[root] = 0;
        }
    }
    void add(int root, int l, int r, int al, int ar) {
        if (ar < l || al > r) return;
        pushdown(root, l, r);
        if (al <= l && ar >= r) {
            ++tag[root];
            stree[root] += fibseg.query(1, 1, MXN - 5, l, r);
            stree[root] %= MOD;
            // printf("%I64d\n", stree[root]);
            return;
        }
        add(lson(root), l, mid(l, r), al, ar);
        add(rson(root), mid(l, r) + 1, r, al, ar);
        update(root);
    }
    ll query(int root, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        pushdown(root, l, r);
        if (ql <= l && qr >= r) return stree[root];
        return (
        query(lson(root), l, mid(l, r), ql, qr)
        + query(rson(root), mid(l, r) + 1, r, ql, qr)
        ) % MOD;
    }
} mseg;
int n, m;
int main() {
    freopen("test.in", "r", stdin);
    freopen("fibnacci.out", "w", stdout);
    fibseg.rawdata[1] = 1;
    for (int i = 2; i < MXN - 4; ++i) {
        fibseg.rawdata[i] = (fibseg.rawdata[i - 1] + fibseg.rawdata[i - 2]) % MOD;
    }
    fibseg.build(1, 1, MXN - 5);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arrseg.rawdata[i]);
    }
    arrseg.build(1, 1, MXN - 5);
    int a, b, c;
    while (m--) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            mseg.add(1, 1, MXN - 5, b, c);
        } else {
            printf("%I64d\n", (arrseg.query(1, 1, MXN - 5, b, c) + mseg.query(1, 1, MXN - 5, b, c)) % MOD);
        }
    }
    printf("%f\n", clock()/(float)CLOCKS_PER_SEC);
    return 0;
}