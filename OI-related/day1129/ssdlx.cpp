#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, s, t;
struct edge {
    int a, b, w;
    bool operator<(const edge &b) const {
        return w < b.w;
    }
} egs[5007];
struct unionset {
    int fa[1007];
    unionset() {
        for (int i = 0; i < 1007; ++i) {
            fa[i] = i;
        }
    }
    int getfa(int x) {
        return fa[x] == x ? x : fa[x] = getfa(fa[x]);
    }
    int setfa(int a, int b) {
        fa[getfa(a)] = getfa(b);
    }
} ust;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &egs[i].a, &egs[i].b, &egs[i].w);
        ust.setfa(egs[i].a, egs[i].b);
    }
    scanf("%d %d", &s, &t);
    if (ust.getfa(s) != ust.getfa(t)) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    sort(egs, egs + m);
    int mawn, mewn, fma, fmi;
    float bz = 1e9, current;
    for (int i = 0; i < m; ++i) {
        mawn = egs[i].w;
        ust = unionset();
        ust.setfa(egs[i].a, egs[i].b);
        for (int j = i; j >= 0; --j) {
            mewn = egs[j].w;
            current = (float)mawn / (float)mewn;
            if (current >= bz) break;
            ust.setfa(egs[j].a, egs[j].b);
            if (ust.getfa(s) == ust.getfa(t)) {
                bz = current;
                fma = mawn;
                fmi = mewn;
            }
        }
    }
    if (bz != 1e9) {
        int asd = gcd(fma, fmi);
        if (fmi / asd == 1) printf("%d\n", fma / asd);
        else printf("%d/%d\n", fma / asd, fmi / asd);
    } else {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}