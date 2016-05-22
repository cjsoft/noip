#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#define INF 0x3f3f3f3f
typedef std::bitset<16> BITS;
int dp[12877];
int st[]
char inpt[67];

int main() {
    for (int i = 0; i < 4; ++i) scanf("%s", inpt + 4 * i);
    for (int i = 0; i < 65537; ++i) dp[i] = INF;
    BITS st(std::string(inpt));
    dp[st.to_ulong()] = 0;

}