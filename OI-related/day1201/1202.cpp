#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int w, n, m;
struct unionSet {
    int fa[507];
    int tag[507];
    unionSet() {
        for (int i = 0; i < 507; ++i) {
            fa[i] = i;
            tag[i] = 0;
        }
    }
    int getfa(int x) {
        if (fa[x] == x) return x;
        int t = getfa(fa[x]);
        tag [x] += tag[fa[x]];
        fa[x] = t;
        return t;
    }
    void weightedUnion(int a, int b, int v) {
        int tfa = getfa(a);
        fa[tfa] = getfa(b);
        tag[tfa] = v - tag[a] + tag[b];
    }
};

int main() {
    scanf("%d", &w);
    for (int i = 0; i < w; ++i) {
        scanf("%d %d", &n, &m);
        unionSet ust;
        int s, t, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &s, &t, &v);
            if (ust.getfa(s - 1) == ust.getfa(t)) {
                if (ust.tag[s - 1] - ust.tag[t] != v) {
                    puts("false");
                    goto __EXIT;
                }
            } else {
                ust.weightedUnion(s - 1, t, v);
            }
        }
        puts("true");
__EXIT:;
    }
    return 0;
}