#include <iostream>
#include <cstdio>
#include <cstring>

#define MXN 1007
int dp[MXN][MXN], w[MXN], s[MXN], n, m;
int q[MXN * 11];
int Up(int a, int b, int i) {return dp[i - 1][a] + s[a] * s[a] - w[a] - dp[i - 1][b] - s[b] * s[b] + w[b];}
int Down(int a, int b) {return s[a] - s[b];}
int Dp(int a, int b, int i) {return dp[i][a] = dp[i - 1][b] + w[a] - w[b] - s[b] * (s[a] - s[b]);}
int main() {
    while (~scanf("%d %d", &n, &m)) {
        if (n == 0) break;
        memset(dp, 0, sizeof(dp));
        memset(w, 0, sizeof(w));
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", s + i);
            w[i] += w[i - 1] + s[i - 1] * s[i];
            s[i] += s[i - 1];
            dp[1][i] = w[i];
        }
        for (int i = 2; i <= m + 1; ++i) {
            int head = 0, tail = 0;
            q[tail++] = i - 1;
            for (int j = i; j <= n; ++j) {
                while (tail > head + 1 && Up(q[head + 1], q[head], i) < s[j] * Down(q[head + 1], q[head])) 
                    ++head;
                if (tail > head) 
                    Dp(j, q[head], i);
                while (tail > head + 1 && Up(j, q[tail - 1], i) * Down(q[tail - 1], q[tail - 2]) <= Up(q[tail - 1], q[tail - 2], i) * Down(j, q[tail - 1])) 
                    --tail;
                q[tail++] = j;
            }
        }
        printf("%d\n", dp[m + 1][n]);
    }
}