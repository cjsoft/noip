// stuck now, not finished.

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define CLEAR(x) memset(x,0,sizeof(x))
const int MXN=30007;
using namespace std;
typedef long long ll;
int n;
struct edge
{
    int to,w;
    edge(int a){
        to=a;
    }
};

std::vector <int> v[MXN];
int nodeweight[MXN];
int c_sub_nodes[MXN];
int fa[MXN];
int h_son[MXN];
int head[MXN];
int dep[MXN];
int locator[MXN];
int revlocator[MXN];
int tot=2;

void dfs_1(int root, int from, int depth) {
    if (!from) {
        fa[root] = 0;
    } else {
        fa[root] = from;
    }
    dep[root]=depth;
    c_sub_nodes[root] = 0;
    for (int i = 0; i < v[root].size(); ++i) {
        if (v[root][i] == from) continue;
        dfs_1(v[root][i], root, depth + 1);
        c_sub_nodes[root] += c_sub_nodes[v[root][i]];
        if (c_sub_nodes[v[root][i]] >= c_sub_nodes[h_son[root]]) {
            h_son[root]=v[root][i];
        }
    }
    c_sub_nodes[root] += v[root].size() - 1;
}

void dfs_2(int root, int from) {
    if (h_son[root]) {
        head[h_son[root]] = head[root];
        locator[h_son[root]] = tot;
        revlocator[tot ++] = h_son[root];
        dfs_2(h_son[root], root);
    }
    for (int i = 0; i < v[root].size(); ++i) {
        if (v[root][i] == h_son[root] || v[root][i] == from) continue;
        head[v[root][i]] = root;
        locator[v[root][i]] = tot;
        revlocator[tot ++] = v[root][i];
        dfs_2(v[root][i], root);
    }
}

struct RMQ_QJH_XDS
{
    ll stree_rmq[MXN * 4 + 7];
    ll stree_qjh[MXN * 4 + 7];
    RMQ_QJH_XDS() {
        fill(stree_rmq, stree_rmq + MXN * 4 + 7, -9999999);
        fill(stree_qjh, stree_qjh + MXN * 4 + 7, 0);
    }
    inline int lson(int root) {
        return root << 1 ;
    }
    inline int rson(int root) {
        return root << 1 | 1 ;
    }
    void build(int root, int l, int r) {
        if (l == r) {
            stree_rmq[root] = nodeweight[locator[l]];
            stree_qjh[root] = nodeweight[locator[l]];
            return ;
        }
        int m = (l + r) >> 1;
        build(lson(root), l, m);
        build(rson(root), m + 1, r);
        stree_rmq[root] = std::max(stree_rmq[lson(root)],stree_rmq[rson(root)]);
        stree_qjh[root] = stree_qjh[lson(root)] + stree_qjh[rson(root)];
    }

    ll rmq_query(int root, int l, int r, int queryl, int queryr) {
        cout<<"stuck"<<l<<' '<<r<<endl;
        if (queryl > r || queryr < l) return -9999999;
        if (queryl >= l && queryr <= r) return stree_rmq[root];
        int m = (l + r) >> 1;
        return std::max(rmq_query(lson(root), l, m, queryl, queryr), rmq_query(rson(root), m + 1, r, queryl, queryr));
    }

    ll qjh_query(int root, int l, int r, int queryl, int queryr) {
        if (queryl > r || queryr < l) return 0;
        if (queryl >= l && queryr <= r) return stree_qjh[root];
        int m = (l + r) >> 1;
        return qjh_query(lson(root), l, m, queryl, queryr) + qjh_query(rson(root), m + 1, r, queryl, queryr);
    }

    void edit(int root, int l, int r, int pos, ll new_data) {
        if (l == r) {
            stree_qjh[root] = new_data;
            stree_rmq[root] = new_data;
            return ;
        }
        if (pos > ((l + r) >> 1)) {
            edit(rson(root), (l + r) >> 1 + 1, r, pos, new_data);
        } else {
            edit(lson(root), l, (l + r) >> 1, pos, new_data);
        }
        stree_rmq[root] = std::max(stree_rmq[lson(root)],stree_rmq[rson(root)]);
        stree_qjh[root] = stree_qjh[lson(root)] + stree_qjh[rson(root)];
    }
} slpf;
ll tree_rmq_query(int l, int r) {
    if(dep[l] < dep[r]) std::swap(l, r);
    while (head[l] != head[r]) l = fa[l];
    if (head[l] == head[r]) {
        if (locator[l] <= locator[r]) {
            return slpf.rmq_query(1, 1, tot - 1, locator[l], locator[r]);
        } else {
            return slpf.rmq_query(1, 1, tot - 1, locator[r], locator[l]);
        }
    }
    printf("ERR RMQ\n");
}
ll tree_qjh_query(int l, int r) {
    if(dep[l] < dep[r]) std::swap(l, r);
    while (head[l] != head[r]) l = fa[l];
    if (head[l] == head[r]) {
        if (locator[l] <= locator[r]) {
            return slpf.qjh_query(1, 1, tot - 1, locator[l], locator[r]);
        } else {
            return slpf.qjh_query(1, 1, tot - 1, locator[r], locator[l]);
        }
    }
    printf("ERR QJH\n");
}
int main() {
    CLEAR(nodeweight);
    CLEAR(c_sub_nodes);
    CLEAR(fa);
    CLEAR(h_son);
    CLEAR(head);
    CLEAR(dep);
    CLEAR(locator);
    CLEAR(revlocator);
    scanf("%d", &n);
    int tempa,tempb;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &tempa, &tempb);
        v[tempa].push_back(/*edge*/(tempb));
        v[tempb].push_back(/*edge*/(tempa));
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nodeweight[i]);
    }
    head[1] = 1;
    dfs_1(1, 0, 1);
    dfs_2(1, 0);
    locator[1] = 1;
    revlocator[1] = 1;
    slpf.build(1, 1, tot - 1);
    int q;
    char tc[11];
    scanf("%d", &q);

    for (int i = 0; i < q; ++i) {
        CLEAR(tc);
        scanf("%s %d %d", tc, &tempa, &tempb);
        if (tc[1] == 'M') {
            ll asd = tree_rmq_query(tempa, tempb);
            printf("%lld\n", asd);
        } else if (tc[1] == 'S') {
            printf("%lld\n", tree_qjh_query(tempa, tempb));
        } else {
            slpf.edit(1, 1, tot - 1, tempa, tempb);
        }
    }
}