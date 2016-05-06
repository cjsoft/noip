#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
int n,a[500007];
int dp[500007];
int main(){
    scanf("%d",&n);
    for (int i = 1; i < 500007; ++i)
    {
        dp[i]=1;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d",a+i);
    }
    for (int i = 0; i <=n-4; i++) {
        for (int j = i+1; j <= n-3; j++) {
            for (int k = j+1; k <= n-2; k ++) {
                for (int l = k+1; l <= n-1; l++) {
                    for(int m=l+1;m<=n;m++){
                        if((a[j]==a[l] && a[k]==a[m])&& !(dp[i]%4)){
                            dp[j]=max(dp[j],dp[i]+1);
                            dp[k]=max(dp[k],dp[i]+2);
                            dp[l]=max(dp[l],dp[i]+3);
                            dp[m]=max(dp[m],dp[i]+4);
                        }
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