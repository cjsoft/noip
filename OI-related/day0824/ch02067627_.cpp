#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;
#define M 100  
#define N 100  
int dp[101][101];
int main ()  {
	int i,j,k,m,n;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=N;i++)
		dp[1][i]=i;
	for(j=2;j<=M;j++)
		for(k=1;k<=N;k++){
			dp[j][k]=1+max(dp[j-1][0],dp[j][k-1]);
			for(i=2;i<=k;i++)
				dp[j][k]=min(dp[j][k],1+max(dp[j-1][i-1],dp[j][k-i]));
		}
	while(scanf("%d%d",&n,&m)!=EOF)
		printf("%d\n",dp[m][n]);
	return 0;
}