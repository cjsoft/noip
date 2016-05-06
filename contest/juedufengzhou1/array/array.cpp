#include <iostream>
#include <cstdio>
using namespace std;
int n;
int b[10000007];
inline int getint();
int mxa = -1;
int getK(int posn) {
    int last = b[posn];
    for (int i = posn - 1; i > 0; --i) {
        if (last < b[i]) return i + 1;
        last = b[i];
    }
    return 1;
}
int main() {
    freopen("array.in", "r", stdin);
    freopen("array.out", "w", stdout);
    n = getint();
    int pos = 1;
    for (int i = 1; i <= n; ++i) {
        b[i] = getint();
        printf("%d\n", i - getK(i) + 1);
        // if (i - getK(i) + 1 > mxa) pos = i;
        mxa = max(mxa, i - getK(i) + 1);
    }
    printf("%d\n", mxa);
    return 0;
}
inline int getint() {
    char ch = getchar();
    int data = 0;
    while (ch <'0' || ch > '9') ch = getchar();
    do {
        data = data * 10 + ch - 48;
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return data;
}