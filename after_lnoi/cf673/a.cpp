#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
int arr[97];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    arr[n] = 90;
    int last = 0;
    for (int i = 0; i <= n; ++i) {
        if (arr[i] - last >= 16) {
            printf("%d\n", last + 15);
            return 0;
        } else {
            last = arr[i];
        }
    }
    printf("%d\n", last);
    return 0;
}
