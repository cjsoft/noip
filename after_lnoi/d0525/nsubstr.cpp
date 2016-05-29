#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 500007
int len = 0;
char input[MXN];
struct sam {
    int mxstep;
    struct node {
        int step, sz;
        node *pre, *c[26];
    } *buf, *cur, *root, *last;
    sam() {
        buf = new node[MXN];
        memset(buf, 0, sizeof(node) * MXN);
        cur = buf + 1;
        root = last = buf;
    }
    sam(int n) {
        buf = new node[n];
        memset(buf, 0, sizeof(node) * n);
        cur = buf + 1;
        root = last = buf;
    }
    ~sam() {
        delete[] buf;
    }
    node *alloc(int st) {
        cur->step = st;
        memset(cur->c, 0, sizeof(cur->c));
        cur->pre = 0;
        cur->sz = 0;
        return cur++;
    }
    node **rank;
    void extend(int chr) {
        node *p = last;
        node *np = alloc(p->step + 1);
        np->sz = 1;
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
    void topo(int n) {
        int *b = new int[n];
        rank = new node*[n];
        memset(rank, 0, sizeof(node*) * n);
        memset(b, 0, sizeof(int) * n);
        node *p = buf + 1;
        mxstep = 0;
        for (; p != cur; ++p) ++b[p->step], mxstep = std::max(mxstep, p->step);
        for (int i = 2; i <= mxstep; ++i) b[i] += b[i - 1];
        for (p = buf + 1; p != cur; ++p) rank[--b[p->step]] = p;
        delete[] b;
    }
} sss;
int dp[MXN];
int main() {
    scanf("%s", input);
    len = strlen(input);
    for (int i = 0; i < len; ++i) {
        sss.extend(input[i] - 'a');
    }
    sss.topo(MXN);
    int i;
    for (i = 0; sss.rank[i]; ++i);
    for (--i; i >= 0; --i) {
        sss.rank[i]->pre->sz += sss.rank[i]->sz;
    }
    for (sam::node *p = sss.buf + 1; p != sss.cur; ++p) {
        dp[p->step] = std::max(dp[p->step], p->sz);
    }
    for (int i = 1; i <= sss.mxstep; ++i) {
        printf("%d\n", dp[i]);
    }
    return 0;
}