#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MXN 500007
#define isrson(x) (x == x->parent->c[1])
#define mid(l, r) (l + ((r - l) >> 1))
int pos, tot, c, pcur;
int n, m;
char input[11];
struct node {
    int sum, mprefix, msuffix, msum;
    int sz, data, v;
    bool isrev;
    node *parent, *c[2];
} buf[MXN], *pool[MXN], *nil, *root, _nil;
inline int getint() {
    int rtn = 0, f = 1;
    char ch;
    while ((ch = getchar()) < '0' || ch > '9') {if (ch == '-') f = -1;}
    rtn = ch - 48;
    while ((ch = getchar()) >= '0' && ch <= '9') {rtn *= 10; rtn += ch - 48;}
    return rtn * f;
}
inline void update(node *x) {
    if (x == nil) return;
    x->sz = x->c[0]->sz + 1 + x->c[1]->sz;
    x->sum = x->c[0]->sum + x->c[1]->sum + x->data;
    x->msum = std::max(x->c[0]->msum, x->c[1]->msum);
    x->msum = std::max(x->msum, x->c[0]->msuffix + x->data + x->c[1]->mprefix);
    x->mprefix = std::max(x->c[0]->mprefix, x->c[0]->sum + x->data + x->c[1]->mprefix);
    x->msuffix = std::max(x->c[1]->msuffix, x->c[0]->msuffix + x->data + x->c[1]->sum);
}
node *newnode(int s, node *parent) {
    --pcur;
    pool[pcur]->data = pool[pcur]->sum = s;
    pool[pcur]->parent = parent;
    pool[pcur]->c[0] = pool[pcur]->c[1] = nil;
    pool[pcur]->isrev = false;
    pool[pcur]->sz = 1;
    pool[pcur]->v = INF;
    pool[pcur]->mprefix = pool[pcur]->msuffix = s >= 0 ? s : 0;
    pool[pcur]->msum = s;
    return pool[pcur];
}
inline void recycle(node *x) {
    pool[pcur++] = x; 
}
void init() {
    pool[0] = buf;
    pcur = MXN - 1;
    for (int i = 1; i < MXN; ++i) pool[i] = pool[i - 1] + 1;
    nil = &_nil;
    nil->parent = nil->c[0] = nil->c[1] = nil;
    nil->isrev = false;
    nil->data = nil->sz = nil->sum = nil->mprefix = nil->msuffix = 0;
    nil->msum = -INF;
    nil->v = INF;
    root = newnode(-INF, nil);
    root->c[1] = newnode(-INF, root);
    update(root);
}
inline void pushdown(node *x) {
    if (x == nil) return;
    if (x->v != INF) {
        if (x->c[0] != nil) {
            x->c[0]->sum = x->c[0]->mprefix = x->c[0]->msuffix = x->c[0]->msum = x->v * x->c[0]->sz;
            x->c[0]->data = x->v;
            x->c[0]->v = x->v;
        }
        if (x->c[1] != nil) {
            x->c[1]->sum = x->c[1]->mprefix = x->c[1]->msuffix = x->c[1]->msum = x->v * x->c[1]->sz;
            x->c[1]->data = x->v;
            x->c[1]->v = x->v;
        }
        if (x->v < 0) {
            if (x->c[0] != nil) x->c[0]->mprefix = x->c[0]->msuffix = 0, x->c[0]->msum = x->v;
            if (x->c[1] != nil) x->c[1]->mprefix = x->c[1]->msuffix = 0, x->c[1]->msum = x->v;
        }
        x->v = INF;
    }
    if (x->isrev) {
        if (x->c[0] != nil) {
            std::swap(x->c[0]->c[0], x->c[0]->c[1]);
            std::swap(x->c[0]->mprefix, x->c[0]->msuffix);
            x->c[0]->isrev ^= 1; 
        }
        if (x->c[1] != nil) {
            std::swap(x->c[1]->c[0], x->c[1]->c[1]);
            std::swap(x->c[1]->mprefix, x->c[1]->msuffix);
            x->c[1]->isrev ^= 1; 
        }
        x->isrev = false;
    }
}
void destroy(node *x) {
    if (x == nil) return;
    destroy(x->c[0]);
    destroy(x->c[1]);
    recycle(x);
}
inline void rotate(node *x) {
    node *p = x->parent, *z = p->parent;
    int fx = isrson(x), fp = isrson(p);
    if (p == root) root = x;
    else z->c[fp] = x;
    p->c[fx] = x->c[fx ^ 1];
    x->c[fx ^ 1] = p;
    p->c[fx]->parent = p;
    x->c[fx ^ 1]->parent = x;
    x->parent = z;
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
node *findk(int k) {
    node *x; int dir;
    for (x = root, pushdown(x), dir = k > x->c[0]->sz + 1; k != x->c[0]->sz + 1; x = x->c[dir], pushdown(x), dir = k > x->c[0]->sz + 1) if (dir) k -= x->c[0]->sz + 1;
    return x;
}
void swim(int pos, node *y) {
    node *x = findk(pos);
    splay(x, y);
}
int arr[MXN];
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
node *createLinkSequence(int len) {
    for (int i = 0; i < len; ++i) arr[i] = getint();
    return build(0, len - 1, nil);
}
void INSERT() {
    pos = getint(); tot = getint();
    swim(pos + 1, nil);
    swim(pos + 2, root);
    root->c[1]->c[0] = createLinkSequence(tot);
    root->c[1]->c[0]->parent = root->c[1];
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
    pos = getint(); tot = getint(); c = getint();
    swim(pos, nil);
    swim(pos + tot + 1, root);
    root->c[1]->c[0]->data = c;
    root->c[1]->c[0]->sum = c * root->c[1]->c[0]->sz;
    root->c[1]->c[0]->mprefix = root->c[1]->c[0]->msuffix = (c >= 0) ? (c * root->c[1]->c[0]->sz) : 0;
    root->c[1]->c[0]->msum = (c >= 0) ? (c * root->c[1]->c[0]->sz) : c;
    root->c[1]->c[0]->v = c;
    update(root->c[1]);
    update(root);
}
void REVERSE() {
    pos = getint(); tot = getint();
    swim(pos, nil);
    swim(pos + tot + 1, root);
    if (root->c[1]->c[0]->v != INF) return;
    std::swap(root->c[1]->c[0]->c[0], root->c[1]->c[0]->c[1]);
    std::swap(root->c[1]->c[0]->mprefix, root->c[1]->c[0]->msuffix);
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
int main() {
    init();
    n = getint(); m = getint();
    root->c[1]->c[0] = createLinkSequence(n);
    root->c[1]->c[0]->parent = root->c[1];
    update(root->c[1]); update(root);
    for (int i = 0; i < m; ++i) {
        scanf("%s", input);
        if (input[0] == 'I') INSERT();
        else if (input[0] == 'D') DELETE();
        else if (input[2] == 'K') MAKE_SAME();
        else if (input[0] == 'R') REVERSE();
        else if (input[0] == 'G') GET_SUM();
        else MAX_SUM();
    }
}