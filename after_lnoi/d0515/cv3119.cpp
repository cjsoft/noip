#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MOD 100000000
#define WIDTH 8
using namespace std;
typedef long long ll;
int sequ[1007];
int resu[1007];
char input[1007];
ll te[10];
int tl;
void init() {
    te[0] = 1;
    for (int i = 1; i < 10; ++i) {
        te[i] = te[i - 1] * 10;
    }
}
struct num {
    ll a[507]; // start from a[0]
               // compress 1e8 into one long long varible
    int len;
    char str[1007];
    num() { memset(a, 0, sizeof(a)); memset(str, 0, sizeof(str)); len = 0; }
    num(const char raw[]) {
        memset(a, 0, sizeof(a)); memset(str, 0, sizeof(str));
        int l = strlen(raw);
        for (int i = l - 1; i >= 0; --i) {
            a[(l - i - 1) / WIDTH] += (raw[i] - 48) * te[(l - i - 1) % 8];
        }
        len = l / 8 + 1;
        for (; !a[len - 1] && len > 1; --len);
    }
    char* dumptoString() {
        while (a[len - 1] == 0) --len;
        if (len < 0) len = 0;
        char *ts = str;
        for (int i = len - 1; i >= 0; --i) {
            ts += sprintf(ts, i == len - 1 ? "%lld" : "%08lld", a[i]);
        }
        *ts = '\0';
        return str;
    }
    num operator*(num b) const {
        num rtn;
        rtn.len = len + b.len - 1;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < b.len; ++j) {
                rtn.a[i + j] += a[i] * b.a[j];
            }
        }
        for (int i = 0; i < rtn.len; ++i) {
            rtn.a[i + 1] += rtn.a[i] / MOD;
            rtn.a[i] %= MOD;
        }
        if (rtn.a[rtn.len]) ++rtn.len;
        return rtn;
    }
    num operator/(ll b) const {
        num rtn;
        ll mod = 0;
        for (int i = len - 1; i >= 0; --i) {
            mod *= MOD;
            mod += a[i];
            rtn.a[i] = mod / b;
            mod = mod % b;
        }
        for (rtn.len = len; rtn.len > 0 && !rtn.a[rtn.len - 1]; --rtn.len);
        return rtn;
    }
    num operator+(num b) const {
        num rtn;
        rtn.len = std::max(len, b.len);
        for (int i = 0; i < rtn.len; ++i) {
            rtn.a[i] = a[i] + b.a[i];
            // assert(i < 124);
        }
        for (int i = 0; i < rtn.len; ++i) {
            rtn.a[i + 1] += rtn.a[i] / MOD;
            rtn.a[i] %= MOD;
        }
        if (rtn.a[rtn.len]) ++rtn.len;
        return rtn;
    }
    int cmp(num b) {
        for (; !a[len - 1] && len > 1; --len);
        for (; !b.a[b.len - 1] && b.len > 1; --b.len);
        if (len < b.len) return -1;
        if (len > b.len) return 1;
        for (int i = len - 1; i >= 0; --i) {
            if (a[i] < b.a[i]) return -1;
            if (a[i] > b.a[i]) return 1;
        }
        return 0;
    }
};
int main() {
    init();
    scanf("%s", input);
    num a(input);
    num l("0"), r1("1");
    // char sss[1007];
    // for (int i = 1; i < 500; ++i) sss[i] = 48;
    // sss[0] = 49;
    num r(input);
    num mid = (l + r) / 2LL;
    int dir1 = a.cmp(mid * mid), dir2 = a.cmp((mid + r1) * (mid + r1));
    while (dir1 != 0) {
        // mid.dumptoString();
        num q = mid * mid;
        // printf("%d %I64d %d\n", q.len, q.a[0], dir1);
        if (dir1 == 1 && dir2 == -1) break;
        else if (dir1 == 1)
            l = mid + r1;
        else r = mid;
        mid = (l + r) / 2LL;
        dir1 = a.cmp(mid * mid);
        dir2 = a.cmp((mid + r1) * (mid + r1));
    }
    mid.dumptoString();
    printf("%s\n", mid.str);    

    return 0;
}