#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 230007
#define mid(l, r) (l + ((r - l) >> 1))
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
int sa[MXN], h[MXN], t1[MXN], t2[MXN], rank[MXN], c[MXN];
int l1;
char rstr[MXN];
int sequ[MXN];
void getsa(int raw[], int sa[], int n, int m) {
    int *x = t1, *y = t2, i, j, p;
    for (i = 0; i < m; ++i) c[i] = 0;
    for (i = 0; i < n; ++i) ++c[x[i] = raw[i]];
    for (i = 1; i < m; ++i) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
    for (j = 1, p = 0; j <= n && p < n - 1; j <<= 1, m = p + 1, p = 0) {
        for (i = n - j; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < m; ++i) c[i] = 0;
        for (i = 0; i < n; ++i) ++c[x[y[i]]];
        for (i = 1; i < m; ++i) c[i] += c[i - 1];
        for (i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
        for (i = 1, p = 0, std::swap(x, y), x[sa[0]] = 0; i < n; ++i)
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + j] == y[sa[i - 1] + j]) ? p : ++p;
    }
}
void getheight(int sai[], int raw[], int h[], int n) {
    int i, j, k;
    for (i = 0; i <= n; ++i) rank[sa[i]] = i;
    for (i = 0, k = 0; i < n; h[rank[i++]] = k)
        for (j = sa[rank[i] - 1], k ? --k : 0; raw[i + k] == raw[j + k]; ++k);
}
int stree[MXN << 2];
void build(int root, int l, int r) {
    if (l == r) {
        stree[root] = h[l];
        return;
    }
    build(lson(root), l, mid(l, r));
    build(rson(root), mid(l, r) + 1, r);
    stree[root] = std::min(stree[lson(root)], stree[rson(root)]);
}
int query(int root, int l, int r, int ql, int qr) {
    if (ql > qr) std::swap(ql, qr);
    if (ql > r || qr < l) return 0x7fffffff;
    if (l >= ql && r <= qr) return stree[root];
    return std::min(query(lson(root), l, mid(l, r), ql, qr), query(rson(root), mid(l, r) + 1, r, ql, qr));
}
int main() {
    while (~scanf("%s", rstr)) {
        memset(rank, 0, sizeof(rank));
        memset(sa, 0, sizeof(sa));
        memset(h, 0, sizeof(h));
        memset(sequ, 0, sizeof(sequ));
        l1 = strlen(rstr);
        for (int i = 0; i < l1; ++i) sequ[i] = rstr[i] + 1, sequ[l1 * 2 - i] = rstr[i] + 1;
        sequ[l1] = 1;
        // for (int i = 0; i <= l1 * 2; ++i) printf("%03d ", sequ[i]);
        //     putchar('\n');
        getsa(sequ, sa, l1 * 2 + 2, 128);
        getheight(sa, sequ, h, l1 * 2 + 1);
        build(1, 1, l1 * 2 + 1);
        int m = 0, res = 0, tmp, z = 0x7fffffff;
        for (int i = 0; i < l1; ++i) {
            int l, r;
            l = rank[i], r = rank[l1 * 2 - i];
            if (l > r) std::swap(l, r);
            tmp = (query(1, 1, l1 * 2 + 1, l + 1, r) << 1) - 1;
            if (tmp > res) {
                m = i;
                res = tmp;
            }
            l = rank[i + 1], r = rank[l1 * 2 - i];
            if (l > r) std::swap(l, r);
            tmp = query(1, 1, l1 * 2 + 1, l + 1, r) << 1;
            if (tmp > res) {
                m = i + 1;
                res = tmp;
            }
        }
        printf("%d\n", res);
        int q = m - res / 2;
        for (int i = q; i < q + res; ++i)
            putchar(rstr[i]);
        putchar('\n');
        memset(rstr, 0, sizeof(rstr));
    }
    return 0;
}
