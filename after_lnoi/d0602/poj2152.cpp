#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 1007
#define iterate(x, i) for (edge *i = head[x]; i; i = i->prev)

struct edge {edge *prev; int to, weight;};
edge buf[MXN], *cur = buf, *head[MXN];
int d[MXN][MXN];
int best[MXN], dp[MXN][MXN];
inline void addedge(int a, int b, int w) {
    cur->prev = head[a];
    cur->weight = w;
    cur->to = b;
    head[a] = cur++;
}
int r;
void DIS(int root, int fa, int len) {
    d[r][root] = len;
    iterate(root, i) {
        if (i->to != fa) {
            DIS(i->to, root, len + i->w);
        }
    }
}
void dfs(int root, int fa) {
    
}