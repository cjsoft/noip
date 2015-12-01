#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int w, n, m;
ll prefix[507];
int reflect[507];
bool exist[507];
struct testCase
{
    int s, t, v;
} csa[1007];
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
        return fa[x] == x ? x : fa[x] = getfa(fa[x]);
    }
};

int main() {
    scanf("%d", &w);
    for (int i = 0; i < w; ++i) {
        scanf("%d %d", &n, &m);
        unionSet ust;
        memset(exist, false, sizeof(exist));
        memset(csa, 0, sizeof(csa));
        memset(reflect, 0, sizeof(reflect));
        int s, t, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &csa[i].s, &csa[i].t, &csa[i].v);
            exist[csa[i].s] = exist[csa[i].t] = true;
        }
        int rfCnt = 0;
        for (int i = 0; i < 507; ++i) {
            if (exist[i]) reflect[i] = ++rfCnt;
        }
    }
    return 0;
}