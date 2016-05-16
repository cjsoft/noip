#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 100007
using namespace std;
int sa[MXN], h[MXN], t1[MXN], t2[MXN], rank[MXN], c[MXN];

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


int main() {

    return 0;
}