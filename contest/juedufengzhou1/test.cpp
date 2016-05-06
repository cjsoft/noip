#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {
    string a("hhh");
    char s[100];
    strcpy(s, a.c_str());
    printf("%s\n", s);
}