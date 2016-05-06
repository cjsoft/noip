#include <cstdio>
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>


int cur(1), n, m;
int dis[207], gap[207];
struct edge {
    edge *prev;
    int to, w;
    edge() {
        prev = NULL;
        to = w = 0;
    }
} egs[407];
edge *head[207];


void add_edge(int from, int to, int weight) {
    egs[cur].prev = head[from];
    egs[cur].to = to;
    egs[cur].w = weight;
    head[from] = egs + cur++;
}
int dfs(int root, int current_flow) {
    if (root == m) return current_flow;
    int other_flow = 0, min_dis = n - 1;
    for (edge *i = head[root]; i; i = i->prev) {
        if (i->w) {
            if (dis[root] == dis[i->to] + 1) {
                int temp = dfs(i->to, std::min(current_flow - other_flow, i->w));
                i->w -= temp;
                (egs + ((i - egs) ^ 1))->w += temp;
                other_flow += temp;
                if (dis[1] >= n) return other_flow;
                if (current_flow == other_flow) break;
            }
            min_dis = std::min(min_dis, dis[i->to]);
        }
    }
    if (!other_flow) {
        --gap[dis[root]];
        if (!gap[dis[root]]) dis[1] = n;
        dis[root] = min_dis + 1;
        ++gap[dis[root]];
    }
    return other_flow;
}
int max_flow() {
    int resu(0);
    gap[0] = n;
    while(dis[1] < n) resu += dfs(1, INT_MAX);
    return resu;
}
int main() {
    scanf("%d %d", &n, &m);
    int s, e, c;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &s, &e, &c);
        add_edge(s, e, c);
        add_edge(e, s, 0);
    }
    printf("%d\n", max_flow());
    return 0;
}