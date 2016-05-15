#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
std::vector<int> *mp;
int p, n;
int from[407];
char tag[407];

bool match(int root) {
  if (!root) return true;
  for (int i = 0; i < mp[root].size(); ++i) {
    if (tag[mp[root][i]] == 0) {
      tag[mp[root][i]] = 1;
      if (!from[mp[root][i]] || match(from[mp[root][i]])) {
        from[mp[root][i]] = root;
        return true;
      }
    }
  }
  return false;
}

int xyl() {
  int res = 0;
  memset(from, 0, sizeof from);
  for (int i = 1; i <= p; ++i)
  {
    memset(tag, 0, sizeof tag);
    if (match(i)) ++res;
  }
  return res;
}

void initialize() {
  mp = new std::vector<int>[407];
}
void finalize() {
  delete[] mp;
  mp = 0;
}

void solveATestCase() {
  scanf("%d %d", &p, &n);
  initialize();
  int c, s;
  for (int i = 1; i <= p; ++i) {
    scanf("%d", &c);
    for (int j = 1; j <= c; ++j) {
      scanf("%d", &s);
      mp[i].push_back(s);
    }
  }
  if (xyl() == p) {
    puts("YES");
  } else {
    puts("NO");
  }
  finalize();
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solveATestCase();
  }
  return 0;
}