// not submitted yet

#include <iostream>
#include <cstdio>

using namespace std;
int n;
bool check(int a, int x) {
    if (
        a % 10 == x || (a / 10) % 10 == x ||
        (a / 100) % 10 == x || a % x == 0
        )
        return true;
    return false;
}
int main() {
    scanf("%d", &n);
    typedef long long ll;
    ll resu  = 0;
    for (int i = 1; i <= n; ++i) {
        if (check(i, 3) == false || check(i, 5) == false)
            resu += i * i;
    }
    printf("%lld\n", resu);
    return 0;
}