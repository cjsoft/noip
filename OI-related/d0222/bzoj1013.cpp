#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

double mat[20][20];
double raw[20][20];
double solu[20];
int n;
double k;
int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf", &raw[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = 2 * (raw[i][j] - raw[i + 1][j]);
            mat[i][n] += raw[i][j] * raw[i][j] - raw[i + 1][j] * raw[i + 1][j];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            k = mat[j][i] / mat[i][i];
            for (int l = i + 1; l <= n; ++l) {
                mat[j][l] -= mat[i][l] * k;
            }
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         printf("%lf ", mat[i][j]);
    //     }
    //     putchar('\n');
    // }
    solu[n - 1] =  mat[n - 1][n] / mat[n - 1][n - 1];
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            mat[i][n] -= mat[i][j] * solu[j];
        }
        solu[i] = mat[i][n] / mat[i][i];
    }
    for (int i = 0; i < n - 1; ++i) printf("%.3lf ", solu[i]);
    printf("%.3lf\n", solu[n - 1]);
    return 0;
}