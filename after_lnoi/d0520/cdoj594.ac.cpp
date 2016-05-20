#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int inf=0x3fffffff;
int dp[50005][105],n,c;
int que[105],head,tail;
int main(){
    int k = 0;
    while(scanf("%d%d",&n,&c)==2){
         int x;
         scanf("%d",&x);
         for(int i=0;i<x;i++)
             dp[1][i]=inf;
         for(int i=x;i<=100;i++)
             dp[1][i]=(x-i)*(x-i);
         for(int i=2;i<=n;i++){
             scanf("%d",&x);
             //比前一个人高
             head=1, tail=0;
             for(int j=0;j<=100;j++){
                 int nowf=dp[i-1][j]-j*c;
                 while(head<=tail && que[tail]>nowf)
                     tail--, ++k;
                 que[++tail]=nowf;
                 if(j<x)
                     dp[i][j]=inf;
                 else
                     dp[i][j]=que[head]+j*c+(x-j)*(x-j);
             }
             //比前一个人矮
             head=1, tail=0;
             for(int j=100;j>=0;j--){
                 int nowf=dp[i-1][j]+j*c;
                 while(head<=tail && que[tail]>nowf)
                     tail--, ++k;
                 que[++tail]=nowf;
                 if(j>=x)
                     dp[i][j]=min(dp[i][j],que[head]-j*c+(x-j)*(x-j));
             }
         }
         int ans=inf;
         for(int i=0;i<=100;i++)
             ans=min(ans,dp[n][i]);
         printf("%d %d\n",ans, k);
    }
    return 0;
}