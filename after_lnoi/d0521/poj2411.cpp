#include <iostream>
#include <cstdio>
#include <cstring>
#define pick(a, i) ((a >> (i - 1)) & 1)
typedef long long ll;
int h, w;
ll dp[13][3007];
inline bool chklne1(int stat) {
    int i = 1;
    while (i <= w) {
        if (pick(stat, i)) {
            if (i == w || !pick(stat, i + 1)) return false;
            else i += 2;
        } else ++i;
    }
    return true;
}
inline bool validate(int stat1, int stat2) {
    int i = 1;
    while (i <= w) {
        if (pick(stat1, i)) {
            if (pick(stat2, i)) {
                if (i == w || !pick(stat1, i + 1) || !pick(stat2, i + 1)) return false;
                else i += 2;
            } else ++i;
        } else {
            if (pick(stat2, i)) ++i;
            else return false;
        }
    }
    return true;
}
int main() {
    while (~scanf("%d %d", &h, &w)) {
        if (!(h && w)) return 0;
        if (h < w) std::swap(h, w);
        int mask = (1 << w) - 1;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= mask; ++i) {
            if (chklne1(i)) dp[1][i] = 1;
        }
        for (int i = 2; i <= h; ++i) {
            for (int j = 0; j <= mask; ++j) {
                for (int k = 0; k <= mask; ++k) {
                    if (validate(j, k)) dp[i][j] += dp[i - 1][k];
                }
            }
        }
        printf("%lld\n", dp[h][mask]);
    }
}