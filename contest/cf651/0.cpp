#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int a, b;
int main() {
    scanf("%d %d", &a, &b);
    int cnt = 0;
    while ((a + b > 2) && a && b) {
        // if (!a || !b) break;
        if (a + b == 3) {
            printf("%d\n", cnt + 1);
            return 0;
        }
        if (a > b) swap(a, b);
        if (a + b <= 3) break;
        if (a == b) {
            ++a; b -= 2;
            ++cnt;
            // printf("%d %d %d\n", a, b, cnt);
            continue;
        }
        ++a;
        b -= 2;
        ++cnt;
        // printf("%d %d %d\n", a, b, cnt);
        if (a > b) swap(a, b);
    }
    printf("%d", cnt);
    return 0;
}