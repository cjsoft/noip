#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 600007
int len = 0, lll;
char input[MXN];
char ipt[MXN];
struct node {
    int step;
    node *pre, *c[26];
};
struct sam {
    node buf[MXN], *cur, *root, *last;
    sam() {
        // buf = new node[MXN];
        // memset(buf, 0, sizeof(node) * MXN);
        cur = buf + 1;
        root = last = buf;
        root->step = 0;
    }
    // sam(int n) {
    //     // buf = new node[n];
    //     memset(buf, 0, sizeof(node) * n);
    //     cur = buf + 1;
    //     root = last = buf;
    // }
    // ~sam() {
    //     delete[] buf;
    // }
    inline node *alloc(int st) {
        cur->step = st;
        memset(cur->c, 0, sizeof(cur->c));
        cur->pre = 0;
        return cur++;
    }
    void extend(int chr) {
        node *p = last;
        node *np = alloc(p->step + 1);
        for (; p && !p->c[chr]; p = p->pre) p->c[chr] = np;
        if (!p) {
            np->pre = root;
        } else {
            node *q = p->c[chr];
            if (q->step == p->step + 1) {
                np->pre = q;
            } else {
                node *nq = alloc(p->step + 1);
                memcpy(nq->c, q->c, 4 * 26);
                nq->pre = q->pre;
                q->pre = np->pre = nq;
                for (; p && p->c[chr] == q; p = p->pre) p->c[chr] = nq;
            }
        }
        last = np;
    }
} sss;
int main() {
    // return 0;
    scanf("%s", ipt);
    scanf("%s", input);
    len = strlen(input);
    lll = strlen(ipt);
    // printf("%d %d\n", len, lll);
    for (int i = 0; i < len; ++i) {
        sss.extend(input[i] - 'a');
    }
    node *p = sss.root;
    int tmp = 0, resu = 0;
    for (int i = 0; i < lll; ++i) {
        if (p->c[ipt[i] - 'a']) {
            // puts(" - 1");
            ++tmp;
            resu = std::max(resu, tmp);
            p = p->c[ipt[i] - 'a'];
        } else {
            for (; p && !p->c[ipt[i] - 'a']; p = p->pre);
            if (!p) {
                // puts(" - 2");
                tmp = 0;
                p = sss.root;
            } else {
                // puts(" - 3");
                tmp = p->step + 1;
                p = p->c[ipt[i] - 'a'];
            }
        }
        // printf("%d\n", tmp);
    }
    node *i = sss.buf;
    // for (; i != sss.cur; ++i) {
    //     printf("%d ", i->step);
    // }
    printf("%d\n", resu);
    return 0;
}