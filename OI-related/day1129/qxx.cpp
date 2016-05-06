#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char hxbl[57];
char zxbl[57];
int findPos(char a[], int l, int r, int wtf) {
    for (int i = l; i <= r; ++i)
        if (a[i] == wtf) return i;
    return -1;
}
void parse(int zl, int zr, int hl, int hr) {
    if (zr < zl || hr < hl) return;
    putchar(hxbl[hr]);
    int rpos = findPos(zxbl, zl, zr, hxbl[hr]);
    parse(zl, rpos - 1, hl, hl + rpos - zl - 1);
    parse(rpos + 1, zr, hl + rpos - zl, hr - 1);
}

int main() {
    scanf("%s\n%s", zxbl, hxbl);
    parse(0, strlen(zxbl) - 1, 0, strlen(hxbl) - 1);
    putchar('\n');
    return 0;
}