// Tree
// 树的点分治
#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 200007
#define iterate(x, i) for (edge *i = head[x]; i; i = i->prev)
int aaaa[MXN];
int *arr;
int son[MXN];
char supervis[MXN];
int tsiz = 0x7fffffff;
int center, global_resu = 0;
int n, k;
struct edge {
    edge *prev;
    int to, weight;
} buf[MXN << 1], *head[MXN], *cur;
void init();
inline void addedge(int from, int to, int weight);
void dfs(int root, int fa, int nnn) {
    son[root] = 0;
    // if (supervis[root] == 1) return;
    int tmp = 0;
    son[root] = 1;
    iterate(root, i) {
        if (i->to == fa || supervis[i->to]) continue;
        dfs(i->to, root, nnn);
        son[root] += son[i->to];
        tmp = std::max(tmp, son[i->to]);
    }
    if (std::max(tmp, nnn - son[root]) < tsiz) {
        center = root;
        tsiz = std::max(tmp, nnn - son[root]);
    }
}
void fill_into(int root, int fa, int length) {
    if (supervis[root] == 1) return;
    *(arr++) = length;
    iterate(root, i) {
        if (i->to == fa) continue;
        fill_into(i->to, root, length + i->weight);
    }
}
int count_(int a[], int l, int r) {
    // for (int i = l; i <= r; ++i) { //$%^
        // printf("%d ", a[i]); //$%^
    // } //$%^
    // puts(""); //$%^
    int rtn = 0;
    int i1 = l, i2 = r;
    for (i1 = l; i1 < i2; ++i1) {
        if (a[i1] > k) return 0;
        while (a[i1] + a[i2] > k) --i2;
        if (i1 >= i2) break;
        // printf("%d ", i2 - i1); //$%^
        rtn += i2 - i1;
    }
    // puts("%%%%%%"); //$%^
    // printf("--%d\n-----------------------------\n", rtn); //$%^
    return rtn;
}
int calc(int root, int length) {
    arr = aaaa;
    fill_into(root, center, length);
    std::sort(aaaa, arr);
    return count_(aaaa, 0, arr - aaaa - 1);
}
void qqsolve(int root, int fa, int nnn) {
    if (supervis[root]) return;
    center = root;
    tsiz = 0x7fffffff;
    // memset(son, 0, sizeof(son));
    dfs(center, 0, nnn);
    // printf("$%d\n", center); //$%^
    dfs(center, 0, nnn);
    // memset(aaaa, 0, sizeof(aaaa));
    global_resu += calc(center, 0);
    supervis[center] = 1;
    iterate(center, i) {
        if (supervis[i->to] == 1) continue;
        // memset(aaaa, 0, sizeof(aaaa));
        global_resu -= calc(i->to, i->weight);
    }
    iterate(center, i) {
        if (supervis[i->to] == 1) continue;
        qqsolve(i->to, center, son[i->to]);
    }
}
int main() {
    scanf("%d %d", &n, &k);
    while (n != 0) {
        init();
        int a, b, w;
        for (int i = 1; i < n; ++i) {
            scanf("%d %d %d", &a, &b, &w);
            addedge(a, b, w);
            addedge(b, a, w);
        }
        qqsolve(1, 0, n);
        printf("%d\n", global_resu);
        scanf("%d %d", &n, &k);
    }
    return 0;
}

void init() {
    memset(buf, 0, sizeof(buf));
    memset(head, 0, sizeof(head));
    // memset(aaaa, 0, sizeof(aaaa));
    arr = aaaa;
    memset(supervis, 0, sizeof(supervis));
    tsiz = 0x7fffffff;
    global_resu = 0;
    cur = buf;
}
inline void addedge(int a, int b, int w) {
    cur->to = b;
    cur->weight = w;
    cur->prev = head[a];
    head[a] = cur++;
}