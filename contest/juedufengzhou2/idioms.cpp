#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, d;
char cy[50007][5];
inline bool check(const char a[], const char b[]) {
    // int cnt = 0;
    // for (int i = 0; i < 4; ++i) {
    //     if (a[i] != b[i]) ++cnt;
    // }
    // printf("   %d\n", (int)(a[0] == b[0]));
    if (d == (
        (int)(a[0] == b[0]) + (int)(a[1] == b[1]) +
        (int)(a[2] == b[2]) + (int)(a[3] == b[3])
        )) return true;
    else return false;
}
/*
4 2
0000
a010
0202
a0e2
 */
int main() {
    freopen("idioms.in", "r", stdin);
    freopen("idioms.out", "w", stdout);
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cy[i]);
    }
    int gr = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (check(cy[i], cy[j])) ++gr;
        }
    }
    printf("%d\n", gr);
}
