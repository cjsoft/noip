#include <iostream>
#include <cstdio>
#include <cstring>
#define MXN 17
#define MXM 8207
#define MOD 100000000
int st[MXM], mp[MXN];
int dp[MXN][MXM];
int n, m, x;
inline bool check1(int x) {
    return (x & (x << 1));
}
inline bool check2(int a, int b) {
    return (mp[a] & st[b]);
}
int main() {
    while (~scanf("%d %d", &n, &m)) {
        memset(st, 0, sizeof(st));
        memset(mp, 0, sizeof(mp));
        memset(dp, 0, sizeof(dp));
        int x, k = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &x);
                if (!x) mp[i] |= 1 << (j - 1);
            }
        }
        for (int i = 0; i < (1 << m); ++i)
            if (!check1(i)) st[k++] = i;
        for (int i = 0; i < k; ++i)
            if (!check2(1, i))
                dp[1][i] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (check2(i, j)) continue;
                for (int l = 0; l < k; ++l) {
                    if (check2(i - 1, l)) continue;
                    if (!(st[j] & st[l]))
                        dp[i][j] = (dp[i][j] + dp[i - 1][l]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < k; ++i)
            ans = (dp[n][i] + ans) % MOD;
        printf("%d\n", ans);
    }
}