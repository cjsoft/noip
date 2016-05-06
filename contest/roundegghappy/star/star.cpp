#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
const float eps = 0.00005;
/*struct naivedict {
    float key[1007];
    int value[1007];
    int tot;
    naivedict() {
        memset(key, 0, sizeof(key));
        memset(value, 0, sizeof(value));
        tot = 0;
    }
    naivedict(float k) {
        memset(key, 0, sizeof(key));
        memset(value, 0, sizeof(value));
        key[0] = k;
        value[0] = 1;
        tot = 1;
    }
    int get(float k) {
        for (int i = 0; i < tot; ++i) {
            if (fabs(key[i] - k) < eps) return value[i];
        }
        return -1;
    }
    void add(float k) {
        for (int i = 0; i < tot; ++i) {
            if (fabs(key[i] - k) < eps) {
                ++value[i];
                return;
            }
        }
        key[tot] = k;
        value[tot++] = 1;
    }
};*/

map<float, map<float, int> > mp;
int n;
int A[1007], B[1007], C[1007];
void solve_equ(int a, int b) {

    float A1 = A[a], B1 = B[a], C1 = C[a];
    float A2 = B[b], B2 = B[b], C2 = C[b];
    float mat[20][20], solu[20];
    mat[0][0] = A1; mat[0][1] = B1; mat[0][2] = -C1;
    mat[1][0] = A2; mat[1][1] = B2; mat[1][2] = -C2;
    float k;
    for (int j = 1; j < 2; ++j) {
        k = mat[j][0] / mat[0][0];
        for (int l = 1; l <= 2; ++l) {
            mat[j][l] -= mat[0][l] * k;
        }
        }
    solu[1] =  mat[1][2] / mat[1][1];
    for (int i = 2 - 2; i >= 0; --i) {
        for (int j = i + 1; j < 2; ++j) {
            mat[i][2] -= mat[i][j] * solu[j];
        }
        solu[i] = mat[i][2] / mat[i][i];
    }
    float x = solu[0];
    float y = solu[1];
    printf("%f %f\n", solu[0], solu[1]);
    map<float, map<float, int> >::iterator ccc = mp.find(x);
    if (ccc == mp.end()) {
        mp.insert(make_pair(x, map<float, int>()));
        mp.find(x)->second.insert(make_pair(y, 1));
    } else {
        map<float, int>::iterator sss = ccc->second.find(y);
        if (sss == ccc->second.end()) {
            ccc->second.insert(make_pair(y, 1));
        } else {
            sss->second++;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", A + i, B + i, C + i);
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            solve_equ(i, j);
        }
    }
    int mmm = 0;
    for (map<float, map<float, int> >::iterator i = mp.begin(); i != mp.end(); i++) {
        for (map<float, int>::iterator j = i->second.begin(); j != i->second.end(); j++) {
            mmm = max(mmm, j->second);
        }
    }
    printf("%d\n", mmm);
}