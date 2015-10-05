#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;
using namespace std;

struct pos {
    ll x, y;
    pos(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    void set(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    pos operator+(pos const &b) const {
        return pos(x + b.x, y + b.y);
    }
    pos operator-(pos const &b) const {
        return pos(x - b.x, y - b.y);
    }
    ll mod() {
        return ll(sqrt(x * x * 100 + y * y * 100) + 0.5);
    }
    void print() {
        printf("!%I64d %I64d\n", x, y);
    }
};
pos locate(ll id, ll level, int prev) {
    if (id == 1LL && level == 0) return pos(1LL, 1LL);
    ll total = 1LL << (level << 1LL);
    if (prev == 2 || prev == 3){
        if (id <= (total >> 2LL)) {
            // puts("1.");
            return pos(0, 0) + locate(id, level - 1LL, 1);
        } else if (id > (total >> 2LL) && id <= (total >> 1LL)) {
            // puts("2.");
            return pos(1LL << (level - 1LL), 0) + locate(id - (total >> 2LL), level - 1LL, 2);
        } else if (id > (total >> 1LL) && id <= ((total >> 1LL) + (total >> 2LL))) {
            // puts("3.");
            return pos(1LL << (level - 1LL), 1LL << (level - 1LL)) + locate(id - (total >> 1LL), level - 1LL, 3);
        } else {
            // puts("4.");
            return pos(0, 1LL << (level - 1LL)) + locate(id - (total >> 1LL) - (total >> 2LL), level - 1LL, 4);
        }
    } else if (prev == 1) {
        if (id <= (total >> 2LL)) {
            // puts("1.");
            return pos(0, 0) + locate(id, level - 1LL, 1);
        } else if (id > (total >> 2LL) && id <= (total >> 1LL)) {
            // puts("2.");
            return pos(0, 1LL << (level - 1LL)) + locate(id - (total >> 2LL), level - 1LL, 2);
        } else if (id > (total >> 1LL) && id <= ((total >> 1LL) + (total >> 2LL))) {
            // puts("3.");
            return pos(1LL << (level - 1LL), 1LL << (level - 1LL)) + locate(id - (total >> 1LL), level - 1LL, 3);
        } else {
            // puts("4.");
            return pos(1LL << (level - 1LL), 0) + locate(id - (total >> 1LL) - (total >> 2LL), level - 1LL, 4);
        }
    } else {
        if (id <= (total >> 2LL)) {
            // puts("1.");
            return pos(1LL << (level - 1LL), 1LL << (level - 1LL)) + locate(id, level - 1LL, 1);
        } else if (id > (total >> 2LL) && id <= (total >> 1LL)) {
            // puts("2.");
            return pos(1LL << (level - 1LL), 0) + locate(id - (total >> 2LL), level - 1LL, 2);
        } else if (id > (total >> 1LL) && id <= ((total >> 1LL) + (total >> 2LL))) {
            // puts("3.");
            return pos(0, 0) + locate(id - (total >> 1LL), level - 1LL, 3);
        } else {
            // puts("4.");
            return pos(0, 1LL << (level - 1LL)) + locate(id - (total >> 1LL) - (total >> 2LL), level - 1LL, 4);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    ll n, s, d;
    while (T--) {
        cin>>n>>s>>d;
        locate(s, n, 2).print();locate(d, n, 2).print();
        // cout<<(locate(s, n, 2) - locate(d, n, 2)).mod()<<endl;
    }
    return 0;
}