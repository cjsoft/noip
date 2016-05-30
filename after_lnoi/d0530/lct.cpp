#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>
#define MXN 200007
#define INF 0x3f3f3f3f
#define isrson(x) (x == x->parent->c[1])
int n, m;
inline int getint();
struct node {
    int sz;
    int id;
    bool isrev;
    node *parent, *c[2];
} buf[MXN], *cur, *root, *nil, _nil;
node *locator[MXN];
inline bool isroot(node *x);
inline void rev(node *x) {
    if (x == nil) return;
    std::swap(x->c[0], x->c[1]);
    x->isrev ^= 1;
    // if (x->c[0] != nil) x->c[0]->isrev ^= 1;
    // if (x->c[1] != nil) x->c[1]->isrev ^= 1;
}
void pushdown(node *x) {
    if (x->isrev) {
        x->isrev = false;
        rev(x->c[0]);
        rev(x->c[1]);
    }
}
inline node *newnode(int id, node *parent) {
    cur->parent = parent;
    locator[id] = cur;
    cur->id = id;
    cur->sz = 1;
    cur->isrev = false;
    cur->c[0] = cur->c[1] = nil;
    return cur++;
}
void update(node *x) {
    x->sz = x->c[0]->sz + x->c[1]->sz + 1;
}
inline void rotate(node *x) {
    // if (x == nil || isroot(x) || x->parent == nil)
        // puts("+");
    node *p = x->parent, *z = p->parent;
    int fx = isrson(x), fp = isrson(p);
    if (!isroot(p)) z->c[fp] = x;
    x->parent = z;
    p->c[fx] = x->c[fx ^ 1];
    x->c[fx ^ 1] = p;
    p->c[fx]->parent = p;
    p->parent = x;
    update(p);
    // update(x);
}
node *stk[MXN]; int top;
bool isroot(node *x) {
    // if (x == nil)
        // puts("=");
    // assert(x != nil);
    if (x->parent->c[0] == x || x->parent->c[1] == x) return false;
    return true;
}
void splay(node *x) {
    top = 0;
    node *p = x;
    while (!isroot(p)) {
        stk[top++] = p;
        p = p->parent;
    }
    stk[top++] = p;
    for (int i = top - 1; i >= 0; --i) pushdown(stk[i]);
    for (; !isroot(x); rotate(x)) {
        if (!isroot(x->parent)) {
            if (isrson(x) == isrson(x->parent)) rotate(x->parent);
            else rotate(x);
        }
    }
    update(x);
}
node *access(node *x) {
    node *p = nil;
    for (; x != nil; p = x, x = x->parent) {
        splay(x);
        x->c[1] = p;
        if (x->c[1] != nil) x->c[1]->parent = x;
        // p->isroot = false;
    }
    return p;
}
// node *findroot(node *x) {
    // access(x); splay(x);
    // while (x->c[0] != nil) x = x->c[0];
    // return x;
// }
void makeroot(node *x) {
    access(x); splay(x); rev(x);
}
void link(node *a, node *b) {
    makeroot(b);
    b->parent = a;
    access(b);
    // puts("link");
}
void cut(node *a, node *b) {
    makeroot(a); access(b); splay(b);
    b->c[0]->parent = nil;
    b->c[0] = nil;
}
node *findroot(node *x) {
    while (x->parent != nil) x = x->parent;
    return x;
}
inline void init() {
    cur = buf;
    nil = &_nil;
    nil->sz = 0;
    nil->parent = nil->c[0] = nil->c[1] = nil;
    nil->isrev = false;
    nil->id = -1;
    for (int i = 1; i <= n; ++i) {
        locator[i] = newnode(i, nil);
    }
}
char input[11];
int main() {
    n = getint(); m = getint();
    // printf("%d %d \n", n, m);
    init();
    int a, b;
    while (m--) {
        scanf("%s", input);
        a = getint(); b = getint();
        switch (input[0]) {
        case 'Q':
            if (findroot(locator[a]) == findroot(locator[b])) puts("Yes");
            else puts("No");
            break;
        case 'C':
            link(locator[a], locator[b]);
            break;
        case 'D':
            cut(locator[a], locator[b]);
            
        }
    }
    return 0;
}
int getint() {
    int f = 1, rtn;
    char ch;
    while ((ch = getchar()) > '9' || ch < '0') if (ch == '-') f = -1;
    rtn = ch - 48;
    while ((ch = getchar()) <= '9' && ch >= '0') rtn = rtn * 10 + ch - 48;
    return rtn * f;
}