#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
#define mid(l, r) ((l + r) >> 1)
#define update(x) stree[x] = (stree[x << 1] + stree[x << 1 | 1]) % MOD
#define lowbit(x) (x & (-x))
#define spminus(x, y) (((x - y) % MOD + MOD) % MOD)
using namespace std;
typedef long long ll;
const int MXN = 100007;
const ll MOD = 1000000001;
int n, m;
ll fib[MXN];
// struct szsz {
//     ll d[MXN];
//     szsz() {memset(d, 0, sizeof(d));}
//     void add(int pos,ll ad){
//         while (pos < MXN && pos > 0){
//             d[pos] += ad;
//             d[pos] %= MOD;
//             pos += lowbit(pos);
//         }
//     }
//     ll sum(int pos){
//         ll rtn = 0;
//         while (pos > 0){
//             rtn += d[pos];
//             rtn %= MOD;
//             pos -= lowbit(pos);
//         }
//         rtn += MOD;
//         rtn %= MOD;
//         return rtn;
//     }
// } ta;
inline int getint() {
    char ch = getchar();
    int data = 0;
    while (ch <'0' || ch > '9') ch = getchar();
    do {
        data = data * 10 + ch - 48;
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return data;
}
inline int getll() {
    char ch = getchar();
    ll data = 0;
    while (ch <'0' || ch > '9') ch = getchar();
    do {
        data = data * 10 + ch - 48;
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return data;
}
ll arr[MXN];
// struct nsegtree {
//     ll rawdata[MXN];
//     ll stree[MXN * 8 + 7];
//     nsegtree() {memset(rawdata, 0, sizeof(rawdata)); memset(stree, 0, sizeof(stree));}
//     inline void build(int root, int l, int r) {
//         if (l == r) {
//             stree[root] = rawdata[l];
//             return;
//         }
//         int m = mid(l, r);
//         build(lson(root), l, m);
//         build(rson(root), ++m, r);
//         update(root);
//     }
//     inline ll query(int root, int l, int r, int ql, int qr) {
//         if (qr < l || ql > r) return 0;
//         if (ql <= l && qr >= r) 
//             return stree[root];
//         int m = mid(l, r);
//         return (
//             query(lson(root), l, m, ql, qr)
//             + query(rson(root), ++m, r, ql, qr)
//         ) % MOD;
//     }
// } arrseg;
ll fqzh[MXN];
struct fsegstree {
    ll stree[MXN * 8 + 7];
    int tag[MXN * 8 + 7];
    fsegstree() {memset(stree, 0, sizeof(stree)); memset(tag, 0, sizeof(tag));}
    /*inline*/ void pushdown(int root, int l, int r) {
        if (tag[root]) {
            int m = mid(l, r);
            stree[lson(root)] = (stree[lson(root)] + spminus(fqzh[m], fqzh[l - 1])/*fibseg.query(1, 1, n, l, m)*/ * tag[root] % MOD) % MOD;
            // stree[lson(root)] %= MOD;
            stree[rson(root)] = (stree[rson(root)] + (spminus(fqzh[r], fqzh[m]))/*fibseg.query(1, 1, n, ++m, r)*/ * tag[root] % MOD) % MOD;
            // stree[rson(root)] %= MOD;
            tag[lson(root)] += tag[root];
            tag[rson(root)] += tag[root];
            tag[root] = 0;
        }
    }
    /*inline*/ void add(int root, int l, int r, int al, int ar) {
        if (ar < l || al > r) return;
        pushdown(root, l, r);
        if (al <= l && ar >= r) {
            ++tag[root];
            stree[root] = (stree[root] + spminus(fqzh[r], fqzh[l - 1])/*fibseg.query(1, 1, n, l, r)*/) % MOD;
            // stree[root] %= MOD;
            // printf("%I64d\n", stree[root]);
            return;
        }
        int m = mid(l, r);
        add(lson(root), l, m, al, ar);
        add(rson(root), ++m, r, al, ar);
        update(root);
    }
    /*inline*/ ll query(int root, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && qr >= r) return stree[root];
        pushdown(root, l, r);
        int m = mid(l, r);
        return (
        query(lson(root), l, m, ql, qr)
        + query(rson(root), ++m, r, ql, qr)
        ) % MOD;
    }
} mseg;
int main() {
    freopen("fibnacci.in", "r", stdin);
    freopen("fibnacci.out", "w", stdout);
    // ta.add(1, 1);
    // ta.add(2, 1);
    fib[1] = 1;
    for (int i = 2; i < MXN - 4; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
        // ta.add(i, fib[i]);
    }
    for (int i = 1; i < MXN - 4; ++i) {
        fqzh[i] = (fqzh[i - 1] + fib[i]) % MOD;
    }
    // printf("%I64d\n", ta.sum(4));
    scanf("%d %d", &n, &m);
    // fibseg.build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        //0.14
        arr[i] = arr[i - 1] + getint();
        arr[i] %= MOD;
        // scanf("%d", &arrseg.rawdata[i]);
    }
    // printf("%f\n", clock()/(float)CLOCKS_PER_SEC);
    int a, b, c;
    int totals = 0, totalss = 0;
    while (m--) {
        a = getint();
        b = getint();
        c = getint();
        // scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            // clock_t sss = clock();
            mseg.add(1, 1, n, b, c);
            // totals += clock() - sss;
        } else {
            // clock_t sss = clock();
            printf("%lld\n", (spminus(arr[c], arr[b - 1]) + mseg.query(1, 1, n, b, c)) % MOD);
            // totalss += clock() - sss;
        }
    }
    // printf("%f\n", clock()/(float)CLOCKS_PER_SEC);
    // printf("%f\n", totals/(float)CLOCKS_PER_SEC);
    // printf("%f\n", totalss/(float)CLOCKS_PER_SEC);
    return 0;
}