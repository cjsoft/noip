#include <iostream>
#include <cstdio>

using namespace std;
int dp[27],n;
int main(){
	scanf("%d",&n);
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=n;++i){
		dp[i]=dp[i-1]+dp[i-2];
	}
	printf("%d\n",dp[n] );
	return 0;
}