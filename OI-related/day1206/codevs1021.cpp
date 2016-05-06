#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
std::vector<int> vt[1007], vw[1007];
int n, m;
char inqueue[1007];
int dist[1007];
std::queue<int> qt;
struct pathComponent {
    int from, eid;
} path[1007];

void spfa(int s, bool enablePathFinder) {
    qt.push(s);
    memset(inqueue, 0, sizeof(inqueue));
    inqueue[s] = 1;
    std::fill_n(dist, 1007, INT_MAX >> 1);
    dist[s] = 0;
    while (!qt.empty()) {
        for (int i = 0; i < vt[qt.front()].size(); ++i) {
            if (vw[qt.front()][i] + dist[qt.front()] < dist[vt[qt.front()][i]]) {
                dist[vt[qt.front()][i]] = vw[qt.front()][i] + dist[qt.front()];
                if (enablePathFinder) {
                    path[vt[qt.front()][i]].eid = i;
                    path[vt[qt.front()][i]].from = qt.front();
                }
                if (inqueue[vt[qt.front()][i]] == 0) {
                    inqueue[vt[qt.front()][i]] = 1;
                    qt.push(vt[qt.front()][i]);
                }
            }
        }
        inqueue[qt.front()] = 0;
        qt.pop();
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int a, b, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &v);
        vt[a].push_back(b);
        vt[b].push_back(a);
        vw[a].push_back(v);
        vw[b].push_back(v);
    }
    spfa(1, true);
    int temp, loc = n, result = 0;;
    path[1].from = 0;
    while (path[loc].from) {
        temp = vw[path[loc].from][path[loc].eid];
        vw[path[loc].from][path[loc].eid] = INT_MAX >> 1;
        spfa(1, false);
        result = std::max(result, dist[n]);
        vw[path[loc].from][path[loc].eid] = temp;
        loc = path[loc].from;
    }
    printf("%d\n", result);
    return 0;
}