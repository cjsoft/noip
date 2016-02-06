#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int n, m;
int a[50007], b[50007];
int mam(int arr[], int na) {
    int resu = INT_MIN;
    for (int i = 1; i <= na; ++i) {
        resu = max(resu, arr[i]);
    }
    return resu;
}
int mim(int arr[], int na) {
    int resu = INT_MAX;
    for (int i = 1; i <= na; ++i) {
        resu = min(resu, arr[i]);
    }
    return resu;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", b + i);
    }
    // damn....
    // 我要乱搞，憋拦我
    // 肯定过不了
    // 我要颓
    printf("%d\n", min(mam(a, n) + mim(b, m), mim(a, n) + mam(b, m)));
    return 0;
}
