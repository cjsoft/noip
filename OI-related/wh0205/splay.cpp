#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int SZN = 100007;
struct splaytree {
  int root;
  int tot;
  int ls[SZN], rs[SZN], pr[SZN];
  int data[SZN];
  int sz[SZN];
  splaytree() {
    tot = root = 0;
    memset(ls, 0, sizeof(ls));
    memset(rs, 0, sizeof(rs));
    memset(pr, 0, sizeof(pr));
    memset(sz, 0, sizeof(sz));
    memset(data, 0, sizeof(data));
  }
  void update(int &x) {
    if (x) {
      sz[x] = sz[ls[x]] + sz[rs[x]] + 1;
    }
  }
  int newNode(int parent, int value) {
    ++tot;
    ls[tot] = rs[tot] = 0;
    sz[tot] = 1;
    pr[tot] = parent;
    data[tot] = value;
    return tot;
  }
  void zuoxuan(int &x) {
    int p = pr[x];
    rs[p] = ls[x];
    pr[rs[p]] = p;
    ls[x] = p;
    pr[x] = pr[p];
    if (ls[pr[p]] == p) {
      ls[pr[p]] = x;
    } else {
      rs[pr[p]] = x;
    }
    pr[p] = x;
    update(p);
    update(x);
    if (root == p) root = x;
  }
  void youxuan(int &x) {
    int p = pr[x];
    ls[p] = rs[x];
    pr[ls[p]] = p;
    rs[x] = p;
    pr[x] = pr[p];
    if (rs[pr[p]] == p) {
      rs[pr[p]] = x;
    } else {
      ls[pr[p]] = x;
    }
    pr[p] = x;
    update(p);
    update(x);
    if (root == p) root = x;
  }
  void splay(int &x, int &y) {
    while (pr[x] != y) {
      if (pr[pr[x]] == y) {
        if (ls[pr[x]] == x) { // x is lson
          youxuan(x);
        } else {
          zuoxuan(x);
        }
      } else if (ls[pr[pr[x]]] == pr[x]) {
        if (ls[pr[x]] == x) {
          youxuan(pr[x]);
          youxuan(x);
        } else {
          zuoxuan(x);
          youxuan(x);
        }
      } else {
        if (rs[pr[x]] == x) { // x is rson
          zuoxuan(pr[x]);
          zuoxuan(x);;
        } else {
          youxuan(x);
          zuoxuan(x);
        }
      }
    }
    update(x);
  }
  int find(int k, int y) {
    int x = root;
    while (k != sz[ls[x]] + 1) {
      if (k < sz[ls[x]]) {
        x = ls[x];
      } else {
        k -= sz[ls[x]] + 1;
        x = rs[x];
      }
    }
    splay(x, y);
  }
  void insert(int x, int da) {
    if (root == 0) {
      root = newNode(0, da);
      return;
    }

    
    find(x, 0);
    update(root);
    if (sz[root] >= x + 1)
      find(x + 1, root);
    ls[rs[root]] = newNode(rs[root], da);
    update(rs[root]);
  }

} sp;

int main() {
  for (int i = 0; i < 10; i++) {
    sp.insert(i, i + 5);
  }
  printf("%d\n", sp.data[sp.find(3, sp.root)]);
  return 0;
}
