#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef long long ll;
int n, m, p;
ll cntleft = 0, cntright = 0;
string la, ra, lb, rb, a, b;
char sm[10007];
string strm;
ll query() {
    if (ra.length() + lb.length() < m) return 0;
    char tempa[40007];
    // memset(tempa, 0, sizeof(tempa));
    // memset(tempb, 0, sizeof(tempb));
    // strcpy(tempa, ra.c_str());
    // strcpy(tempb, lb.c_str());
    ll count = 0;
    // ra jiequchangdu min(ra.length(), m - 1)
    string temp = ra.substr(ra.length() - min((int)ra.length(), m - 1), min((int)ra.length(), m - 1)) + lb.substr(0, min((int)lb.length(), m - 1));
    strcpy(tempa, temp.c_str());
    for (int i = 0; i < temp.length() - m + 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (tempa[i + j] != sm[j]) goto NXT;
        }
        ++count;
        NXT:;
            // printf("     %s\n", temp.c_str());
    }
    return count;
}
int main() {
    freopen("bugs.in", "r", stdin);
    freopen("bugs.out", "w", stdout);
    a = "0";
    la = "0";
    ra = "0";
    b = "1";
    lb = "1";
    rb = "1";
    la.reserve(40007);
    ra.reserve(40007);
    lb.reserve(40007);
    rb.reserve(40007);
    scanf("%d %d %d", &n, &m, &p);
    scanf("%s", sm);
    strm = string(sm);
    if (m == 1) {
        if (sm[0] == '0') cntleft = 1;
        if (sm[0] == '1') cntright = 1;
    }
    ll tempcnt = 0;
    // string tla, tlb, tra, trb;
    string tempra, templa, tempa;
    tempra.reserve(40007);
    templa.reserve(40007);
    for (int i = 1; i < n; ++i) {
        // printf("%s %s %s %s %d\n", la.c_str(), ra.c_str(), lb.c_str(), rb.c_str(), query());
        tempcnt = cntleft + cntright + query();
        // printf("%d\n", i);
        tempcnt %= p;
        cntleft = cntright;
        cntright = tempcnt;
        if (la.length() < m || ra.length() < m || lb.length() < m || rb.length() < m) {
            tempa = a;
            a = b;
            b = tempa + b;
            if (a.length() > m) {
                la = a.substr(0, m);
                ra = a.substr(a.length() - m, m);
            } else {
                la =a;
                ra = a;
            }
            if (b.length() > m) {
                lb = b.substr(0, m);
                rb = b.substr(b.length() - m, m);
            } else {
                lb =b;
                rb = b;
            }
        } else {
            // tla = la;
            // tlb = lb;
            // tra = ra;
            // trb = rb;
            swap(la, lb);
            // la = tlb;
            ra = rb;
            // lb = la;
            
        }
    }
    cout << cntright << endl;
    // printf("%d\n", cntright);
    // printf("%f\n", clock()/(double)CLOCKS_PER_SEC);
}