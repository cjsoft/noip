#include <iostream>
#include <cstdio>
#define MXN 50007
#define INF 0x3fffffff
int dp[2][107], h[MXN], n, c, *t1, *t2;

int main() {
    while (~scanf("%d %d", &n, &c)) {
        t1 = dp[1], t2 = dp[0];
        for (int i = 1; i <= n; ++i) scanf("%d", h + i);
        for (int i = 0; i <= 100; ++i) t1[i] = i < h[1] ? INF : (h[1] - i) * (h[1] - i);
        for (int i = 2; i <= n; ++i) {
            int asd = INF;
            for (int j = 0; j <= 100; ++j) {
                asd = std::min(t1[j] - j * c, asd);
                if (j < h[i]) t2[j] = INF;
                else t2[j] = asd + j * c + (h[i] - j) * (h[i] - j);
            }
            asd = INF;
            for (int j = 100; j >= 0; --j) {
                asd = std::min(t1[j] + j * c, asd);
                if (j >= h[i]) t2[j] = std::min(t2[j], asd - j * c + (h[i] - j) * (h[i] - j));
            }
            std::swap(t1, t2);
        }
        int resu = INF;
        for (int i = 0; i <= 100; ++i) resu = std::min(t1[i], resu);
        printf("%d\n", resu);
    }
}