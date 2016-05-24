#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 40007
struct samNode {
    samNode *parent;
    samNode *c[27];
    int step/*, r*/;
} buf[MXN], *root, *cur, *last;
char input[MXN];
int pattern[MXN];
int dep = 0;
int l;
int fail[MXN];
samNode *trans(samNode *r, int st) {
    for (int i = st; i < 27; ++i) {
        if (r->c[i]) {
            pattern[dep++] = i;
            return r->c[i];
        }
    }
    return 0;
}
int kmp() {
    memset(fail, 0, sizeof(int) * (l + 7));
    for (int i = 1; i < l; ++i) {
        int j = i;
        while (j > 0) {
            j = fail[j];
            if (pattern[j] == pattern[i]) {
                fail[i + 1] = j + 1;
                break;
            }
        }
    }
    for (int i = 0, j = 0; i < l * 2; ++i) {
        if (j < l && pattern[j] == input[i]) {
            ++j;
        } else {
            while (j > 0) {
                j = fail[j];
                if (pattern[j] == input[i]) {
                    ++j;
                    break;
                }
            }
        }
        if (j == l) {
            return i - l + 1;
        }
    }
    return -1;
}
int qqsolve() {
    memset(pattern, 0, (l + 7) << 2);
    dep = 0;
    samNode *pp = root;
    // pp = trans(pp, 1);
    while (dep < l && pp) pp = trans(pp, 0);
    // for (int i = 0; i < dep; ++i) {
    //  putchar(pattern[i] + 'a' - 1);
    // }
    // putchar('\n');
    return pp->step;
}
void extend(int ch) {
    samNode *p = last;
    samNode *np = cur++;
    np->step = last->step + 1;
    for (; p && !p->c[ch]; p = p->parent) p->c[ch] = np;
    // if (!p) p = root;
    if (!p) {
        np->parent = root;
    } else {
        samNode *q = p->c[ch];
        if (q->step != p->step + 1) {
            samNode *nq = cur++;
            nq->step = p->step + 1;
            memcpy(nq->c, q->c, sizeof q->c);
            nq->parent = q->parent;
            q->parent = np->parent = nq;
            for (; p && p->c[ch] == q; p = p->parent) p->c[ch] = nq;
        } else np->parent = q;
    }
    last = np;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(buf, 0, sizeof(buf));
        last = root = buf;
        // root->parent = root;
        cur = buf + 1;
        input[MXN];
        memset(input, 0, sizeof(input));
        scanf("%s", input);
        l = strlen(input);
        for (int i = 0; i < l; ++i) input[l + i] = input[i];
        // printf("%s\n", input);  
        for (int i = 0, _end_ = l * 2; i < _end_; ++i) {
            extend(input[i] - 'a' + 1);
        }
        // extend(0);
        // for (int i = 0; i < l; ++i) {
        //  extend(input[i] - 'a');
        // }
        printf("%d\n", qqsolve() - l + 1);
    }
}