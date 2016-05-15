#include <iostream>
#include <cstdio>
#include <cstring>
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
#define mid(l, r) ((l + r) >> 1)
using namespace std;
int stree[400007][7];
int tag[400007];
int raw[100007];
int temp[7];
inline void update(int root) {
  for (int i = 0; i < 7; ++i) {
    stree[root][i] = stree[lson(root)][i] + stree[rson(root)][i];
  }
}
inline void pushdown(int root, int l, int r) {
  if (tag[root]) {
    tag[lson(root)] += tag[root];
    tag[rson(root)] += tag[root];
    tag[lson(root)] %= 7;
    tag[rson(root)] %= 7;
    for (int i = 0; i < 7; ++i) {
      temp[i] = stree[lson(root)][i];
    }
    for (int i = 0; i < 7; ++i) {
      stree[lson(root)][i] = temp[(i + 7 - tag[root]) % 7];
    }
    for (int i = 0; i < 7; ++i) {
      temp[i] = stree[rson(root)][i];
    }
    for (int i = 0; i < 7; ++i) {
      stree[rson(root)][i] = temp[(i + 7 - tag[root]) % 7];
    }
    tag[root] = 0;
  }
  update(root);
}
void build(int root, int l, int r) {
  if (l == r) {
    stree[root][raw[l] % 7] = 1;
    return;
  }
  build(lson(root), l, mid(l, r));
  build(rson(root), mid(l, r) + 1, r);
  update(root);
}
void add(int root, int l, int r, int addl, int addr, int adddata) {
  if (l > addr || r < addl) return;
  if (l >= addl && r <= addr) {
    tag[root] += adddata;
    tag[root] %= 7;
    for (int i = 0; i < 7; ++i) {
      temp[i] = stree[root][i];
    }
    for (int i = 0; i < 7; ++i) {
      stree[root][i] = temp[(i + 7 - (adddata % 7)) % 7];
    }
    return;
  }
  // pushdown(root, l, r);
  add(lson(root), l, mid(l, r), addl, addr, adddata);
  add(rson(root), mid(l, r) + 1, r, addl, addr, adddata);
  pushdown(root, l, r);
}
int query(int root, int l, int r, int ql, int qr, int k) {
  if (l > qr || r < ql) return 0;
  if (l >= ql && r <= qr) return stree[root][k];
  pushdown(root, l, r);
  return query(lson(root), l, mid(l, r), ql, qr, k) +
         query(rson(root), mid(l, r) + 1, r, ql, qr, k);
}
int main() {
  int n, q, a, b, c;
  char ipt[7];
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", raw + i);
  }
  build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    scanf("%s %d %d", ipt, &a, &b);
    if (ipt[0] == 'c') {
      printf("%d\n", query(1, 1, n, a, b, 0));
    } else {
      scanf("%d", &c);
      add(1, 1, n, a, b, c);
    }
  }
  return 0;
}
// 4 8 9
