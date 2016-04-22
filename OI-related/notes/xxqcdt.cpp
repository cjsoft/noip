#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int H = 2;
const int W = 2;
int n, q;
struct matrix {
    int a[H][W];
    matrix() {
        memset(a, 0, sizeof(a));
    }
    matrix operator+(const matrix &b) const {
        matrix rtn;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                rtn.a[i][j] = (*this).a[i][j] + b.a[i][j];
                rtn.a[i][j] %= q;
            }
        }
        return rtn;
    }
    matrix operator-(const matrix &b) const {
        matrix rtn;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                rtn.a[i][j] = (*this).a[i][j] - b.a[i][j];
                rtn.a[i][j] = (rtn.a[i][j] % q + q) % q;
            }
        }
        return rtn;
    }
    matrix operator*(const matrix &b) const {
        matrix rtn;
        for (int i = 0; i < W; i++) {
           for (int j = 0; j < W; j++) {
               for (int k = 0; k < W; k++) {
                   rtn.a[i][j] += (*this).a[i][k] * b.a[k][j];
                   rtn.a[i][j] %= q;
               }
           } 
        }
        return rtn;
    }
};
matrix matquickpow(matrix a, int b) {
    matrix rtn;
    for (int i = 0; i < W; i++) {
        rtn.a[i][i] = 1;
    }
    while (b) {
        if (b & 1) rtn = rtn * a;
        a = a * a;
        b >>= 1;
    }
    return rtn;
}
// int matquickpow(int a, int b) {
    // int rtn = 1;
    // while (b) {
        // if (b & 1) rtn = rtn * a;
        // a = a * a;
        // b >>= 1;
    // }
    // return rtn;
// }
int main() {
    // printf("%d\n", matquickpow(3, 4));
    int T;
    scanf("%d", &T);
    matrix basemat;
    basemat.a[0][0] = 1;
    basemat.a[0][1] = 1;
    basemat.a[1][0] = 1;
    matrix rawmat;
    rawmat.a[0][0] = 1;
    rawmat.a[1][0] = 1;
    while (T--) {
        scanf("%d %d", &n, &q);
        printf("%d\n", (matquickpow(basemat, n - 1) * rawmat).a[0][0]);
    }
    return 0;
}
