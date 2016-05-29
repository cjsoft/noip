// 曾出现的bug原因
//  1.  isrson写错
//  2.  rotate的fx写错
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mid(l, r) (l + ((r - l) >> 1))
#define isrson(x) (x->parent->c[1] == x)
#define MXN 500007
#define INF 0x3f3f3f3f
struct node {int sz, data, sum, msum, mpreffix, msuffix, v; bool isrev; node *parent, *c[2];};
node buf[MXN], *pool[MXN], *nil, *root, _nil;
int ptot, arr[MXN];
int n, m;
int pos, tot;
inline int getint();
inline void update(node *x);
inline void pushdown(node *x);
inline node *newnode(int s, node *parent);
node *build(int l, int r, node *parent);
inline void recycle(node *x);
void destroy(node *x);
node *find(int k);
inline void rotate(node *x);
void splay(node *x, node *y);
void swim(int pos, node *y);
void init();
void INSERT();
void DELETE();
void MAKE_SAME();
void REVERSE();
void GET_SUM();
void MAX_SUM();
int main() {
    char input[11];
    n = getint(); m = getint();
    init();
    while (m--) {
        scanf("%s", input);
        if (input[0] == 'I') INSERT();
        else if (input[0] == 'D') DELETE();
        else if (input[2] == 'K') MAKE_SAME();
        else if (input[0] == 'R') REVERSE();
        else if (input[0] == 'G') GET_SUM();
        else MAX_SUM();
    }
    return 0;
}
int getint() {
    int rtn = 0, f = 1;
    char ch;
    while ((ch = getchar()) < '0' || ch > '9') {if (ch == '-') f = -1;}
    rtn = ch - 48;
    while ((ch = getchar()) >= '0' && ch <= '9') {rtn *= 10; rtn += ch - 48;}
    return rtn * f;
}
void update(node *x) {
    if (x == nil) return;
    x->sz = x->c[0]->sz + x->c[1]->sz + 1;
    x->sum = x->c[0]->sum + x->c[1]->sum + x->data;
    x->msum = std::max(x->c[0]->msum, x->c[1]->msum);
    x->msum = std::max(x->msum, x->c[0]->msuffix + x->data + x->c[1]->mpreffix);
    x->mpreffix = std::max(x->c[0]->mpreffix, x->c[0]->sum + x->data + x->c[1]->mpreffix);
    x->msuffix = std::max(x->c[1]->msuffix, x->c[0]->msuffix + x->data + x->c[1]->sum);
}
void pushdown(node *x) {
    if (x->v != INF) {
        if (x->c[0] != nil) {
            x->c[0]->data = x->v;
            x->c[0]->sum = x->v * x->c[0]->sz;
            x->c[0]->mpreffix = x->c[0]->msuffix = x->v >= 0 ? x->c[0]->sum : 0;
            x->c[0]->msum = x->v >= 0 ? x->c[0]->sum : x->v;
            x->c[0]->v = x->v;
        }
        if (x->c[1] != nil) {
            x->c[1]->data = x->v;
            x->c[1]->sum = x->v * x->c[1]->sz;
            x->c[1]->mpreffix = x->c[1]->msuffix = x->v >= 0 ? x->c[1]->sum : 0;
            x->c[1]->msum = x->v >= 0 ? x->c[1]->sum : x->v;
            x->c[1]->v = x->v;
        }
        x->v = INF;
    }
    if (x->isrev) {
        if (x->c[0] != nil) {
            std::swap(x->c[0]->c[0], x->c[0]->c[1]);
            std::swap(x->c[0]->mpreffix, x->c[0]->msuffix);
            x->c[0]->isrev ^= 1;
        }
        if (x->c[1] != nil) {
            std::swap(x->c[1]->c[0], x->c[1]->c[1]);
            std::swap(x->c[1]->mpreffix, x->c[1]->msuffix);
            x->c[1]->isrev ^= 1;
        }
        x->isrev = false;
    }
}
node *newnode(int s, node *parent) {
    pool[--ptot]->data = s;
    pool[ptot]->sum = pool[ptot]->msum = s;
    pool[ptot]->mpreffix = pool[ptot]->msuffix = s >= 0 ? s : 0;
    pool[ptot]->sz = 1;
    pool[ptot]-> v = INF;
    pool[ptot]->isrev = false;
    pool[ptot]->parent = parent;
    pool[ptot]->c[0] = pool[ptot]->c[1] = nil;
    return pool[ptot];
}
node *build(int l, int r, node *parent) {
    if (l > r) return nil;
    if (l == r) {
        node *p = newnode(arr[l], parent);
        return p;
    }
    node *p = newnode(arr[mid(l, r)], parent);
    p->c[0] = build(l, mid(l, r) - 1, p);
    p->c[1] = build(mid(l, r) + 1, r, p);
    update(p);
    return p;
}
void recycle(node *x) {
    pool[ptot++] = x;
}
void destroy(node *x) {
    if (!x || x == nil) return;
    destroy(x->c[0]);
    destroy(x->c[1]);
    recycle(x);
}
node *find(int k) {
    int dir; node *x;
    for (x = root, pushdown(x), dir = k > x->c[0]->sz + 1; k != x->c[0]->sz + 1; x = x->c[dir], pushdown(x), dir = k > x->c[0]->sz + 1)
        if (dir) k -= x->c[0]->sz + 1;
    return x;
}
void rotate(node *x) {
    if (x == root || x == nil) return;
    node *p = x->parent, *z = p->parent;
    int fx = isrson(x), fp = isrson(p);
    if (root == p) root = x;
    else z->c[fp] = x;
    p->c[fx] = x->c[fx ^ 1];
    x->c[fx ^ 1] = p;
    x->parent = z;
    p->c[fx]->parent = p;
    p->parent = x;
    update(p);
    update(x);
}
void splay(node *x, node *y) {
    for (; x->parent != y; rotate(x)) {
        if (x->parent->parent != y) {
            if (isrson(x) == isrson(x->parent)) rotate(x->parent);
            else rotate(x);
        }
    }
}
void swim(int pos, node *y) {
    splay(find(pos), y);
}
void init() {
    ptot = MXN - 1;
    pool[0] = buf;
    for (int i = 1; i < MXN; ++i) pool[i] = pool[i - 1] + 1;
    nil = &_nil;
    nil->parent = nil->c[0] = nil->c[1] = nil;
    nil->data = nil->sz = 0;
    nil->sum = nil->mpreffix = nil->msuffix =0;
    nil->msum = -INF;
    nil->v = INF;
    nil->isrev = false;
    root = newnode(0, nil);
    root->c[1] = newnode(0, root);
    for (int i = 0; i < n; ++i) arr[i] = getint();
    root->c[1]->c[0] = build(0, n - 1, root->c[1]);
    update(root->c[1]);
    update(root);
}
void INSERT() {
    pos = getint(); tot = getint();
    swim(pos + 1, nil);
    swim(pos + 2, root);
    for (int i = 0; i < tot; ++i) arr[i] = getint();
    root->c[1]->c[0] = build(0, tot - 1, root->c[1]);
    update(root->c[1]);
    update(root);
}
void DELETE() {
    pos = getint(); tot = getint();
    swim(pos, nil);
    swim(pos + tot + 1, root);
    destroy(root->c[1]->c[0]);
    root->c[1]->c[0] = nil;
    update(root->c[1]);
    update(root);
}
void MAKE_SAME() {
    pos = getint(); tot = getint(); int c = getint();
    swim(pos, nil);
    swim(pos + tot + 1, root);
    root->c[1]->c[0]->data = root->c[1]->c[0]->v = c;
    root->c[1]->c[0]->sum = root->c[1]->c[0]->sz * c;
    root->c[1]->c[0]->msum = c >= 0 ? root->c[1]->c[0]->sum : c;
    root->c[1]->c[0]->mpreffix = root->c[1]->c[0]->msuffix = c >= 0 ? root->c[1]->c[0]->sum : 0;
    root->c[1]->c[0]->isrev = false;
    update(root->c[1]);
    update(root);
}
void REVERSE() {
    pos = getint(); tot = getint();
    swim(pos, nil);
    swim(pos + tot + 1, root);
    if (root->c[1]->c[0]->v != INF) return;
    std::swap(root->c[1]->c[0]->c[0], root->c[1]->c[0]->c[1]);
    std::swap(root->c[1]->c[0]->mpreffix, root->c[1]->c[0]->msuffix);
    root->c[1]->c[0]->isrev ^= 1;
}
void GET_SUM() {
    pos = getint(); tot = getint();
    swim(pos, nil);
    swim(pos + tot + 1, root);
    printf("%d\n", root->c[1]->c[0]->sum);
}
void MAX_SUM() {
    swim(1, nil);
    swim(root->sz, root);
    printf("%d\n", root->c[1]->c[0]->msum);
}
