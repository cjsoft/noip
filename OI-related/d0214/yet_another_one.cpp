#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define islson(x) (x->parent->child[0] == x)
#define isrson(x) (x->parent->child[1] == x)
using namespace std;

const int LEFT = 0;
const int RIGHT = 1;
const int MXN = 100007;
const int MXM = 50007;
const int INF = 0x7fffffff;

struct splaytree {
    struct node {
        int value, size;
        node *parent, *child[2];
    } *nil, _nil, *root, buffer[MXN], *cur;
    splaytree() {
        nil = &_nil;
        _nil.parent = nil;
        _nil.child[LEFT] = _nil.child[RIGHT] = nil;
        _nil.size = _nil.value = 0;
        root = nil;
        cur = buffer;
    }
    void print(node *x) {
        if (x == nil) return;
        print(x->child[LEFT]);
        printf("  - %d\n", x->value);
        print(x->child[RIGHT]);
    }
    inline node *newnode(int value, node *parent) {
        cur->parent = parent;
        cur->value = value;
        cur->size = 1;
        cur->child[LEFT] = cur->child[RIGHT] = nil;
        return cur++;
    }
    inline void update(node *x) {
        if (x == nil) return;
        x->size = x->child[LEFT]->size + x->child[RIGHT]->size + 1;
    }
    inline int f(node *x) {
        if (root == x || x == nil) return -1;
        return isrson(x); 
    }
    inline void rotate(node *x, int dir) {
        if (x->parent == nil) return;
        node *p = x->parent;
        x->parent = p->parent;
        p->child[!dir] = x->child[dir];
        x->child[dir]->parent = p;
        if (islson(p)) {
            p->parent->child[LEFT] = x;
        } else {
            p->parent->child[RIGHT] = x;
        }
        x->child[dir] = p;
        p->parent = x;
        update(p);
        update(x);
        if (root == p) root = x;
    }
   /* inline void rotate(node *x) {
        node *p = x->parent, *z = x->parent->parent;
        int k = f(x), fz = f(p);
        if (fz >= 0) z->child[fz] = x;
        else root = x;
        p->child[k] = x->child[!k];
        x->child[!k] = p;
        p->child[k]->parent = p;
        x->child[!k]->parent = x;
        x->parent = z;
        update(p);
        update(x);
    }*/
    void rotate(node *x) {
        if (x == nil || x == root) return;
        node *p = x->parent, *z = x->parent->parent;
        int fx = isrson(x), fp = isrson(p);
        p->child[fx] = x->child[!fx];
        p->child[fx]->parent = p;
        x->child[!fx] = p;
        if (p == root) {
            root = x;
            x->parent = nil;
        } else {
            z->child[fp] = x;
            x->parent = z;
        }
        p->parent = x;
        update(p);
        update(x);
    }
    // inline void splay(node *x, node *y) {
    //     for (; x->parent != y; rotate(x)) {
    //         if (x->parent->parent != y)
    //             if (f(x->parent) == f(x)) rotate(x->parent);
    //             else rotate(x);
    //     }
    // }
    void splay(node *x, node *y) {
        for (; x->parent != y; rotate(x))
            if (x->parent->parent != y) {
                if (isrson(x) == isrson(x->parent)) rotate(x->parent);
                else rotate(x);
            }
    }
    inline void swim(int pos, node *y) {
        node *x = root;
        while (pos != x->child[LEFT]->size + 1) {
            if (pos < x->child[LEFT]->size + 1) {
                x = x->child[LEFT];
            } else {
                pos -= x->child[LEFT]->size + 1;
                x = x->child[RIGHT];
            }
        }
        splay(x, y);
    }
    inline int find(int value) {
        node *x = root;
        int count = 0;
        while (value != x->value) {
            if (value < x->value) {
                x = x->child[LEFT];
            } else {
                count += x->child[LEFT]->size + 1;
                x = x->child[RIGHT];
            }
        }
        return count + x->child[LEFT]->size + 1;
    }
    inline void remove(int value) {
        int pos = find(value);
        swim(pos - 1, nil);
        swim(pos + 1, root);
        root->child[RIGHT]->child[LEFT] = nil;
        update(root->child[RIGHT]);
        update(root);
    }
    inline void insert(int value) {
        if (root == nil) {
            root = newnode(value, nil);
            return;
        }
        node *x = root;
        int dir = value > x->value;
        while (x->child[dir] != nil) {
            x = x->child[dir];
            dir = value > x->value;
        }
        x->child[dir] = newnode(value, x);
        update(x);
        splay(x->child[dir], nil);
    }
    inline void clear() {
        cur = buffer;
        root = nil;
        insert(INF);
        insert(-INF);
    }
    inline int getKth(int k) {
        swim(k + 1, nil);
        return root->value;
    }
} spt;

int n, m;
int pretty[MXN];
int ans[MXM];
struct interval {
    int l, r, k, id;
    bool operator<(const interval &b) const {
        return r < b.r;
    }
} ivals[MXM];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", pretty + i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &ivals[i].l, &ivals[i].r, &ivals[i].k);
        ivals[i].id = i;
    }
    sort(ivals, ivals + m);
    spt.clear();
    int pl = 1, pr = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = pl; j < ivals[i].l && j <= pr; ++j) {
            spt.remove(pretty[j]);
        }
        for (int j = std::max(ivals[i].l, pr + 1); j <= ivals[i].r; ++j) {
            spt.insert(pretty[j]);
        }
        ans[ivals[i].id] = spt.getKth(ivals[i].k);
        pl = ivals[i].l;
        pr = ivals[i].r;
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}