#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 20007
#define iterate(x, i) for (edge *i = head[x]; i; i = i->prev)
char supervis[MXN];
int tsiz = 0x7fffffff;
int center;
int n, k;
int global_resu = 0;
int *p, a[MXN], son[MXN];
struct edge {
    int w, to;
    edge *prev;
} buf[MXN], *head[MXN], *cur;
void addedge(int, int, int);
void dfs(int root, int fa, int nnn);
void fillintoArray(int root, int fa, int length);
int calc(int root, int length);
void qqsolve(int root, int nnn);
void init();
int main() {
    int a, b, v;
    while (~scanf("%d %d", &n, &k)) {
        if (n == 0) break;
        init();
        for (int i = 1; i < n; ++i) {
            scanf("%d %d %d", &a, &b, &v);
            addedge(a, b, v);
            addedge(b, a, v);
        }
        qqsolve(1, n);
        printf("%d\n", global_resu);
    }
}
void init() {
    memset(supervis, 0, sizeof(supervis));
    memset(son, 0, sizeof(son));
    memset(buf, 0, sizeof(buf));
    memset(head, 0, sizeof(head));
    global_resu = 0;
    cur = buf;
}
void dfs(int root, int fa, int nnn) {
    son[root] = 0;
    if (supervis[root]) return;
    if (!fa) tsiz = 0x7fffffff;
    son[root] = 1;
    int tmp = 0;
    iterate(root, i) {
        if (i->to == fa) continue;
        dfs(i->to, root, nnn);
        son[root] += son[i->to];
        tmp = std::max(tmp, son[i->to]);
    }
    tmp = std::max(tmp, nnn - son[root]);
    if (tmp < tsiz) {
        center = root;
        tsiz = tmp;
    }
}
void fillintoArray(int root, int fa, int length) {
    if (supervis[root]) return;
    (*p++) = length;
    iterate(root, i) {
        if (i->to == fa) continue;
        fillintoArray(i->to, root, length + i->w);
    }
}
int calc(int root, int length) {
    p = a;
    fillintoArray(root, 0, length);
    std::sort(a, p);
    int r = p - a - 1;
    int rtn = 0;
    for (int l = 0; l < r; ++l) {
        while (a[l] + a[r] > k) --r;
        if (l >= r) break;
        rtn += r - l;
    }
    return rtn;
}
void qqsolve(int root, int nnn) {
    if (supervis[root]) return;
    center = root;
    dfs(center, 0, nnn);
    dfs(center, center, nnn);
    global_resu += calc(center, 0);
    supervis[center] = 1;
    iterate(center, i) {
        global_resu -= calc(i->to, i->w);
    }
    iterate(center, i) {
        qqsolve(i->to, son[i->to]);
    }
}
void addedge(int a, int b, int w) {
    cur->to = b;
    cur->w = w;
    cur->prev = head[a];
    head[a] = cur++;
}