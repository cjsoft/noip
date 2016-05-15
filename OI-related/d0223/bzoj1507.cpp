#include <iostream>
#include <cstdio>
#include <cstring>
#define isrson(x) (x->p->c[1] == x)
#define islson(x) (x->p->c[0] == x)
using namespace std;
const int MXN = 2 * 1024 * 1024 + 4107;
const int LEFT = 0;
const int RIGHT = 1;
int cpos = 0;
struct node {
    node *p;
    node *c[2];
    char val;
    int size;
} _nil, *nil, *root, *cur, buffer[MXN], *iptc;
void pnt(node *x) {
    if (x == nil) return;
    pnt(x->c[LEFT]);
    if (x->val) putchar(x->val);
    pnt(x->c[RIGHT]);
}
inline void update(node *x) {
    if (x == nil) return;
    x->size = x->c[LEFT]->size + x->c[RIGHT]->size + 1;
}
inline node *newnode(char value, node *parent) {
    cur->val = value;
    cur->p = parent;
    cur->c[LEFT] = cur->c[RIGHT] = nil;
    cur->size = 1;
    return cur++;
}
inline void init() {
    cur = buffer;
    nil = &_nil;
    nil->size = nil->val = 0;
    nil->c[LEFT] = nil->c[RIGHT] = nil->p = nil;
    root = newnode('\0', nil);
    root->c[RIGHT] = newnode('\0', root);
    iptc = root;
    update(root);
}
inline void rotate(node *x, node **rt) {
    node *p = x->p, *z = x->p->p;
    int a = isrson(x), b = isrson(p);
    if ((*rt) != p) {
        z->c[b] = x;
        // printf("##### %d d\n", z == nil);
    } else {
        // node *re = (*rt);
        (*rt) = x;
        // printf("$$$$$ %d %d\n", re, *rt);
    }
    p->c[a] = x->c[!a];
    x->c[!a] = p;
    p->c[a]->p = p;
    p->p = x;
    x->p = z;
    update(p);
    update(x);
}
inline void splay(node *x, node *y, node **rt) {
    // printf("$ %d\n", *rt);
    for (; x->p != y; rotate(x, rt))
        if (x->p->p != y)
            if (isrson(x) == isrson(x->p)) rotate(x->p, rt);
            else rotate(x, rt);
}
inline void swim(node *x, int k, node *y) {
    while (k != x->c[LEFT]->size + 1) {
        if (k > x->c[LEFT]->size + 1) {
            k -= x->c[LEFT]->size + 1;
            x = x->c[RIGHT];
        } else {
            x = x->c[LEFT];
        }
    }
    splay(x, y, &root);
}
inline node *build_from_string(const char s[], int len);
inline void move(int k) {
    swim(root, k + 1, nil);
    cpos = k;
    // node *x = root;
    // cpos = k;
    // k = k + 1;
    // while (k != x->c[LEFT]->size + 1) {
    //     if (k > x->c[LEFT]->size + 1) {
    //         k -= x->c[LEFT]->size + 1;
    //         x = x->c[RIGHT];
    //     } else {
    //         x = x->c[LEFT];
    //     }
    // }
    // printf("              %d %d|\n", root, nil);
    // node *px = root;
    // splay(x, nil, &root);
    // printf("----- %d %d\n", px, root);
    // pnt(root);
    // putchar('\n');
    // pnt(x);
    // iptc = x;
}
inline void insert(const char s[], int len) {
    // splay(iptc, nil, &root);
    swim(root, cpos + 2, root);
    root->c[RIGHT]->c[LEFT] = build_from_string(s, len);
    root->c[RIGHT]->c[LEFT]->p = root->c[RIGHT];
    update(root->c[RIGHT]);
    update(root);
    // printf("\nsad %d\n", root->size);
    // pnt(root);
}
inline void delete_(int n_) {
    // splay(iptc, nil, &root);
    swim(root, cpos + n_ + 2, root);
    root->c[RIGHT]->c[LEFT] = nil;
    update(root->c[RIGHT]);
    update(root);
}
inline void get(int n_) {
    // splay(iptc, nil, &root);
    swim(root, cpos + n_ + 2, root);
    pnt(root->c[RIGHT]->c[LEFT]);
    putchar('\n');
}
inline void prev() {
    cpos--;
    swim(root, cpos + 1, nil);
    // cpos--;
    // if (iptc->c[LEFT] != nil) {
    //     iptc = iptc->c[LEFT];
    //     while (iptc->c[RIGHT] != nil) iptc = iptc->c[RIGHT];
    //     return;
    // } else if (isrson(iptc)) {
    //     iptc = iptc->p;
    // } else {
    //     puts("Encountered an Exception.");
    // }
}
inline void next() {
    cpos++;
    swim(root, cpos + 1, nil);
    // cpos++;
    // if (iptc->c[RIGHT] != nil) {
    //     iptc = iptc->c[RIGHT];
    //     while (iptc->c[LEFT] != nil) iptc = iptc->c[LEFT];
    //     return;
    // } else if (islson(iptc)) {
    //     iptc = iptc->p;
    // } else {
    //     puts("Encountered an Exception.");
    // }
}
inline node *build_from_string(const char s[], int len) {
    node *trt = newnode(s[0], nil);
    if (len > 1) {
        trt->c[RIGHT] = newnode(s[len - 1], trt);
        update(trt);
        for (int i = 1; i < len - 1; ++i) {
            trt->c[RIGHT]->c[LEFT] = newnode(s[i], trt->c[RIGHT]);
            update(trt->c[RIGHT]);
            update(trt);
            splay(trt->c[RIGHT]->c[LEFT], nil, &trt);
        }
    }
    // pnt(trt);
    return trt;
}
int getns(char s[], int len) {
    for (int i = 0; i < len; ++i) {
        s[i] = getchar();
        while (s[i] < 32 || s[i] > 126) s[i] = getchar();
    }
    s[len] = 0;
}
int t, asd;
char bfr[9], qwe[MXN];
int main() {
    scanf("%d", &t);
    init();
    while (t--) {
        memset(bfr, 0, sizeof(bfr));
        scanf("%s", bfr);
        switch (bfr[0]) {
        case 'M':
            scanf("%d", &asd);
            move(asd);
            // pnt(root);
            // putchar('\n');
            break;
        case 'I':
            memset(qwe, 0, sizeof(qwe));
            scanf("%d", &asd);
            getns(qwe, asd);
            // puts("4566");
            insert(qwe, asd);
            // puts("2333");
            // pnt(root);
            break;
        case 'D':
            scanf("%d", &asd);
            delete_(asd);
            break;
        case 'G':
            scanf("%d", &asd);
            get(asd);
            break;
        case 'P':
            prev();
            break;
        case 'N':
            next();
            break;
        }
        // puts("--> ");
    }
    return 0;
}