#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cmath>
using namespace std;

int dp[107][107];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=n;++i){
		dp[i][0]=0;
	}
	for(int i=1;i<=n;++i){
		dp[1][i]=i;
		for(int j=2;j<=m;++j){
			for(int k=1;k<=n;++k){
				/*some code*/
			}
		}
	}
	return 0;
}