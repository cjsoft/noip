#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define isrson(x) (x->parent->c[1] == x)
#define MXN 100007
typedef unsigned long long ull;
char input[MXN];
int glen = 0;
ull val[MXN];
struct node {
    int sz;
    ull ha;
    node *parent, *c[2];
    char s;
} _nil, buf[MXN], *cur, *nil, *root;
inline node *newnode(char s, node *parent) {
    cur->parent = parent;
    cur->c[1] = cur->c[0] = nil;
    cur->sz = 1;
    cur->s = s;
    cur->ha = (ull)s;
    return cur++;
}
inline void update(node *x) {
    x->sz = x->c[0]->sz + 1 + x->c[1]->sz;
    x->ha = x->c[0]->ha * val[x->c[1]->sz + 1] + (ull)x->s * val[x->c[1]->sz] + x->c[1]->ha;
}
inline void rotate(node *x) {
    if (x == root || x == nil) return;
    node *p = x->parent, *z = p->parent;
    int fx = isrson(x), fp = isrson(p);
    if (p == root) {
        root = x;
    } else {
        z->c[fp] = x;
    }
    p->c[fx] = x->c[fx ^ 1];
    p->c[fx]->parent = p;
    x->parent = z;
    p->parent = x;
    x->c[fx ^ 1] = p;
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
node *find(int k) {
    node *x = root;
    for (int dir = k > x->c[0]->sz + 1; x->c[0]->sz + 1 != k; x = x->c[dir], dir = k > x->c[0]->sz + 1) {
        if (dir) {
            k -= x->c[0]->sz + 1;
        }
    }
    return x;
}
void swim(int pos, node *y) {
    node *x = find(pos);
    splay(x, y);
}
bool check(int a, int b, int l) {
    ull ha1, ha2;
    swim(a, nil);
    if (root->c[1]->sz < l + 1) return false;
    swim(a + l + 1, root);
    ha1 = root->c[1]->c[0]->ha;
    swim(b, nil);
    if (root->c[1]->sz < l + 1) return false;
    swim(b + l + 1, root);
    ha2 = root->c[1]->c[0]->ha;
    return ha1 == ha2;
}

int lcq(int a, int b) {
    if (a > b) std::swap(a, b);
    int lL, rL, mid, dir;
    lL = 0;
    rL = glen - b + 1;
    for (mid = lL + ((rL - lL) >> 1), dir = check(a, b, mid); ; mid = lL + ((rL - lL) >> 1) ,dir = check(a, b, mid)) {
        if (dir && !check(a, b, mid + 1)) return mid;
        else if (dir) lL = mid + 1;
        else rL = mid;
    }
    return mid;
}
inline void edit(int pos, char nch) {
    swim(pos + 1, nil);
    root->s = nch;
    update(root);
}
inline void insert(int pos, char nch) {
    swim(pos + 1, nil);
    swim(pos + 2, root);
    root->c[1]->c[0] = newnode(nch, root->c[1]);
    update(root->c[1]);
    update(root);
    ++glen;
}
void init() {
    cur = buf;
    val[0] = 1;
    for (int i = 1; i < MXN; ++i) val[i] = val[i - 1] * 31;
    scanf("%s", input);
    glen = strlen(input);
    nil = &_nil;
    nil->s = '\0';
    nil->ha = 0;
    nil->sz = 0;
    nil->parent = nil->c[0] = nil->c[1] = nil;
    root = newnode('#', nil);
    root->c[1] = newnode('$', root);
    root->c[1]->c[0] = newnode(input[0], root->c[1]);
    node *p = root->c[1]->c[0];
    for (int i = 1; i < glen; ++i) {
        p->c[1] = newnode(input[i], p);
        p = p->c[1];
    }
    for (; p != nil; p = p->parent) update(p);
}
int main() {
    init();
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%s", input);
        if (input[0] == 'Q') {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", lcq(a, b));
        } else if (input[0] =='R') {
            int a;
            scanf("%d %s", &a, input);
            edit(a, input[0]);
        } else {
            int a;
            scanf("%d %s", &a, input);
            insert(a, input[0]);
        }
    }
}