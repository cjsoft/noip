#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MXN = 100007;
const int MXM = 50007;
const int LEFT = 0, RIGHT = 1;
const int INF = 0x7fffffff;
struct Node {
    int value, size;
    Node *parent, *child[2];
} buffer[MXN], _nil;

struct SplayTree {
    Node *root, *nil;
    int NodeNumber;
    SplayTree() {
        nil = &_nil;
        _nil.size = _nil.value = 0;
        _nil.parent = nil;
        _nil.child[LEFT] = _nil.child[RIGHT] = nil;
    }

    inline void clear() {
        NodeNumber = 0;
        root = nil;
        insert(-INF);
        insert(INF);
    }
    inline void insert(int value) {
        if (root == nil) {
            root = newNode(nil, value);
            return;
        }
        Node *x = root;
        int dir;
        while (1) {
            dir = x->value < value;
            if (x->child[dir] == nil) {
                x->child[dir] = newNode(x, value);
                update(x);
                splay(x->child[dir], nil);
                return;
            } else {
                x = x->child[dir];
            }
        }
    }
    inline void remove(int value) {
        int k = find(value);
        find(k - 1, nil);
        find (k + 1, root);
        root->child[RIGHT]->child[LEFT] = nil;
        update(root->child[RIGHT]);
        update(root);
    }
    inline int getKth(int k) {
        find (k + 1, nil);
        return root->value;
    }
    inline Node *newNode(Node *parent, int value) {
        buffer[NodeNumber].value = value;
        buffer[NodeNumber].size = 1;
        buffer[NodeNumber].parent = parent;
        buffer[NodeNumber].child[LEFT] = buffer[NodeNumber].child[RIGHT] = nil;
        return &buffer[NodeNumber++];
    }
    inline void update(Node *x) {
        if (x == nil) return;
        x->size = x->child[LEFT]->size + x->child[RIGHT]->size + 1;
    }
    inline void rotate(Node *x, int dir) {
        if (x == nil) return;
        Node *p = x->parent;
        p->child[!dir] = x->child[dir];
        p->child[!dir]->parent = p;
        x->child[dir] = p;
        x->parent = p->parent;
        if (p->parent->child[LEFT] == p) {
            p->parent->child[LEFT] = x;
        } else {
            p->parent->child[RIGHT] = x;
        }
        p->parent = x;
        update(p);
        update(x);
        if (root == p) {
            root = x;
        }
    }

    inline void splay(Node *x, Node *y) {
        while (x->parent != y) {
            if (x->parent->parent == y) {
                rotate(x, x->parent->child[LEFT] == x);
            } else {
                if (x->parent->child[LEFT] == x && x->parent->parent->child[LEFT] == x->parent) {
                    rotate(x->parent, RIGHT);
                    rotate(x, RIGHT);
                } else if (x->parent->child[RIGHT] == x && x->parent->parent->child[RIGHT] == x->parent) {
                    rotate(x->parent, LEFT);
                    rotate(x, LEFT);
                } else if (x->parent->child[RIGHT] == x && x->parent->parent->child[LEFT] == x->parent) {
                    rotate(x, LEFT);
                    rotate(x, RIGHT);
                } else {
                    rotate(x, RIGHT);
                    rotate(x, LEFT);
                }
            }
        }
    }
    inline void find(int k, Node *y) {
        Node *x = root;
        while (k != x->child[LEFT]->size + 1) {
            if (k <= x->child[LEFT]->size) {
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
        while (1) {
            if (x->value == value) {
                return count + x->child[LEFT]->size + 1;
            } else if (x->value > value) {
                x = x->child[LEFT];
            } else {
                count += x->child[LEFT]->size + 1;
                x = x->child[RIGHT];
            }
        }
    }
} spt;
int pretty[MXN];
int ans[MXN];
struct Interval {
    int l, r, k, id;
    bool operator<(const Interval &b) const {
        return r < b.r;
    }
} ivals[MXM];
int n, m;
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
        for (int j = max(pr + 1, ivals[i].l); j <= ivals[i].r; ++j) {
            spt.insert(pretty[j]);
        }
        pl = ivals[i].l;
        pr = ivals[i].r;
        ans[ivals[i].id] = spt.getKth(ivals[i].k);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
