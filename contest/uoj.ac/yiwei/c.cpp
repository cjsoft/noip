#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
struct bcj {
    int fa[1007];
    bcj() {
        for (int i = 0; i < 1007; ++i) {
            fa[i] = i;
        }
    }
    int getfa(int root) {
        if (fa[root] == root) return root;
        fa[root] = getfa(fa[root]);
        return fa[root];
    }
    void setfa(int a, int b) {
        fa[getfa(a)] = getfa(b);
    }
} ba;
struct edge {
    // edge *prev;
    int to, from;
    ll w;
    edge() {
        // prev = to = 0;
        to = from = 0;
        w = 0;
    }
} egs[1014049];
edge *tot = egs;
bool cmp(edge a, edge b) {
    return a.w > b.w;
}
void addedge(int a, int b, ll weight) {
    // tot->to = to;
    tot->w = weight;
    tot->to = b;
    tot->from = a;
    tot++;
    // tot->prev = head[from];
    // head[from] = tot++;
}
edge *head[1007];
int frd[1007];
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", frd + i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            addedge(i, j, frd[i] & frd[j]);
        }
    }
    sort(egs, tot, cmp);
    int ans = 0, nn = 0, cursor = 0;
    while (nn < n - 1) {
        if (ba.getfa(egs[cursor].to) != ba.getfa(egs[cursor].from)) {
            ans += egs[cursor].w;
            // printf(" %d %d %d\n", egs[cursor].from, egs[cursor].to, egs[cursor].w);
            nn++;
            ba.setfa(egs[cursor].to, egs[cursor].from);
        }
        cursor++;
    }
    cout << ans <<endl;
    return 0;
}