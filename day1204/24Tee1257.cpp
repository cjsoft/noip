#include <iostream>
#include <cstdio>

using namespace std;

struct unionSet {
    int fa[10007];
    unionSet() {
        for (int i = 0; i < 10007; ++i) {
            fa[i] = i;
        }
    }
    int getfa(int x) {
        return fa[x] == x ? x : fa[x] = getfa(fa[x]);
    }
    void setfa(int a, int b) {
        fa[getfa(a)] = getfa(b);
    }
} ust;
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        if (ust.getfa(a) == ust.getfa(b)) {
            printf("%d\n", i + 1);
            return 0;
        } else {
            ust.setfa(a, b + n);
            ust.setfa(b, a + n);
        }
    }
    puts("OK");
    return 0;
}