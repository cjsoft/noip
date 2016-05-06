#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 100007
using namespace std;
char s[MXN];
int sequence[MXN];
int sa[MXN], h[MXN];
int t1[MXN], t2[MXN], c[MXN], rank[MXN];
void getsa(int raw[], int sa[], int n, int m) {
  int *x = t1, *y = t2;
  for (int i = 0; i < m; ++i) c[i] = 0;
  for (int i = 0; i < n; ++i) ++c[x[i] = raw[i]];
  for (int i = 1; i < m; ++i) c[i] += c[i - 1];
  for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
  for (int j = 1, p = 0, i = 0; j <= n && p < n - 1; j <<= 1, m = p + 1, p = 0) {
    for (i = n - j; i < n; ++i) y[p++] = i;
    for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < m; ++i) c[i] = 0;
    for (i = 0; i < n; ++i) ++c[x[y[i]]];
    for (i = 1; i < m; ++i) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
    for (i = 1, std::swap(x, y), p = 0, x[sa[0]] = 0; i < n; ++i)
      x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + j] == y[sa[i - 1] + j]) ? p : ++p;
  }
}
void getheight(int raw[], int sa[], int h[], int n) {
  int i, j, k;
  for (i = 1; i <= n; ++i) rank[sa[i]] = i;
  for (k = 0, i = 0; i < n; h[rank[i++]] = k)
    for (j = sa[rank[i] - 1], k ? --k : 0; raw[i + k] == raw[j + k]; ++k);
}
int main() {
  int l;
  scanf("%d", &l);
  scanf("%s", s);
  for (int i = 0; i < l; ++i) {
    sequence[i] = s[i] + 1;
  }
  getsa(sequence, sa, l + 1, 257);
  // getheight(sequence, sa, h, l);
  for (int i = 1; i <= l; ++i) {
    printf("%d\n", sa[i] + 1);
  }
  return 0;
}
