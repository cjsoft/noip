#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 100000000
#define MXN 17
#define MXM 8207
int dp[MXN][MXM], st[MXM], mp[MXN];
int mask, n, m, x, k;
int main() {
    while (~scanf("%d %d", &n, &m)) {
        memset(dp, 0, sizeof(dp));
        memset(st, 0, sizeof(st));
        memset(mp, 0, sizeof(mp));
        mask = (1 << m) - 1, k = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &x);
                if (x) mp[i] |= 1 << j;
            }
        }
        for (int i = 0; i <= mask; ++i) if (!(i & (i << 1))) st[k++] = i;
        for (int i = 0; i < k; ++i)
            if (!(st[i] & ~mp[1])) dp[1][i] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < k; ++j) {
                if ((st[j] & ~mp[i])) continue;
                for (int l = 0; l < k; ++l) {
                    if (st[j] & st[l]) continue;
                    dp[i][j] += dp[i - 1][l];
                    dp[i][j] %= MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < k; ++i) ans += dp[n][i], ans %= MOD;
        printf("%d\n", ans);
    }
}