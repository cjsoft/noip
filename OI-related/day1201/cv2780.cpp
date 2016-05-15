#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct num {
    char s[207];
    num() {
        memset(s, 0, sizeof(s));
    }
    bool operator < (const num &b) const {
        int la = strlen(s), lb = strlen(b.s);
        if (la < lb) return true;
        if (la > lb) return false;
        for (int i = 0; i < la; ++i) {
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        }
        return false;
    }
} asd[27];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", asd[i].s);
    }
    sort(asd, asd + n);
    for (int i = 0; i < n; ++i) {
        printf("%s\n", asd[i].s);
    }
    return 0;
}