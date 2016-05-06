#include <iostream>
#include <cstdio>
#include <cstring>
typedef long long ll;
ll p;
int n;
ll mny[1000007];
ll jiecheng[1000007];
int sz[2000007];
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll temp = exgcd(b, a % b, x, y);
  ll tx = x, ty = y;
  x = ty;
  y = tx - a / b * ty;
  return temp;
}
void init_jiecheng() {
  jiecheng[1] = 1;
  for (int i = 2; i < 1000007; ++i) {
    jiecheng[i] = (jiecheng[i - 1] * i) % p;
  }
}
ll moniyuan(ll a) {
  if (mny[a]) return mny[a];
  ll x, y;
  ll t = exgcd(jiecheng[a], p, x, y);
  x %= p;
  if (x < 0) x += p;
  mny[a] = x;
  return x;
}
void dfs_1(int root) {
  if (root > n) return;
  dfs_1(root << 1);
  dfs_1(root << 1 | 1);
  sz[root] = sz[root << 1] + sz[root << 1 | 1] + 1;
  return;
}
ll C(ll m, ll n) {
  if (m == n) return 1;
  return moniyuan(m - n) * moniyuan(n) % p * jiecheng[m] % p;
}
ll dfs_2(int root) {
  if (sz[root] == 1 || root > n) return 1;
  ll a = dfs_2(root << 1), b = dfs_2(root << 1 | 1);
  return a * b % p * C(sz[root] - 1, sz[root << 1]) % p;
}
int main() {
  memset(sz, 0, sizeof(sz));
  memset(mny, 0, sizeof(mny));
  memset(jiecheng, 0, sizeof(jiecheng));
  scanf("%d %lld", &n, &p);
  init_jiecheng();
  dfs_1(1);
  printf("%lld\n", dfs_2(1));
  return 0;
}
