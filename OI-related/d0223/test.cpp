#include <iostream>
#include <cstdio>

using namespace std;
int a = 1, b = 2, c = 3;
void asd(int **asd) {
    (*asd) = &c;
}
int main() {
    int *sd = &a;
    printf("$%d\n", *sd);
    asd(&sd);
    printf("$%d\n", *sd);
    return 0;
}