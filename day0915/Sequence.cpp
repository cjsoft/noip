#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
int n,a[500007];
int dp[500007];
int main(){
    scanf("%d",&n);
    for (int i = 0; i < 500007; ++i)
    {
        dp[i]=1;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d",a+i);
    }
    for (int i = 1; i <=n; i++) {
        for (int j = i+1; j <= n; j++) {
            for (int k = j+1; k <= n; k ++) {
                for (int l = k+1; l <= n; l++) {
                    if(a[i]==a[k] && a[j]==a[l] ){
                        dp[j]=max(dp[i]+1,dp[j]);
                        dp[k]=max(dp[i]+2,dp[k]);
                        dp[l]=max(dp[i]+3,dp[l]);
                    }
                }
            }
        }
    }
    for (int i = 1; i <=n; ++i)
    {
        printf("%d\n",dp[i]/4*4 );
    }
    return 0;
}