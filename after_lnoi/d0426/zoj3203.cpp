#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define EPS 1e-11
using namespace std;
double H, D, h;
inline long double calc(long double zeta) {
    return (h - zeta) / (H - zeta) * D + zeta;
}

int main() {
    int T;
    scanf("%d", &T);
    long double L, R, mid, mmid;
    while (T--) {
        scanf("%lf %lf %lf", &H, &h, &D);
        L = 0;
        R = h;
        mid = (L * 2 + R) / 3;
        mmid = (L + R * 2) / 3;
        while (R - L > EPS) {
            if (calc(mid) < calc(mmid)) {
                L = mid + EPS;
            } else {
                R = mmid - EPS;
            }
            mid = (L + R) / 2;
            mmid = (mid + R) / 2;
        }
        printf("%.3lf\n", double(calc(mid)));
    }
    return 0;
}
