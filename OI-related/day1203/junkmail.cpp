#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct unionset
{
    int fa[1000000 + 7];
    int tag[1000000 + 7];
    unionset() {
        memset(fa,0,sizeof(fa));
        memset(tag,0,sizeof(tag));
        for (int i = 0; i < 1e6 + 7; ++i)
        {
            fa[i] = i;
        }
    }
    int getfa(int res) {
        if(res != fa[res]) {
            int tfa = getfa(fa[res]);
            tag[res] += tag[fa[res]];
            tag[res] %= 3;
            fa[res] = tfa;
        }
        return fa[res];
    }
    void unn(int a, int b, int x) {
        tag[fa[a]] -= tag[a] - x;
        tag[fa[a]] %= 3;
        tag[fa[a]] += 3;
        tag[fa[a]] %= 3;
        fa[fa[a]] = b;
    }
} ust;
int n, k;
int main() {
    scanf("%d %d", &n, &k);
    int cnt = 0;
    int a, b, c;
    for (int i = 0; i < k; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        if (b > n || c > n || b < 1 || c < 1) {
            ++cnt;
            // printf("sd\n");
            continue;
        }
        if (a == 1) {
            if (b != c)
                if (ust.getfa(b) == ust.getfa(c)) {
                    if (((ust.tag[b] - ust.tag[c]) % 3 + 3) % 3 != 0) {
                        ++cnt;
                        // printf("sd\n");
                    }
                } else {
                    ust.unn(b, c, 0);
                }
        } else {
            if (b == c) {
                ++cnt;
                // printf("sd\n");
                continue;
            }
            if (ust.getfa(b) == ust.getfa(c)) {
                if (((ust.tag[b] - ust.tag[c]) % 3 + 3) % 3 != 1) {
                    ++cnt;
                    // printf("sd\n");
                }
            } else {
                ust.unn(b, c, 1);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}