#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 200007
#define INF 0x3f3f3f3f
#define isrson(x) (x == x->parent->c[1])
#define isroot(x) (!(x->parent->c[0] == x || x->parent->c[1] == x))
struct node {int sz, sum, mmm, data; bool isrev; node *parent, *c[2];} *nil, _nil;
inline void update(node *x) {
    if (x == nil) return;
    x->sz = x->c[0]->sz + x->c[1]->sz + 1;
    x->sum = x->c[0]->sum + x->c[1]->sum + x->data;
    x->mmm = std::max(x->data, std::max(x->c[0]->mmm, x->c[1]->mmm));
}
inline void rev(node *x) {if (x != nil) std::swap(x->c[0], x->c[1]), x->isrev ^= 1;}
inline void pushdown(node *x) {if (x->isrev) rev(x->c[0]), rev(x->c[1]), x->isrev = false;};
inline void rotate(node *x) {
    if (isroot(x))
        puts("------------");
    node *p = x->parent, *z = p->parent;
    int fx = isrson(x), fp = isrson(p);
    if (!isroot(p)) z->c[fp] = x;
    p->parent = x;
    p->c[fx] = x->c[fx ^ 1];
    x->c[fx ^ 1] = p;
    p->c[fx]->parent = p;
    x->parent = z;
    update(p);
}
node *stk[MXN], *pcur; int tot;
void splay(node *x) {
    tot = 0;
    for (pcur = x; !isroot(pcur); pcur = pcur->parent) stk[tot++] = pcur;
    for (stk[tot] = pcur; tot >= 0; --tot) pushdown(stk[tot]);
    for (; !isroot(x); rotate(x)) {
        if (!isroot(x->parent)) {
            if (isrson(x) == isrson(x->parent)) rotate(x->parent);
            else rotate(x);
        }
    }
    update(x);
}
void expose(node *x) {
    node *p = nil;
    for (; x != nil; p = x, x = x->parent) {
        splay(x);
        x->c[1] = p;
        update(x);
        if (p != nil) p->parent = x;
    }
}
void makeroot(node *a) {
    expose(a); splay(a); rev(a);
}
void link(node *a, node *b) {
    makeroot(b); b->parent = a; expose(b);
}
void cut(node *a, node *b) {
    makeroot(a); expose(b); splay(b);
    b->c[0]->parent = nil;
    b->c[0] = nil;
}
node *findATRoot(node *a) {
    while (a->parent != nil) a = a->parent;
    return a;
}
inline int getint();
node buf[MXN];
int n, m, a[MXN], b[MXN], c, d; char input[11];
inline void init();
int main() {
    n = getint();
    init();
    for (int i = 1; i < n; ++i) {
        a[i] = getint(); b[i] =getint();
    }
    for (int i = 1; i <= n; ++i) {
        buf[i].sum = buf[i].mmm = buf[i].data = getint();
        buf[i].sz = 1;
        buf[i].isrev = false;
        buf[i].parent = buf[i].c[0] = buf[i].c[1] = nil;
    }
    for (int i = 1; i < n; ++i) link(buf + a[i], buf + b[i]);
    makeroot(buf + 3);
    expose(buf + 4);
    m = getint();
    while (m--) {
        scanf("%s", input);
        c = getint(); d = getint();
        if (input[1] == 'H') {
            expose(buf + c);
            splay(buf + c);
            buf[c].data = d;
            update(buf + c);
        } else if (input[1] == 'M') {
            makeroot(buf + c);
            expose(buf + d);
            splay(buf + d);
            printf("%d\n", buf[d].mmm);
        } else {
            makeroot(buf + c);
            expose(buf + d);
            splay(buf + d);
            printf("%d\n", buf[d].sum);
        }
    }
}

int getint() {
    int f = 1, rtn;
    char ch;
    while ((ch = getchar()) > '9' || ch < '0') if (ch == '-') f = -1;
    rtn = ch - 48;
    while ((ch = getchar()) <= '9' && ch >= '0') rtn = rtn * 10 + ch - 48;
    return f * rtn;
}
void init() {
    nil = &_nil;
    nil->sum = 0;
    nil->data = 0;
    nil->mmm = -INF;
    nil->sz = 0;
    nil->parent = nil->c[0] = nil->c[1] = nil;
    nil->isrev = false;
}