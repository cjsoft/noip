#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

typedef long long ll;

char ctx = 0; // 0 for x, 1 for y

struct node {
    int data[2], mn[2], mx[2], l, r;
    int &operator[](int n) {
        return data[n];
    }
    friend bool operator<(node a,node b){
        return a[ctx]<b[ctx];
    }
} raw[500007];
inline int dis(node &a, node &b) {
    return std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
}
struct kd_tree {
    node tree[500007], cur;
    int ans;
    void update(int root) {
        int l = tree[root].l, r = tree[root].r;
        for (int i = 0; i < 2; ++i) {
            if (l) {
                tree[root].mn[i] = std::min(tree[root].mn[i], tree[l].mn[i]);
                tree[root].mx[i] = std::max(tree[root].mx[i], tree[l].mx[i]);
            }
            if (r) {
                tree[root].mn[i] = std::min(tree[root].mn[i], tree[r].mn[i]);
                tree[root].mx[i] = std::max(tree[root].mx[i], tree[r].mx[i]);
            }
        }
    }

    int build(int l, int r, char dimen) {
        ctx = dimen;
        int m = (l + r) >> 1;
        std::nth_element(raw + l, raw + m, raw + r);
        tree[m] = raw[m];
        for (int i = 0; i < 2; ++i) {
            tree[m].mn[i] = tree[m].mx[i] = tree[m].data[i];
        }
        tree[m].l = l < m ? build(l, m - 1, dimen ^ 1) : 0;
        tree[m].r = r < m ? build(m + 1, r, dimen ^ 1) : 0;
        update(m);
        return m;
    }
    void qn(int root, int dimen) {
        ctx = dimen;
        if (!tree[root].l) { // on leave
            ans = std::min(ans, dis(cur, tree[root]));
            return ;
        }
        if (cur.data[dimen] < tree[root].data[dimen]) {
            qn(tree[root].l, dimen ^ 1);
            ctx = dimen;
            if (std::abs(tree[root].mn[dimen] - cur.data[dimen]) < ans) {
                qn(tree[root].r, dimen ^ 1);
                ctx = dimen;
            }
        } else if (cur.data[dimen] > tree[root].data[dimen]) {
            qn(tree[root].r, dimen ^ 1);
            ctx = dimen;
            if (std::abs(tree[root].mx[dimen] - cur.data[dimen]) < ans) {
                qn(tree[root].l, dimen ^ 1);
                ctx = dimen;
            }
        } else {
            qn(tree[root].l, dimen ^ 1);
            ctx = dimen;
            qn(tree[root].r, dimen ^ 1);
            ctx = dimen;
            ans = std::min(ans, dis(cur, tree[root]));
        }
        return ;
    }
} kdt;

int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &raw[i].data[0], &raw[i].data[1]);
    }
    kdt.build(1, n, 0);
    for (int i = 1; i <= n; ++i) {
        kdt.ans = 9999999;
        kdt.qn((1 + n) >> 1, 0);
        printf("%d\n", kdt.ans);
    }
}