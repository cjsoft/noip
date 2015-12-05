#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int dp[1007],n,arr[1007],por[1007];
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		dp[i+1]=1;
		scanf("%d",arr+1+i);
	}
	for (int i = 1; i <n; ++i)
	{
		for (int j = i+1; j <=n; ++j)
		{
			if(arr[j]<=arr[i]){
				if(dp[i]+1>dp[j])por[j]=i;
				dp[j]=max(dp[j],dp[i]+1);
			}
		}
	}
	int mmm=0;
	for (int i = 1; i <=n; ++i)
	{
		mmm=max(mmm,dp[i]);
	}
	printf("%d\n",mmm);
	return 0;
}