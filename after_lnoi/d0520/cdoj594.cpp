#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MXN 50007

int q[107];
int h[MXN];
int dp[MXN][107];
int head, tail, nowf;
int c, n;
int main() {
    while (~scanf("%d %d", &n, &c)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", h + i);
        }
        for (int i = 0; i < h[1]; ++i)
            dp[1][i] = 0x3fffffff;
        for (int i = h[1]; i <= 100; ++i)
            dp[1][i] = (i - h[1]) * (i - h[1]);
        for (int i = 2; i <= n; ++i) {
            head = tail = 0;
            for (int j = 0; j <= 100; ++j) {
                nowf = dp[i - 1][j] - j * c;
                while (tail > head && q[tail - 1] > nowf)
                    --tail;
                q[tail++] = nowf;
                if (j < h[i])
                    dp[i][j] = 0x3fffffff;
                else
                    dp[i][j] = q[head] + j * c + (h[i] - j) * (h[i] - j);
            }
            head = tail = 0;
            for (int j = 100; j >= 0; --j) {
                nowf = dp[i - 1][j] + j * c;
                while (tail > head && q[tail - 1] > nowf)
                    --tail;
                q[tail++] = nowf;
                if (j >= h[i])
                    dp[i][j] = std::min(dp[i][j], q[head] - j * c + (h[i] - j) * (h[i] - j));
            }
        }
        int resu = 0x3fffffff;
        for (int i = 0; i <= 100; ++i)
            resu = std::min(resu, dp[n][i]);
        printf("%d\n", resu);
    }
    return 0;
}