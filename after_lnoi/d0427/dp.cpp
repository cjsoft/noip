#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int arr[100007];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    char ipt[7];
    int a, b, c;
    scanf("%s %d %d", ipt, &a, &b);
    if (ipt[0] == 'c') {
      int cnt = 0;
      for (int i = a; i <= b; ++i) {
        if (arr[i] % 7 == 0) ++cnt;
      }
      printf("%d\n", cnt);
    } else {
      scanf("%d", &c);
      for (int i = a; i <= b; ++i) {
        arr[i] += c;
        arr[i] %= 7;
      }
    }
  }
return 0;
}
