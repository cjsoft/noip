#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;
typedef long long ll;
int n;
int arr[5007];
int dp[5007];
int tot[5007];
int mp[5007][5007];
int mmm=0;
int global_result=0;

void dfs(int x,int depth){
	if(depth==mmm){
		++global_result;
		return;
	}
	for (int i = 0; i < tot[x]; ++i)
	{
		dfs(mp[x][i],depth+1);
	}
}

int main(){
	memset(tot,0,sizeof(tot));
	memset(dp,0,sizeof(dp));
	memset(mp,0,sizeof(mp));
	scanf("%d",&n);
	for (int i = 1; i <=n; ++i){
		scanf("%d",arr+i);
	}
	for (int i = 1; i <=n; ++i)
	{
		dp[i]=1;
	}
	for (int i = 1; i <n; ++i)
	{
		for (int j = i+1; j <=n; ++j)
		{
			if(arr[j]<arr[i]){
				if(dp[i]+1>dp[j]){
					dp[j]=dp[i]+1;
					mp[j][0]=i;
					tot[j]=1;
				}else if(dp[i]+1==dp[j]){
					mp[j][tot[j]]=i;
					++tot[j];
				}
			}
		}
	}
	for (int i = 1; i <=n; ++i)
	{
		mmm=max(dp[i],mmm);
	}
	for (int i = 1; i <=n; ++i)
	{
		if(dp[i]==mmm){
			dfs(i,1);
		}
	}
	printf("%d %d\n", mmm,global_result);
	return 0;
}

/*
12
68 69 54 64 68 64 70 67 78 62 98 87

 */