#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MXN 100007
using namespace std;
int locator[MXN];
int pai[MXN];
struct position {
    int x, y;
    int loc;
    bool type;
    int id;
} buff[MXN];
bool cmp(const position &a, const position &b) {
    if ((a.x - buff[a.loc].x) * (b.y - buff[a.loc].y) - (b.x - buff[a.loc].x) * (a.x - buff[a.loc].y) > 0) return true;
    return false;
}
bool ncmp(position &a, position &b) {
    if (a.y < b.y) return true;
    if (a.y > b.y) return false;
    return a.x < b.x;
}
void solve(int l, int r) {
    if (l >= r + 1) return;
    int lll = l;
    for (int i = l + 1; i <= r; ++i) {
        if (ncmp(buff[i], buff[lll])) {
            l = i;
        }
    }
    std::swap(buff[l], buff[lll]);
    for (int i = l; i <= r; ++i) {
        buff[i].loc = lll;
    }
    sort(buff + l, buff + r + 1, cmp);
    int cnt1 = 0, cnt2 = 0;
    for (int i = l + 1; i <= r; ++i) {
        if (buff[lll].type != buff[i].type) {
            if (cnt1 == cnt2) {
                locator[buff[lll].id] = buff[i].id;
                locator[buff[i].id] = buff[lll].id;
                solve(l, i - 1);
                solve(i + 1, r);
            } else {
                ++cnt2;
            }
        } else {
            ++cnt1;
        }
    }
}
void init() {
    for ()
}
int main() {

}