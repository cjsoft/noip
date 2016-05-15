#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int dp[10][3];
int bit[10];
int l, r;
void init() {
    dp[0][0] = 1;
    for (int i = 1; i <= 7; ++i) {
        dp[i][0] = dp[i - 1][0] * 9 - dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][0] + dp[i - 1][1];
    }
}
int solve(int n) {
    int len = 0, ans = n;
    bool tag = false;
    memset(bit, 0, sizeof(bit));
    while (n) {
        bit[++len] = n % 10;
        n /= 10;
    }
    for (int i = len; i > 0; --i) {
        ans -= dp[i - 1][2] * bit[i];
        if (tag)
            ans -= dp[i - 1][0] * bit[i];
        if (!tag && bit[i] > 4)
            ans -= dp[i - 1][0];
        if (!tag && bit[i + 1] == 6 && bit[i] > 2)
            ans -= dp[i][1];
        if (!tag && bit[i] > 6)
            ans -= dp[i - 1][1];
        if (bit[i] == 4 || (bit[i] == 2 && bit[i + 1] == 6))
            tag = true;
    }
    return ans;
}
int main() {
    init();
    while (~scanf("%d %d", &l, &r) && l + r) printf("%d\n", solve(r + 1) - solve(l));
    return 0;
}