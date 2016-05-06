#include <iostream>
#include <cstdio>
#include <cstring>
#define iterate(x, i) for (edge *i = head[x]; i; i = i->prev)
#define lowbit(x) (x & (-x))
using namespace std;
const int MOD = 593119681;
const int MX = 1027;
inline bool ifdis1(int a, int b) {
    int t = a ^ b;
    if (t == 0) return false;
    t >>= lowbit(t);
    if (t) return false;
    return true;
}
int nsbuffer[MX];
int nsc[MX];

int n, t;
inline int getint() {
    char ch = getchar();
    int data = 0;
    while (ch <'0' || ch > '9') ch = getchar();
    do {
        data = data * 10 + ch - 48;
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return data;
}
struct edge {
    int to;
    edge *prev;
} egs[MX * MX * 2 + 7], *cur, *head[MX];
void addedge(int a, int b) {
    cur->to = b;
    cur->prev = head[a];
    head[a] = cur++;
}   
int main() {
    freopen("monster.in", "r", stdin);
    freopen("monster.out", "w", stdout);
    cur = egs;
    // while (1) {
    //     int a = getint(), b = getint();
    //     printf("%d\n", ifdis1(a, b));
    // }
    scanf("%d %d", &n, &t);
    for (int i = 0; i < (1 << n); ++i) {
        nsc[i] = getint();
        // printf("%d\n",nsc[i] );
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = i + 1; j < (1 << n); ++j) {
            if (ifdis1(i, j)) {
                addedge(i, j);
                addedge(j, i);
            }
        }
    }
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            nsc[j] += nsbuffer[j];
            nsc[j] %= MOD;
            nsbuffer[j] = 0;
        }
        for (int j = 0; j < (1 << n); ++j) {
            iterate(j, k) {
                nsbuffer[k->to] += nsc[j];
                nsbuffer[k->to] %= MOD;
            }
        }
        // for (int i = 0; i < (1 << n) - 1; ++i) {
        //     printf("%d ", nsc[i]);
        // }
        // printf("%d\n", nsc[(1 << n) - 1]);
    }
    for (int i = 0; i < (1 << n); ++i) {
        nsc[i] += nsbuffer[i];
        nsbuffer[i] = 0;
        nsc[i] %= MOD;
    }
    for (int i = 0; i < (1 << n) - 1; ++i) {
        printf("%d ", nsc[i]);
    }
    printf("%d\n", nsc[(1 << n) - 1]);
}