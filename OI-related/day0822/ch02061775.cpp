#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
int dp[1007][107];
int t[107],w[107];
int T,m;
int main(){
	scanf("%d %d",&T,&m);
	for(int i=0;i<m;++i){
		scanf("%d %d",t+i,w+i);
	}
	for(int i=0;i<=T;++i){
		for(int j=0;j<m;++j){
			if(i>=t[j]){
				dp[i][j]=max(dp[i][j-1],dp[i-t[j]][j-1]+w[j]);
			}else{
				dp[i][j]=dp[i][j-1];
			}
		}
	}
	int mmm=0;
	for(int i=0;i<=T;++i){
		for(int j=0;j<m;++j){
			mmm=max(mmm,dp[i][j]);
		}
	}
	printf("%d\n", mmm);
	return 0;
}