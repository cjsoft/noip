#include <iostream>
#include <cstdio>
using namespace std;
int dp[107][107],n;
int arr[107][107];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<=n;++i){
		dp[0][i]=99999999;
		dp[i][0]=99999999;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+arr[i][j];
			if(i==1 && j==1)
				dp[i][j]=arr[i][j];
		}
	}
	printf("%d\n", dp[n][n]);
	return 0;
}