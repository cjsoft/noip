#include <iostream>
#include <cstdio>
#include <cstring>
#define isrson(x) (x == x->p->c[RIGHT])
#define SIZE (cur - buffer)
using namespace std;
const int LEFT = 0, RIGHT = 1;
const int MXN = 100007;
struct node {
    node *c[2];
    node *p;
    int val;
    bool isrev;
    int size;
} _nil, *nil, *root, buffer[MXN], *cur;
inline node *newnode(int value, node *parent) {
    cur->p = parent;
    cur->val = value;
    cur->size = 1;
    cur->isrev = false;
    cur->c[LEFT] = cur->c[RIGHT] = nil;
    return cur++;
}
inline void update(node *x) {
    if (x == nil) return;
    x->size = x->c[LEFT]->size + x->c[RIGHT]->size + 1;
}
inline void init() {
    cur = buffer;
    nil = &_nil;
    root = newnode(-999, nil);
    root->c[RIGHT] = newnode(-999, root);
    update(root);
    nil->size = nil->val = 0;
    nil->isrev = false;
    nil->c[LEFT] = nil->c[RIGHT] = nil->p = nil;
}
inline void pushdown(node *x) {
    if (x->isrev && x != nil) {
        std::swap(x->c[LEFT], x->c[RIGHT]);
        x->isrev = false;
        x->c[LEFT]->isrev ^= 1;
        x->c[RIGHT]->isrev ^= 1;
    }
}
inline void rotate(node *x) {
    node *p = x->p, *z = x->p->p;
    int cp = isrson(x), cz = isrson(p);
    if (root != p) z->c[cz] = x;
    else root = x;
    p->c[cp] = x->c[!cp];
    x->c[!cp] = p;
    p->p = x;
    p->c[cp]->p = p;
    x->p = z;
    update(p);
    update(x);
}
node *stack[MXN];
int top;
inline void splay(node *x, node *y) {
    top = 0;
    stack[top++] = x;
    for (node *i = x; i->p != y; i = i->p) {
        stack[top++] = i;
    }
    while (top) pushdown(stack[--top]);
    for(; x->p != y; rotate(x))
        if (x->p->p != y)
            if (isrson(x) == isrson(x->p)) rotate(x->p);
            else rotate(x);
}
inline void swim(int k, node *y) {
    node *x = root;
    pushdown(x);
    while (k != x->c[LEFT]->size + 1) {
        if (k > x->c[LEFT]->size + 1) {
            k -= x->c[LEFT]->size + 1;
            x = x->c[RIGHT];
        } else {
            x = x->c[LEFT];
        }
        pushdown(x);
    }
    splay(x, y);
}
inline void append(int value) {
    swim(SIZE - 1, nil);
    root->c[RIGHT]->c[LEFT] = newnode(value, root->c[RIGHT]);
    update(root->c[RIGHT]);
    update(root);
}
inline void reverse(int l, int r) {
    swim(l, nil);
    swim(r + 2, root);
    root->c[RIGHT]->c[LEFT]->isrev ^= 1;
}
void output(node *x) {
    if (x == nil) return;
    pushdown(x);
    output(x->c[LEFT]);
    if (x->val != -999)
        printf("%d ", x->val);
    output(x->c[RIGHT]);
}
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    init();
    for (int i = 1; i <= n; ++i) {
        append(i);
    }
    int l, r;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &l, &r);
        reverse(l, r);
    }
    output(root);
}