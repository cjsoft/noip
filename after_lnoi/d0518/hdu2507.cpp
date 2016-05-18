#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
typedef long long ll;
std::deque <ll> q;
int n, m;
ll s[500007];
ll dp[500007];
ll Up(int, int);
ll Down(int, int);
ll Dp(int, int);
void init(int);
int main() {
    while (~scanf("%d %d", &n, &m)) {
        init(n);
        for (int i = 1; i <= n; ++i) {
            scanf("%I64d", s + i);
            s[i] += s[i - 1];
        }
        dp[1] = s[1] * s[1] + m;
        q.push_back(0);
        for (int i = 1; i <= n; ++i) {
            while (q.size() >= 2 && Up(q[1], q.front()) <= s[i] * Down(q[1], q.front())) {
                // printf("  %d\n", q[1]);
                // printf("--- %I64d %d\n", dp[i], q.size());
                q.pop_front();
            }
            if (!q.empty())
                Dp(i, q.front());
            // printf("%I64d %d\n", dp[i], q.size());
            while (q.size() >= 2 /*&& 1, printf("--- %I64d %d\n *** %I64d %I64d\n", dp[i], q.back(), Up(i, q.back()) * Down(q.back(), q[q.size() - 2]), Up(q.back(), q[q.size() - 2]) * Down(i, q.back())) */&& Up(i, q.back()) * Down(q.back(), q[q.size() - 2]) <= Up(q.back(), q[q.size() - 2]) * Down(i, q.back())) {
                // ;
                // printf("  %d\n", q[1]);
                q.pop_back();
            }
            q.push_back(i);
                // printf("  %d\n", q.size());
        }
        printf("%I64d\n", dp[n]);
    }
}

ll Up(int a, int b) {
    return dp[a] + s[a] * s[a] - dp[b] - s[b] * s[b];
}
ll Down(int a, int b) {
    return (s[a] << 1) - (s[b] << 1);
}
ll Dp(int a, int b) {
    return dp[a] = dp[b] + (s[a] - s[b]) * (s[a] - s[b]) + m;
}
void init(int n) {
    memset(s, 0, sizeof(s));
    memset(dp, 0, sizeof(dp));
    q.clear();
}