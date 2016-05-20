#include <iostream>
#include <cstdio>
#define MXN 50007
#define INF 0x3fffffff

int dp[MXN][107], h[MXN], q[107];
int n, c;
int main() {
    while (~scanf("%d %d", &n, &c)) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", h + i);
        for (int i = 0; i <= 100; ++i)
            dp[1][i] = (i < h[1]) ? INF : (h[1] - i) * (h[1] - i);
        for (int i = 2; i <= n; ++i) {
            int tail = 0;
            for (int j = 0; j <= 100; ++j) {
                int f = dp[i - 1][j] - j * c;
                while (tail && f < q[tail - 1]) --tail;
                q[tail++] = f;
                if (j < h[i]) dp[i][j] = INF;
                else dp[i][j] = q[0] + j * c + (h[i] - j) * (h[i] - j);
            }
            tail = 0;
            for (int j = 100; j >= 0; --j) {
                int f = dp[i - 1][j] + j * c;
                while (tail && f < q[tail - 1]) --tail;
                q[tail++] = f;
                if (j >= h[i]) dp[i][j] = std::min(dp[i][j], q[0] - j * c + (h[i] - j) * (h[i] - j));
            }
        }
        int resu = INF;
        for (int i = 0; i <= 100; ++i) resu = std::min(resu, dp[n][i]);
        printf("%d\n", resu);
    }
}