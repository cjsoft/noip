#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
FILE *f;
using namespace std;

int main() {
    f = fopen("pair.out", "w");
    fputs("No idea...", f);
    fclose(f);
    return 0;
}