#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
int dp[57][57],m,n;
void solve(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			if(i==1 && j==1){
				dp[i][j]=1;
			}else if(i>j){
				dp[i][j]=dp[i][j-1]+dp[i-j][j];
			}else if(i==j){
				dp[i][j]=dp[i][j-1]+1;
			}else{
				dp[i][j]=dp[i][i];
			}
		}
	}
	printf("%d\n",dp[m][n] );
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&m,&n);
		solve();
	}
	return 0;
}