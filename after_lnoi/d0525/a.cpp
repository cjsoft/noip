#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 600010;
const int MAXL = 30;
int cnt = 1;
int nxt[MAXN][MAXL],par[MAXN],val[MAXN];
int root(1),last(1);
void extend(int w) {
    int p = last;
    int np = ++cnt;
    val[np] = val[p] + 1;
    while (p && nxt[p][w] == 0) 
        nxt[p][w] = np,p = par[p];
    if (!p) par[np] = root;
    else {
        int q = nxt[p][w];
        if (val[q] == val[p] + 1) {
            par[np] = q;
        }
        else {
            int nq = ++cnt;
            val[nq] = val[p] +  1;
            memcpy(nxt[nq],nxt[q],sizeof(nxt[q]));
            par[nq] = par[q];
            par[q] = par[np] = nq;
            while (p && nxt[p][w] == q) 
                nxt[p][w] = nq,p = par[p];
        }
    }
    last = np;
}
char s[MAXN],s2[MAXN];
int main() {
    scanf("%s",s);
    scanf("%s",s2);
    int l = strlen(s);
    for (int i=0;i<l;i++) {
        extend(s[i] - 'a');
    }
    int ans = 0;
    int cur = 1;
    int lcs = 0;
    int l2 = strlen(s2);
    for (int i=0;i<l2;i++) {
        int w = s2[i] - 'a';
        if (nxt[cur][w]) {
            cur = nxt[cur][w];
            lcs ++;
            ans = max(ans,lcs);
        }
        else {
            while (cur && !nxt[cur][w]) cur = par[cur];
            if (!cur) {
                cur = 1;
                lcs = 0;
            }
            else {
                lcs = val[cur] + 1;
                cur = nxt[cur][w];
            }
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        printf("%d ", val[i]);
    }
    printf("%d\n",ans);
}