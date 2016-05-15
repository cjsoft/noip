#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
typedef unsigned int ll;
const ll INFF = INT_MAX;
int cur(1);
int n, m;
int gap[1000007], dis[1007][1007];
struct edge {
    edge *prev;
    int tox, toy;
    ll w;
    // edge() {
    //     prev = NULL;
    //     tox = toy = w = 0;
    // }
} egs[6000007], *head[1007][1007];

void add_edge(int fx, int fy, int tx, int ty, ll &weight) {
    egs[cur].prev = head[fy][fx];
    egs[cur].tox = tx;
    egs[cur].toy = ty;
    egs[cur].w = weight;
    head[fy][fx] = egs + cur++;
}
inline void gett(ll &x) {
    char c;
    while((c=getchar())<'0' || c>'9');
    x=c-'0';
    while((c=getchar())>='0' && c<='9') x=(x<<3)+(x<<1)+c-'0';
}

void read() {
    scanf("%d %d", &n, &m);
    ll temp;
    int i, j;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j < m; ++j) {
            // scanf("%u", &temp);
            gett(temp);
            add_edge(j, i, j + 1, i, temp);
            add_edge(j + 1, i, j, i, temp);
        }
    }
    for (i = 1; i < n; ++i) {
        for (j = 1; j <= m; ++j) {
            // scanf("%u", &temp);
            gett(temp);
            add_edge(j, i, j, i + 1, temp);
            add_edge(j, i + 1, j, i, temp);
        }
    }
    for (i = 1; i < n; ++i) {
        for (j = 1; j < m; ++j) {
            // scanf("%u", &temp);
            gett(temp);
            add_edge(j, i, j + 1, i + 1, temp);
            add_edge(j + 1, i + 1, j, i, temp);
        }
    }
}

ll dfs(int rx, int ry, ll Cflow) {
    if (rx == m && ry == n) return Cflow;
    ll Fflow(0);
    int min_d(m * n - 1);
    for (edge *i = head[ry][rx]; i; i = i->prev) {
        if (i->w){
            if (dis[ry][rx] == dis[i->toy][i->tox] + 1){
                int temp = dfs(i->tox, i->toy, std::min(Cflow - Fflow, i->w));
                i->w -= temp;
                (((i - egs) ^ 1) + egs)->w +=temp;
                Fflow += temp;
                if (dis[1][1] >= n * m) return Fflow;
                if (Cflow <= Fflow) break;
            }
            if (min_d > dis[i->toy][i->tox]) min_d = dis[i->toy][i->tox];
        }
    }
    if (!Fflow) {
        if (!(--gap[dis[ry][rx]])) dis[1][1] = m * n;
        ++gap[dis[ry][rx] = min_d + 1];
    }
    return Fflow;
}

ll max_flow() {
    gap[0] = n * m;
    ll resu(0);
    while (dis[1][1] < n * m) resu += dfs(1, 1, INFF);
    return resu;
}

int main() {
    read();
    printf("%u\n", max_flow());
}