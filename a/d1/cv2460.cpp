#include <iostream>
#include <cstdio>
#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define parent(x) ((x) >> 1)
// #define update(x) stree[x] = stree[(x) << 1] + stree[(x) << 1 | 1]
#define mid(a, b) ((a + b) >> 1)
#define iterate(a, i) for (edge *i = ehd[a]; i; i = i->prev)
using namespace std;
const int MXN = 30007;
typedef long long ll;

int n, q;
struct edge {
    edge *prev;
    int to;
} *ehd[MXN], buffer[MXN << 1 | 1], *cur;

void addedge(int a, int b) {
    cur->to = b;
    cur->prev = ehd[a];
    ehd[a] = cur++;
}
int nodeweight[MXN];
int sz[MXN];
int locator[MXN];
int revlocator[MXN];
int hson[MXN];
int head[MXN];
int fa[MXN];
int dep[MXN];
int tot = 1;
void init() {
    for (int i = 1; i <= n; ++i) {
        dep[i] = sz[i] = 0;
        head[i] = i;
    }
}
void dfs1(int from) {
    dep[from] = dep[fa[from]] + 1;
    iterate(from, i) {
        if (i->to == fa[from]) continue;
        fa[i->to] = from;
        dfs1(i->to);
        sz[from] += sz[i->to];
        if (sz[i->to] >= sz[hson[from]]) hson[from] = i->to;
    }
    sz[from]++;
}
void dfs2(int from) {
    locator[from] = tot;
    revlocator[tot++] = from;
    if (hson[from]) {
        head[hson[from]] = head[from];
        dfs2(hson[from]);
    }
    iterate(from, i) {
        if (i->to == hson[from]) continue;
        head[i->to] = i->to;
    }
}

struct ST {
    ll streem[MXN << 2 | 1];
    ll strees[MXN << 2 | 1];
    ll raw[MXN];
    int innerlocator[MXN];
    inline void update(int root) {

    }
    inline void build(int root, int l, int r) {
        if (l == r) {
            streem[root] = strees[root] = raw[l];
            innerlocator[l] = root;
            return;
        }
        build(lson(root), l, mid(l, r));
        build(rson(root), mid(l, r) + 1, r);
        update(root);
    }
    inline ll querys(int root, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (l <= ql && r >= qr) return strees[root];
        return querys(lson(root), l, mid(l, r), ql, qr) +
               querys(rson(root), mid(l, r) + 1, r, ql, qr);
    }
    inline ll querym(int root, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return -30007;
        if (l <= ql && r >= qr) return streem[root];
        return std::max(querym(lson(root), l, mid(l, r), ql, qr),
               querym(rson(root), mid(l, r) + 1, r, ql, qr));
    }
    inline void edit(int pos, ll newdata) {
        pos = innerlocator[pos];
        strees[pos] = streem[pos] = newdata;
        while (parent(pos)) update(pos = parent(pos));
    }
} st;

int main() {
    cur = buffer;
    scanf("%d", &n);
    int a, b;
    init();
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", nodeweight + i);
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
        st.raw[i] = nodeweight[revlocator[i]];
    }
    st.build(1, 1, n);
    scanf("%d", &q);
    char op[10];
    while (q--) {
        scanf("%s", op);
        scanf("%d %d", &a, &b);
        if (op[1] == 'H') {
            st.edit(locator[a], b);
        } else if (op[1] == 'M') {

        } else if (op[1] == 'S') {

        }
     }
    return 0;
}