#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 100007
using namespace std;
int a[MXN], b[MXN];
struct node {
  node *ls, *rs;
  int val;
  node() {
    ls = rs = NULL;
    val = 0;
  }
} buf[MXN * 20 + 7], *rt[MXN], *cur;
void Build(node *&root, int l, int r) {
  root = cur++;
  if (l == r) return;
  int mid = (l + r) >> 1;
  Build(root->ls, l, mid);
  Build(root->rs, mid + 1, r);
}
void Update(node *&root, int l, int r, node *last, int data) {
  root = cur++;
  root->ls = last->ls;
  root->rs = last->rs;
  root->val = last->val + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (data <= mid) Update(root->ls, l, mid, last->ls, data);
  else Update(root->rs, mid + 1, r, last->rs, data);
}
int Query(node *lr, node *rr, int l, int r, int k) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  int cnt = rr->ls->val - lr->ls->val;
  if (k <= cnt) return Query(lr->ls, rr->ls, l, mid, k);
  else return Query(lr->rs, rr->rs, mid + 1, r, k - cnt);
}

int main() {
  int T;
  T = 1;
  // scanf("%d", &T);
  while (T--) {
    cur = buf;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int sz = unique(b + 1, b + 1 + n) - b - 1;
    Build(rt[0], 1, sz);
    for (int i = 1; i <= n; ++i) {
      a[i] = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
      Update(rt[i], 1, sz, rt[i - 1], a[i]);
    }
    for (int i = 0; i < m; ++i) {
      int s, t, k;
      scanf("%d %d %d", &s, &t, &k);
      int ans = Query(rt[s - 1], rt[t], 1, sz, k);
      printf("%d\n", b[ans]);
    }
  }
  return 0;
}
