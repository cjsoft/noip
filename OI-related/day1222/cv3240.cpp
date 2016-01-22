#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
ll dp[67][67];
int m, n;
int main() {
    scanf("%d %d", &m, &n);
    dp[1][0] = 1;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    printf("%lld\n", dp[m][n]);
    return 0;
}
