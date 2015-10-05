#include <iostream>
#include <cstdio>

using namespace std;

char a[207];
bool check() {
    for (int i = 0; i < 206; ++i) {
        if (a[i]!=1) return false;
        if (a[i] == 1 && a[i+1] == '\0')
            return true;
    }
}
void minn() {
    int ms = 0
    for (int i = 0; i < 207; ++i) {
        ms *= 10;
        ms +=a[i]-48;
        a[i] = (ms & 1) + 48;
        ms &= 1;
        if (a[i]==0)
            return ;
    }
}
int main() {

    return 0;
}