/**
 * Copyright 2015 CJSoft
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define CLEAR(x) memset(x, 0, sizeof(x))
const int MXN = 30007;
typedef long long ll; //NOLINT
int n;
struct edge {
    int to;
    explicit edge(int a) {
        to = a;
    }
};
std::vector <int> v[MXN];
int c_sub_nodes[MXN];
int fa[MXN];
int h_son[MXN];
int head[MXN];
int dep[MXN];
int locator[MXN];
int tot = 1;
void dfs_1(int root, int from, int depth) {
    if (!from) {
        fa[root] = 0;
    } else {
        fa[root] = from;
    }
    dep[root] = depth;
    c_sub_nodes[root] = 1;
    h_son[root] = 0;
    for (int i = 0; i < v[root].size(); ++i) {
        if (v[root][i] == from) continue;
        dfs_1(v[root][i], root, depth + 1);
        c_sub_nodes[root] += c_sub_nodes[v[root][i]];
        if (c_sub_nodes[v[root][i]] >= c_sub_nodes[h_son[root]]) {
            h_son[root] = v[root][i];
        }
    }
}
void dfs_2(int root, int hd) {
    locator[root] = tot++;
    head[root] = hd;
    if (h_son[root]) {
        dfs_2(h_son[root], hd);
    }
    for (int i = 0; i < v[root].size(); ++i) {
        if (v[root][i] == h_son[root] || v[root][i] == fa[root]) continue;
        dfs_2(v[root][i], v[root][i]);
    }
}
ll query(int l, int r) {
    ll resu = 0;
    while (head[l] != head[r]) {
        if (dep[head[l]] < dep[head[r]]) std::swap(l, r);
        resu += locator[l] - locator[head[l]] + 1;
        l = fa[head[l]];
    }
    resu += std::abs(locator[l] - locator[r]);
    return resu;
}
int main() {
    CLEAR(c_sub_nodes);
    CLEAR(fa);
    CLEAR(h_son);
    CLEAR(head);
    CLEAR(dep);
    CLEAR(locator);
    scanf("%d", &n);
    int tempa, tempb;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &tempa, &tempb);
        v[tempa].push_back(tempb);
        v[tempb].push_back(tempa);
    }
    dfs_1(1, 0, 1);
    dfs_2(1, 1);
    int q;
    scanf("%d", &q);
    int temp;
    scanf("%d", &temp);
    ll resu = 0;
    for (int i = 1; i < q; ++i) {
        int te;
        scanf("%d", &te);
        resu += query(te, temp);
        temp = te;
    }
    printf("%lld\n", resu);
    return 0;
}
