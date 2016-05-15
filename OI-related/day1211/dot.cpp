#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
typedef long long ll;
///////////////////////////////////////
// let 0, 2000006 be the extra node  //
///////////////////////////////////////
const int MXN = 2000007;

std::vector<int> vt[MXN], vw[MXN];
std::queue<int> q;
ll dist[MXN];
int n, m;
char inqueue[MXN];

int main() {
    scanf("%d %d", &n, &m);
    int temp_input;
    if (n == 1 || m == 1) {
        int s = std::max(n, m), inp, resu = INT_MAX;
        for (int i = 1; i < s; ++i) {
            scanf("%d", &inp);
            resu = std::min(resu, inp);
        }
        printf("%d\n", resu);
        return 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; ++j) {
            scanf("%d", &temp_input);
            if (i == 1) {
                vt[j << 1].push_back(0);
                vw[j << 1].push_back(temp_input);
                vt[0].push_back(j << 1);
                vw[0].push_back(temp_input);
            } else if (i == n) {
                vt[(i - 2) * ((m - 1) << 1) + (j << 1) - 1].push_back(MXN - 1);
                vw[(i - 2) * ((m - 1) << 1) + (j << 1) - 1].push_back(temp_input);
                vt[MXN - 1].push_back((i - 2) * ((m - 1) << 1) + (j << 1) - 1);
                vw[MXN - 1].push_back(temp_input);
            } else {
                vt[(i - 1) * ((m - 1) << 1) + (j << 1)].push_back((i - 2) * ((m - 1) << 1) + (j << 1) - 1);
                vw[(i - 1) * ((m - 1) << 1) + (j << 1)].push_back(temp_input);
                vt[(i - 2) * ((m - 1) << 1) + (j << 1) - 1].push_back((i - 1) * ((m - 1) << 1) + (j << 1));
                vw[(i - 2) * ((m - 1) << 1) + (j << 1) - 1].push_back(temp_input);
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &temp_input);
            if (j == 1) {
                vt[(i - 1) * ((m - 1) << 1) + 1].push_back(MXN - 1);
                vw[(i - 1) * ((m - 1) << 1) + 1].push_back(temp_input);
                vt[MXN - 1].push_back((i - 1) * ((m - 1) << 1) + 1);
                vw[MXN - 1].push_back(temp_input);
            } else if (j == m) {
                vt[i * ((m - 1) << 1)].push_back(0);
                vw[i * ((m - 1) << 1)].push_back(temp_input);
                vt[0].push_back(i * ((m - 1) << 1));
                vw[0].push_back(temp_input);
            } else {
                vt[(i - 1) * ((m - 1) << 1) + (j << 1) - 1].push_back((i - 1) * ((m - 1) << 1) + (j << 1) - 2);
                vw[(i - 1) * ((m - 1) << 1) + (j << 1) - 1].push_back(temp_input);
                vt[(i - 1) * ((m - 1) << 1) + (j << 1) - 2].push_back((i - 1) * ((m - 1) << 1) + (j << 1) - 1);
                vw[(i - 1) * ((m - 1) << 1) + (j << 1) - 2].push_back(temp_input);
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            scanf("%d", &temp_input);
            vt[(i - 1) * ((m - 1) << 1) + (j << 1)].push_back((i - 1) * ((m - 1) << 1) + (j << 1) - 1);
            vw[(i - 1) * ((m - 1) << 1) + (j << 1)].push_back(temp_input);
            vt[(i - 1) * ((m - 1) << 1) + (j << 1) - 1].push_back((i - 1) * ((m - 1) << 1) + (j << 1));
            vw[(i - 1) * ((m - 1) << 1) + (j << 1) - 1].push_back(temp_input);
        }
    }
    memset(inqueue, 0, sizeof(inqueue));
    std::fill(dist, dist + MXN, INT_MAX);
    inqueue[0] = 1;
    dist[0] = 0;
    q.push(0);
    int s;
    while (!q.empty()) {
        for (int i = 0; i < vt[q.front()].size(); ++i) {
            s = q.front();
            if (vw[q.front()][i] + dist[q.front()] < dist[vt[q.front()][i]]) {
                dist[vt[q.front()][i]] = vw[q.front()][i] + dist[q.front()];
                if (inqueue[vt[q.front()][i]] == 0) {
                    inqueue[vt[q.front()][i]] = 1;
                    q.push(vt[q.front()][i]);
                }
            }
        }
        inqueue[q.front()] = 0;
        q.pop();
    }
    std::cout << dist[MXN - 1] << std::endl;
    return 0;
}