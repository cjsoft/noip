#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 500007
#define INF 0x3f3f3f3f
#define iterate(x, i) for (edge *i = head[x]; i; i = i->prev)
int n, d, m;
int c[MXN][21], dpu[MXN][21], dpd[MXN][21], fa[MXN], w[MXN];
struct edge {edge *prev; int to;};
edge buf[MXN << 1], *head[MXN], *cur = buf;
inline void addedge(int a, int b) {
    cur->prev = head[a];
    cur->to = b;
    head[a] = cur++;
}
void dfs(int x) {
    int flag = 0;
    iterate(x, i) {
        if (i->to == fa[x]) continue;
        flag = 1;
        fa[i->to] = x;
        dfs(i->to);
        for (int j = 1; j <= d; ++j)
            c[x][j] |= c[i->to][j - 1];
    }
    if (!flag) {
        dpu[x][0] = dpd[x][0] = w[x] * c[x][0];
        for (int i = 1; i <= d; ++i) {
            dpu[x][i] = w[x];
            dpd[x][i] = 0;
        }
        return;
    }
    for (int i = 1; i <= d; ++i) {
        dpd[x][i] = 0;
        iterate(x, j) {
            if (j->to != fa[x])
                dpd[x][i] += dpd[j->to][i - 1];
        }
    }
    dpu[x][d] = 0;
    iterate(x, i) {
        if (i->to != fa[x])
            dpu[x][d] += dpd[i->to][d];
    }
    dpu[x][d] += w[x];
    for (int j = d - 1; j >= 0; --j) {
        int s = 0;
        iterate(x, i) {
            if (i->to != fa[x])
                s += dpd[i->to][j];
        }
        dpu[x][j] = dpu[x][j + 1];
        iterate(x, i) {
            if (i->to != fa[x])
                dpu[x][j] = std::min(dpu[x][j], dpu[i->to][j + 1] + s - dpd[i->to][j]);
        }
    }
    dpd[x][0] = dpu[x][0];
    for (int i = 1; i <=d; ++i) {
        dpd[x][i] = std::min(dpd[x][i], dpd[x][i - 1]);
    }
    for (int i = d - 1; i >= 0; --i) {
        if (!c[x][i]) dpd[x][i] = std::min(dpd[x][i], dpd[x][i + 1]);
    }
    dpu[x][0] = dpd[x][0];
}
int main() {
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; ++i) scanf("%d", w + i);
    scanf("%d", &m);
    int q, w, e;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &q);
        c[q][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &w, &e);
        addedge(w, e);
        addedge(e, w);
    }
    dfs(1);
    printf("%d\n", dpd[1][0]);
    return 0;
}