#include <iostream>
#include <cstdio>
#include <cstring>
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
#define parent(x) (x >> 1)
#define mid(l, r) ((l + r) >> 1)
using namespace std;
typedef long long ll;

ll stree[800007];
int pos[200007];
int len = 0;
int m;
ll t = 0;
ll d;
void init(int root, int l, int r) {
    if (l == r) {
        pos[l] = root;
        return;
    }
    init(lson(root), l, mid(l, r));
    init(rson(root), mid(l, r) + 1, r);
}
ll query(int root, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && qr >= r) return stree[root];
    return max(query(lson(root), l, mid(l, r), ql, qr), query(rson(root), mid(l, r) + 1, r, ql, qr));
}
void edit(int p, ll value) {
    stree[p = pos[p]] = value;
    p >>= 1;
    while (p > 0) {
        stree[p] = max(stree[lson(p)], stree[rson(p)]);
        p >>= 1;
    }
}
void append(ll n) {
    edit(++len, (n + t) % d);
}
ll Query(int L) {
    t = query(1, 1, m, len - L + 1, len);
    return t;
}
int main() {
    scanf("%d %lld", &m, &d);
    init(1, 1, m);
    
    char ipt[3];
    ll tmp;
    for (int i = 0; i < m; ++i) {
        memset(ipt, 0, sizeof(ipt));
        scanf("%s %lld", ipt, &tmp);
        if (ipt[0] == 'Q') {
            printf("%lld\n", Query(tmp));
        } else {
            append(tmp);
        }
    }
    return 0;
}