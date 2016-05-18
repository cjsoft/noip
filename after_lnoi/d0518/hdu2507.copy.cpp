#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#define MXN 500007
int s[MXN], dp[MXN], n, m;
int Up(int, int);
int Down(int, int);
int Dp(int, int);
int main() {
    while (~scanf("%d %d", &n, &m)) {
        std::deque <int> q;
        memset(s, 0, sizeof(s));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", s + i);
            s[i] += s[i - 1];
        }
        q.push_back(0);
        for (int i = 1; i <= n; ++i) {
            while (q.size() >= 2 && Up(q[1], q.front()) <= s[i] * Down(q[1], q.front())) q.pop_front();
            if (!q.empty()) Dp(i, q.front());
            while (q.size() >= 2 && Up(i, q.back()) * Down(q.back(), q[q.size() - 2]) <= Up(q.back(), q[q.size() - 2]) * Down(i, q.back())) q.pop_back();
            q.push_back(i);
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
int Up(int a, int b) {
    return dp[a] + s[a] * s[a] - dp[b] - s[b] * s[b];
}
int Down(int a, int b) {
    return (s[a] - s[b]) << 1;
}
int Dp(int a, int b) {
    return dp[a] = dp[b] + m + (s[b] - s[a]) * (s[b] - s[a]);
}