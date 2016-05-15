#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
#define mid(l, r) ((l + r) >> 1)
#define MXN 10007
using namespace std;
struct seg {
    int x1, x2, y, atag;
    seg() {x1 = x2 = y = atag = 0;}
    seg(int a, int b, int c, int d):x1(a),x2(b),y(c),atag(d) {}
    bool operator<(const seg &b) const {
        return y == b.y ? atag > b.atag : y < b.y;
    }
} ss[MXN];
int cnt[20000 << 2 | 7], lne[20000 << 2 | 7];
bool lbd[20000 << 2 | 7], rbd[20000 << 2 | 7];
int stree[20000 << 2 | 7];
inline void pushup(int root, int l, int r) {
    if (cnt[root]) {
        lbd[root] = rbd[root] = true;
        stree[root] = r - l + 1;
        lne[root] = 1;
    } else if (l == r) {
        lbd[root] = rbd[root] = false;
        lne[root] = stree[root] = 0;
    } else {
        stree[root] = stree[lson(root)] + stree[rson(root)];
        lne[root] = lne[lson(root)] + lne[rson(root)];
        if (rbd[lson(root)] && lbd[rson(root)]) --lne[root];
        lbd[root] = lbd[lson(root)];
        rbd[root] = rbd[rson(root)];
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
    int n;
    while (~scanf("%d", &n)) {
        int a, b, c, d;
        int m = 0;
        int lbd = 999999, rbd = -999999;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            lbd = std::min(lbd, a);
            rbd = std::max(rbd, c);
            ss[m++] = seg(a, c, b, 1);
            ss[m++] = seg(a, c, d, -1);
        }
        sort(ss, ss + m);
        int last = 0, resu = 0;
        for (int i = 0; i < m; ++i) {
            adddata(1, lbd, rbd - 1, ss[i].x1, ss[i].x2 - 1, ss[i].atag);
            if (i != m - 1) resu += (lne[1] << 1) * (ss[i + 1].y - ss[i].y);
            resu += std::abs(stree[1] - last);
            last = stree[1];
        }
        printf("%d\n", resu);
    }
}
