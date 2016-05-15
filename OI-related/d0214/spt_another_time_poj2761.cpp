#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MXN = 100007;
const int MXM = 50007;
const int LEFT = 0, RIGHT = 1;
const int INF = 0x7fffffff;

struct SplayTree {
    struct Node {
        Node *parent;
        Node *child[2];
        int value;
        int size;
    } *root, *nil, _nil, buffer[MXN], *cur;
    SplayTree() {
        nil = &_nil;
        _nil.size = _nil.value = 0;
        _nil.child[LEFT] = _nil.child[RIGHT] = nil;
        _nil.parent = nil;
        root = nil;
        cur = buffer;
    }
    inline Node *newNode(int value, Node *parent) {
        cur->value = value;
        cur->size = 1;
        cur->child[LEFT] = cur->child[RIGHT] = nil;
        cur->parent = parent;
        return cur++;
    }
    inline void update(Node *x) {
        if (x == nil) return;
        x->size = x->child[LEFT]->size + x->child[RIGHT]->size + 1;
    }
    inline void rotate(Node *x, int dir) {
        if (x->parent == nil) return;
        Node *p = x->parent;
        p->child[!dir] = x->child[dir];
        x->child[dir]->parent = p;
        if (p->parent->child[LEFT] == p) {
            p->parent->child[LEFT] = x;
        } else {
            p->parent->child[RIGHT] = x;
        }
        x->child[dir] = p;
        x->parent = p->parent;
        p->parent = x;
        update(p);
        update(x);
        if (root == p) root = x;
    }
    inline bool islson(Node *x) {return x->parent->child[LEFT] == x;}
    inline bool isrson(Node *x) {return x->parent->child[RIGHT] == x;}
    inline void splay(Node *x, Node *y) {
        if (x == root) return;
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
    inline void insert(int value) {
        if (root == nil) {
            root = newNode(value, nil);
            return;
        }
        Node *x = root;
        int dir;
        while (1) {
            dir = value > x->value;
            if (x->child[dir] == nil) {
                x->child[dir] = newNode(value, x);
                update(x);
                splay(x->child[dir], nil);
                return;
            } else {
                x = x->child[dir];
            }
        }
    }
    inline void clear() {
        cur = buffer;
        root = nil;
        insert(-INF);
        insert(INF);
    }
    inline void swim(int k, Node *y) {
        Node *x = root;
        while (k != x->child[LEFT]->size + 1) {
            if (k < x->child[LEFT]->size + 1) {
                x = x->child[LEFT];
            } else {
                k -= x->child[LEFT]->size + 1;
                x = x->child[RIGHT];
            }
        }
        splay(x, y);
    }
    inline int find(int value) {
        Node *x = root;
        int count = 0;
        while (x->value != value) {
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