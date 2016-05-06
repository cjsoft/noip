#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
std::stack <int> arr, pos;
int a[200007], b[200007], n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::fill_n(b, 200007, 0);
  for (int i = n - 1; i >= 0; --i) {
    if (arr.empty()) {
      arr.push(a[i]);
      pos.push(i);
    } else {
      while (a[i] < arr.top()) {
        b[pos.top()] = a[i];
        arr.pop();pos.pop();
        if (arr.empty()) break;
      }
      arr.push(a[i]);
      pos.push(i);
    }
  }
  for (int i = 0; i < n; ++i)
  {
    printf("%d\n", b[i]);
  }
  return 0;
}