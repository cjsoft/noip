#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 200007
using namespace std;
int sa[MXN], h[MXN], t1[MXN], t2[MXN], rank[MXN], c[MXN];
int l1, l2;
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
int main() {
    scanf("%s", rstr);
    l1 = strlen(rstr);
    scanf("%s", rstr + l1 + 1);
    l2 = strlen(rstr + l1 + 1);
    for (int i = 0; i < l1 + 1 + l2; ++i) sequ[i] = rstr[i] + 1;
    getsa(sequ, sa, l1 + l2 + 2, 128);
    getheight(sa, sequ, h, l1 + l2 + 1);
    int resumax = 0;
    for (int i = 1; i < l1 + l2 + 1; ++i)
        if ((sa[i] > l1 && sa[i - 1] < l1) || (sa[i] < l1 && sa[i - 1] > l1))
            resumax = std::max(h[i], resumax);
    printf("%d\n", resumax);
    return 0;
}
