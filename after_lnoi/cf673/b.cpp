#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int arr[1000007];
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    // for (int i = 0; i < n; ++i) {
        // scanf("%d", arr + i);
    // }
    int a, b;
    int mx = 1, mn = n;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        if (a > b) std::swap(a, b);
        mx = std::max(mx, a);
        mn = std::min(mn, b);
        // if (arr[mx] < arr[a]) mx = a;
        // if (arr[mn] > arr[b]) mn = b;
    }
    if (mx > mn) puts("0");
    else {
        printf("%d\n", mn - mx);
    }
    return 0;
}
