#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>
#define isrson(x) (x->parent->c[1] == x)
#define MXN 100007
 
typedef unsigned long long ull;
ull val[100007];
int glen;
struct node {
    node *parent, *c[2];
    ull ha;
    char s;
    int sz;
} buf[200007], *cur, *root, _nil, *nil;
node *newnode(node *parent, char s) {
    cur->sz = 1;
    cur->parent = parent;
    cur->c[0] = cur->c[1] = nil;
    cur->s = s;
    cur->ha = (ull)s;
    return cur++;
}
inline void update(node *x) {
    if (!x || x == nil) return;
    x->sz = x->c[0]->sz + x->c[1]->sz + 1;
    x->ha = x->c[0]->ha * val[x->c[1]->sz + 1] + x->c[1]->ha + x->s * val[x->c[1]->sz];
}
char input[MXN];
void init() {
    cur = buf;
    val[0] = 1;
    for (int i = 1; i <100007; ++i) val[i] = val[i - 1] * 31;
    nil = &_nil;
    nil->sz = 0;
    nil->ha = 0;
    nil->s = '\0';
    nil->parent = nil->c[0] = nil->c[1] = nil;
    root = newnode(nil, '#');
    root->c[1] = newnode(root, '$');
    update(root);
    scanf("%s", input);
    glen = strlen(input);
    node *p;
    root->c[1]->c[0] = p = newnode(root->c[1], input[0]);
    for (int i = 1; i < glen; ++i) {
        p->c[1] = newnode(p, input[i]);
        p = p->c[1];
    }
    for (; p != nil; p = p->parent) update(p);
}
inline void rotate(node *x) {
    if (x == nil || x == root) return;
    node *p = x->parent, *z = x->parent->parent;
    int fx = isrson(x), fp = isrson(p);
    p->c[fx] = x->c[!fx];
    p->c[fx]->parent = p;
    x->c[!fx] = p;
    p->parent = x;
    x->parent = z;
    if (p == root) {
        root = x;
    }
    else {
        z->c[fp] = x;
    }
    update(p);
    update(x);
}
 
inline void splay(node *x, node *y) {
    for (; x->parent != y; rotate(x)) {
        if (x->parent->parent != y) {
            if (isrson(x) == isrson(x->parent)) rotate(x->parent);
            else rotate(x);
        }
    }
}
inline node *findk(int k) {
    node *x = root;
    while (x->c[0]->sz + 1 != k) {
        int dir = k > x->c[0]->sz + 1;
        if (dir) {
            k -= x->c[0]->sz + 1;
        }
        x = x->c[dir];
    }
    return x;
}
inline void swim(int k, node *y) {
    node *x = findk(k);
    splay(x, y);
}
inline void edit(int pos, char nch) {
    swim(pos + 1, nil);
    root->s = nch;
    update(root);
}
inline void add(int pos, char nch) {
    swim(pos + 1, nil);
    swim(pos + 2, root);
    root->c[1]->c[0] = newnode(root->c[1], nch);
    update(root->c[1]);
    glen++;
    update(root);
}
inline bool check(int a, int b, int l) {
    ull ha1, ha2;
    swim(a, nil);
    swim(a + l + 1, root);
    ha1 = root->c[1]->c[0]->ha;
    swim(b, nil);
    swim(b + l + 1, root);
    ha2 = root->c[1]->c[0]->ha;
    return ha1 == ha2;
}
int lcq(int a, int b) {
    if (a > b) std::swap(a, b);
    int rL = glen - b + 1;
    int lL = 0;
    int mid = lL + ((rL - lL) >> 1);
    bool dir = check(a, b, mid);
    while (1) {
        if (mid >= glen - b + 1 || (dir && !check(a, b, mid + 1))) {
            return mid;
        }
        else {
            if (dir) {
                lL = mid + 1;
            }
            else {
                rL = mid;
            }
        }
        mid = lL + ((rL - lL) >> 1);
        dir = check(a, b, mid);
    }
    return mid;
}
int main() {
    init();
    int m;
    scanf("%d", &m);
    char input[3];
    for (int i = 0; i < m; ++i) {
        scanf("%s", input);
        if (input[0] == 'Q') {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", lcq(a, b));
        }
        else if (input[0] == 'R') {
            int a;
            scanf("%d %s", &a, input);
            edit(a, input[0]);
        }
        else {
            int a;
            scanf("%d %s", &a, input);
            add(a, input[0]);
        }
    }
}