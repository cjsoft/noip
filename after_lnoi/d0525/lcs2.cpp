#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 600007
int len = 0, lll;
char input[MXN];
char ipt[MXN];
struct node {
    int step, ml, nl;
    int nlstep, mlstep;
    node *pre, *c[26];
};
struct sam {
    node buf[MXN], *cur, *root, *last;
    int mxstep;
    node *rank[MXN];
    int b[MXN];
    sam() {
        memset(buf, 0, sizeof(node) * MXN);
        cur = buf + 1;
        root = last = buf;
    }
    node *alloc(int st) {
        cur->step = st;
        memset(cur->c, 0, sizeof(cur->c));
        cur->pre = 0;
        cur->ml = st;
        cur->mlstep = st;
        cur->nl = 0;
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
                memcpy(nq->c, q->c, sizeof(q->c));
                nq->pre = q->pre;
                q->pre = np->pre = nq;
                for (; p && p->c[chr] == q; p = p->pre) p->c[chr] = nq;
            }
        }
        last = np;
    }
    void topo(int n) {
        memset(rank, 0, sizeof(node*) * n);
        memset(b, 0, sizeof(int) * n);
        node *p = buf;
        mxstep = 0;
        for (; p != cur; ++p) ++b[p->step], mxstep = std::max(mxstep, p->step);
        for (int i = 1; i <= mxstep; ++i) b[i] += b[i - 1];
        for (p = buf; p != cur; ++p) rank[--b[p->step]] = p;
    }
} sss;
int main() {
    scanf("%s", input);
    len = strlen(input);
    for (int i = 0; i < len; ++i) {
        sss.extend(input[i] - 'a');
    }
    sss.topo(len + 7);
    while (~scanf("%s", ipt)) {
        lll = strlen(ipt);
        node *p = sss.root;
        int tmp = 0, resu = 0;
        for (int i = 0; i < lll; ++i) {
            if (p->c[ipt[i] - 'a']) {
                ++tmp;
                p = p->c[ipt[i] - 'a'];
            } else {
                for (; p && !p->c[ipt[i] - 'a']; p = p->pre);
                if (!p) {
                    tmp = 0;
                    p = sss.root;
                } else {
                    tmp = p->step + 1;
                    p = p->c[ipt[i] - 'a'];
                }
            }
            if (tmp > p->nl) {
                p->nl = tmp;
                p->nlstep = p->step;
            }
            // p->nl = std::max(p->nl, tmp);
        }
        memset(ipt, 0, sizeof(ipt));
        int i;
        for (i = 0; sss.rank[i]; ++i);
        for (--i; i >= 0; --i) {
            p = sss.rank[i];
            if (p->nl < p->ml) {
                p->ml = p->nl;
                p->mlstep = p->nlstep;
            }
            if (p->pre && p->pre->nl < p->nl) {
                p->pre->nl = p->nl;
                p->pre->nlstep = p->nlstep;
            }
            // p->ml = std::min(p->ml, p->nl);
            // if (p->pre) p->pre->nl = std::max(p->pre->nl, p->nl);
            p->nl = 0;
            p->nlstep = 0;
        }
    }
    node *mp = sss.root;
    for (node *p = sss.root + 1; p != sss.cur; ++p) {
        if (mp->ml < p->ml) mp = p;
    }
    for (int i = mp->mlstep - mp->ml; i < mp->mlstep; ++i) {
        putchar(input[i]);
    }
    putchar('\n');
    printf("%d\n", mp->ml);
    return 0;
}
