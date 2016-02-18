#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
#include <climits>
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
        int key, size;
        node *parent, *child[2];
    } *nil, _nil, *root, buffer[MXN], *cur;
    splaytree() {
        nil = &_nil;
        _nil.parent = nil;
        _nil.child[LEFT] = _nil.child[RIGHT] = nil;
        _nil.size = _nil.key = 0;
        root = nil;
        cur = buffer;
    }
    void print(node *x) {
        if (x == nil) return;
        print(x->child[LEFT]);
        printf("  - %d\n", x->key);
        print(x->child[RIGHT]);
    }
    inline node *newnode(int key, node *parent) {
        cur->parent = parent;
        cur->key = key;
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
    inline int find(int key) {
        node *x = root;
        int count = 0;
        while (key != x->key) {
            if (key < x->key) {
                x = x->child[LEFT];
            } else {
                count += x->child[LEFT]->size + 1;
                x = x->child[RIGHT];
            }
        }
        return count + x->child[LEFT]->size + 1;
    }

    inline void insert(int key) {
        if (root == nil) {
            root = newnode(key, nil);
            return;
        }
        node *x = root;
        int dir = key > x->key;
        while (x->child[dir] != nil) {
            x = x->child[dir];
            dir = key > x->key;
        }
        x->child[dir] = newnode(key, x);
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
        return root->key;
    }
} spt;
struct testcase {
    void read_data() {
        
    }
    void start_the_test1() {
        
    }
    void start_the_test2() {
        
    }
    clock_t run1() {
        start_the_test1();
        return clock();
    }
    clock_t run2() {
        start_the_test2();
        return clock();
    }
} tc;

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    FILE *f = fopen("result1.txt", "w");
    tc.read_data();
    puts("data read");
    clock_t p = clock();
    fprintf(f, "%d\n", int(tc.run1() - p));
    p = clock();
    fprintf(f, "%d\n", int(tc.run2() - p));
    fclose(f);
    puts("done");
    while (1);
}