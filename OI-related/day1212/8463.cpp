#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
typedef unsigned long long ll;
using namespace std;

struct pos {
    ll x, y;
    pos(ll xx, ll yy) {
        x = xx;
        y = yy;
    }
    pos() {
        x = y = 0;
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
        return ll(sqrt(x * x * 100LL + y * y * 100LL) + 0.5);
    }
    void print() {
        printf("!%I64d %I64d\n", x, y);
    }
};

pos locate(ll id, ll level, ll dd) {
    // if (level <= 0) 
    //     puts("her");
    if (id == 1LL && level == 0LL) return pos(1LL, 1LL);
    ll total = 1LL << (level << 1LL), half = total >> 1LL, quater = half >> 1LL, halfnquater = half + quater;
    ll hop = (1LL << level) >> 1LL;
    pos poss[4];
    ll rotateS = 0LL;
    if (dd % 4LL == 0LL) {
        rotateS = 0LL;
        poss[0] = pos(0, 0);
        poss[1] = pos(hop, 0);
        poss[2] = pos(hop, hop);
        poss[3] = pos(0, hop);
    } else if (dd % 4LL == 1LL) {
        rotateS = 2LL;
        poss[0] = pos(0, 0);
        poss[1] = pos(0, hop);
        poss[2] = pos(hop, hop);
        poss[3] = pos(hop, 0);
    } else if (dd % 4LL == 2LL) {
        poss[0] = pos(hop, hop);
        poss[1] = pos(0, hop);
        poss[2] = pos(0, 0);
        poss[3] = pos(hop, 0);
    } else {
        rotateS = 2LL;
        poss[0] = pos(hop, hop);
        poss[1] = pos(hop, 0);
        poss[2] = pos(0, 0);
        poss[3] = pos(0, hop);
    }
    // printf("dd %d\n", dd);

    if (id <= quater) {
        // puts("1..");
        return poss[0] + locate(id, level - 1, dd + rotateS + 1);
    } else if (id > quater && id <= half) {
        // puts("2..");
        return poss[1] + locate(id - quater, level - 1, dd);
    } else if (id > half && id <= halfnquater) {
        // puts("3..");
        return poss[2] + locate(id - half, level - 1, dd);
    } else {
        // puts("4..");
        return poss[3] + locate(id - halfnquater, level - 1, dd + rotateS + 3);
    }
}

int main() {
    // cout<<(int)(0 + 1)<<endl;
    int T;
    scanf("%d", &T);
    ll n, s, d;
    while (T--) {
        cin>>n>>s>>d;
        // locate(s, n, 0).print();locate(d, n, 0).print();
        cout<<(locate(s, n, 0) - locate(d, n, 0)).mod()<<endl;
    }
    return 0;
}