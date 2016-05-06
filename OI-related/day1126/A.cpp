#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char s[257];
    int a[257];
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    gets(s);
    for (int i = 0; i < strlen(s); ++i)
    {
        a[s[i]]++;
    }
    int cnt = 0;
    for (int i = '0'; i <= '9'; ++i)
    {
        cnt += a[i];
    }
    printf("%d\n", cnt);
    return 0;
}