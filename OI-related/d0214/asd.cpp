#define islson(x) (x->parent->child[0] == x)
#define isrson(x) (x->parent->child[1] == x)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MXN = 100007;
const int MXM = 50007;
const int LEFT = 0, RIGHT = 1;
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
    inline void splay(node *x, node *y) {
        if (x->parent == nil) return;
        while (x->parent != y) {
            if (x->parent->parent == y) {
                rotate(x, islson(x));
            } else {
                if (islson(x)) {
                    if (islson(x->parent)) {
                        rotate(x->parent, RIGHT);
                        rotate(x, RIGHT);
                    } else {
                        rotate(x, RIGHT);
                        rotate(x, LEFT);
                    }
                } else {
                    if (islson(x->parent)) {
                        rotate(x, LEFT);
                        rotate(x, RIGHT);
                    } else {
                        rotate(x->parent, LEFT);
                        rotate(x, LEFT);
                    }
                }
            }
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
} sp;
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
    sp.clear();
    sort(ivals, ivals + m);
    int pl = 1, pr = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = pl; j <= pr && j < ivals[i].l; ++j) {
            sp.remove(pretty[j]);
        }
        for (int j = std::max(ivals[i].l, pr + 1); j <= ivals[i].r; ++j) {
            sp.insert(pretty[j]);
        }
        ans[ivals[i].id] = sp.getKth(ivals[i].k);
        pl = ivals[i].l;
        pr = ivals[i].r;
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
}