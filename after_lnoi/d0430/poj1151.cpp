#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
#define mid(l, r) ((l + r) >> 1)
#define MXN 207
using namespace std;
struct seg {
    double x1, x2;
    int atag;
    double y;
    int lx1, lx2;
    seg() {x1 = x2 = y = atag = 0;}
    seg(double a, double b, double c, int d):x1(a),x2(b),y(c),atag(d) {}
    bool operator<(const seg &b) const {
        return y == b.y ? atag > b.atag : y < b.y;
    }
} ss[MXN];
int cnt[MXN << 2 | 7];
int ll[MXN << 2 | 7], rr[MXN << 2 | 7];
double stree[MXN << 2 | 7];
double prefix[MXN], loc[MXN];
inline void pushup(int root, int l, int r) {
    if (cnt[root]) {
        stree[root] = loc[r] - loc[l - 1];
    } else if (l == r) {
        stree[root] = 0;
    } else {
        stree[root] = stree[lson(root)] + stree[rson(root)];
    }
}
void adddata(int root, int l, int r, int al, int ar, int data) {
    if (l > ar || r < al) return;
    if (l >= al && r <= ar) {
        cnt[root] += data;
        pushup(root, l, r);
        return;
    }
    adddata(lson(root), l, mid(l, r), al, ar, data);
    adddata(rson(root), mid(l, r) + 1, r, al, ar, data);
    pushup(root, l, r);
}
int main() {
    int n = 0;
    int t = 1;
    while (~scanf("%d", &n)) {
        if (n == 0) return 0;
        double a, b, c, d;
        int m = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
            ss[m++] = seg(a, c, b, 1);
            ss[m++] = seg(a, c, d, -1);
            loc[cur++] = a; loc[cur++] = c;
        }
        sort(loc, loc + cur);
        int sz = unique(loc, loc + cur) - loc;
        for (int i = 0; i < sz; ++i) {
            prefix[i + 1] = loc[i];
        }
        for (int i = 0; i < m; ++i) {
            ss[i].lx1 = lower_bound(loc, loc + sz, ss[i].x1) - loc + 1;
            ss[i].lx2 = lower_bound(loc, loc + sz, ss[i].x2) - loc + 1;
        }
        sort(ss, ss + m);
        double last = 0, resu = 0;
        for (int i = 0; i < m; ++i) {
            adddata(1, 1, sz, ss[i].lx1, ss[i].lx2 - 1, ss[i].atag);
            if (i != m - 1) resu += fabs(stree[1]) * (ss[i + 1].y - ss[i].y);
            last = stree[1];
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", t++, resu);
    }
}
