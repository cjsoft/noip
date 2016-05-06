#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int dp[100007],n,arr[100007];
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
			if(arr[j]<arr[i]){
				dp[j]=max(dp[j],dp[i]+1);
			}
		}
	}
	int mmm=0;
	for (int i = 1; i <=n; ++i)
	{
		mmm=max(mmm,dp[i]);
	}
	printf("%d\n",n-mmm);
	return 0;
}