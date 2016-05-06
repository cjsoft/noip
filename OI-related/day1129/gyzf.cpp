#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m;
struct edge
{
    int a, b, c;
    edge() {
        a = 0;
        b = 0;
        c = 0;
    }
} egs[500007];
bool edgecmp(const edge &a, const edge &b) {
    return a.c > b.c;
}
struct unionset
{
    int fa[50007];
    unionset() {
        for (int i = 0; i < 50007; ++i) {
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

int main() {
    scanf("%d %d", &n, &m);
    int ta, tb, tc;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &ta, &tb, &tc);
        egs[i].a = ta;
        egs[i].b = tb;
        egs[i].c = tc;
    }
    sort(egs, egs + m, edgecmp);
    for (int i = 0; i < m; ++i) {
        if (ust.getfa(egs[i].a) == ust.getfa(egs[i].b)) {
            printf("%d\n", egs[i].c);
            return 0;
        } else {
            ust.setfa(egs[i].a, egs[i].b + n);
            ust.setfa(egs[i].b, egs[i].a + n);
        }
    }
    printf("0\n");
    return 0;
}