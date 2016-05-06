#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100000 + 5;

int a[N], b[N], rt[N * 20], ls[N * 20], rs[N * 20], sum[N * 20];

int n, k, tot, sz, ql, qr, x, q, T;

void Build(int& o, int l, int r){
    o = ++ tot;
    sum[o] = 0;
    if(l == r) return;
    int m = (l + r) >> 1;
    Build(ls[o], l, m);
    Build(rs[o], m + 1, r);
}

void update(int& o, int l, int r, int last, int p){
    o = ++ tot;
    ls[o] = ls[last];
    rs[o] = rs[last];
    sum[o] = sum[last] + 1;
    if(l == r) return;
    int m = (l + r) >> 1;
    if(p <= m)  update(ls[o], l, m, ls[last], p);
    else update(rs[o], m + 1, r, rs[last], p);
}

int query(int ss, int tt, int l, int r, int k){
    if(l == r) return l;
    int m = (l + r) >> 1;
    int cnt = sum[ls[tt]] - sum[ls[ss]];
    if(k <= cnt) return query(ls[ss], ls[tt], l, m, k);
    else return query(rs[ss], rs[tt], m + 1, r, k - cnt);
}

void work(){
    scanf("%d%d%d", &ql, &qr, &x);
    int ans = query(rt[ql - 1], rt[qr], 1, sz, x);
    printf("%d\n", b[ans]);
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i ++) scanf("%d", a + i), b[i] = a[i];
        sort(b + 1, b + n + 1);
        sz = unique(b + 1, b + n + 1) - (b + 1);
        tot = 0;
        Build(rt[0],1, sz);
        //for(int i = 0; i <= 4 * n; i ++)printf("%d,rt =  %d,ls =  %d, rs = %d, sum = %d\n", i, rt[i], ls[i], rs[i], sum[i]);
        for(int i = 1; i <= n; i ++)a[i] = lower_bound(b + 1, b + sz + 1, a[i]) - b;
        for(int i = 1; i <= n; i ++)update(rt[i], 1, sz, rt[i - 1], a[i]);
        for(int i = 0; i <= 5 * n; i ++)printf("%d,rt =  %d,ls =  %d, rs = %d, sum = %d\n", i, rt[i], ls[i], rs[i], sum[i]);
        while(q --)work();
    }
    return 0;
}
