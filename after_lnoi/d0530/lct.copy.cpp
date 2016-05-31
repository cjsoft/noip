#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 200007
#define isrson(x) (x == x->parent->c[1])
#define isroot(x) (!(x->parent->c[0] == x || x->parent->c[1] == x))
struct node {int sz; bool isrev; node *parent, *c[2];} *nil, _nil;
inline void update(node *x) {x->sz = x->c[0]->sz + x->c[1]->sz + 1;}
inline void rev(node *x) {if (x != nil) std::swap(x->c[0], x->c[1]), x->isrev ^= 1;}
inline void pushdown(node *x) {if (x->isrev) rev(x->c[0]), rev(x->c[1]), x->isrev = false;};
inline void rotate(node *x) {
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
    node *p = a; tot = 0;
    for (; p != nil; p = p->parent) stk[tot++] = p;
    for (--tot; tot >= 0; --tot) pushdown(stk[tot]);
    while (a->parent != nil) a = a->parent;
    return a;
}
inline int getint();
node buf[MXN];
int n, m, a, b; char input[11];
inline void init();
int main() {
    n = getint(); m = getint();
    init();
    while (m--) {
        scanf("%s", input);
        a = getint(); b = getint();
        switch (input[0]) {
        case 'Q':
            if (findATRoot(buf + a) == findATRoot(buf + b)) puts("Yes");
            else puts("No");
            break;
        case 'C':
            link(buf + a, buf + b);
            break;
        case 'D':
            cut(buf + a, buf + b);
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
    nil->sz = 0;
    nil->parent = nil->c[0] = nil->c[1] = nil;
    nil->isrev = false;
    for (int i = 1; i <= n; ++i) {
        buf[i].sz = 1;
        buf[i].isrev = false;
        buf[i].parent = buf[i].c[0] = buf[i].c[1] = nil;
    }
}