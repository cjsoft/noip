#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int MXN = 200007;

stack<int> stk;

int fa[MXN];
char instack[MXN];
int dfn[MXN], low[MXN];
int curr = 1;

int n;
int global_resu = 0x7fffff;
void dfs(int x) {
    dfn[x] = low[x] = curr++;
    stk.push(x);
    instack[x] = 1;
    if (instack[fa[x]] == 0) {
        dfs(fa[x]);
        low[x] = std::min(low[fa[x]], low[x]);
    } else {
        if (instack[fa[x]] == 1) {
            low[x] = std::min(low[x], dfn[fa[x]]);
        }
    }
    if (low[x] == dfn[x]) {
        int cnt =  0;
        while (!stk.empty() && stk.top() != x) {
            instack[stk.top()] = 2;
            stk.pop();
            cnt++;
        }
        instack[stk.top()] = 2;
        stk.pop();
        cnt++;
        if (cnt > 1)
            global_resu = std::min(global_resu, cnt);
    }
}

int main() {
    scanf("%d", &n);
    memset(instack, 0, sizeof(instack));
    for (int i = 1; i <= n; i++) {
        scanf("%d", fa + i);
    }
    for (int i = 1; i <= n; i++) {
        if (instack[i] == 0) {
            dfs(i);
        }
    }
    printf("%d\n", global_resu);
    return 0;
}
