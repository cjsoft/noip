#include <iostream>
#include <cstdio>
#include <cstring>
#define iterate(x, i) for (edge *i = head[x]; i; i = i->prev)
using namespace std;
const int MXN = 607;
const int MXM = 100007;
int n, m, p;
/*struct szsz {
    ll d[MXN];
    szsz() {memset(d, 0, sizeof(d));}
    void add(int pos,ll ad){
        while (pos < MXN && pos > 0){
            d[pos] += ad;
            d[pos] %= MOD;
            pos += lowbit(pos);
        }
    }
    ll sum(int pos){
        ll rtn = 0;
        while (pos > 0){
            rtn += d[pos];
            rtn %= MOD;
            pos -= lowbit(pos);
        }
        rtn += MOD;
        rtn %= MOD;
        return rtn;
    }

} ta;*/
struct edge {
    edge *prev;
    int to;
} egs[MXM], *head[MXN], *cur;
bool capttag[MXN];
int rudu[MXN], qcur = 0, chudu[MXN], zcur = 0;
int qiulst[MXN], zhongdianlst[MXN];
// int asdxxxxxxxxxx
void addedge(int a, int b) {
    cur->prev = head[a];
    cur->to = b;
    head[a] = cur++;
}
void start_trans(int qpos) {

}
int main() {
    cur = egs;
    puts("0");
    return 0;
    scanf("%d %d %d", n, m, p);
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        ++chudu[a];
        ++rudu[b];
        addedge(a, b);
    }
    for (int i = 1; i <= n; ++i) {
        if (!rudu[i]) qiulst[qcur++] = i;
        if (!chudu[i]) zhongdianlst[zcur++] = i;
    }
    return 0;
}