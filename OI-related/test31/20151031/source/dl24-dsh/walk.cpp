#include<cstdio>
#include<iostream>
using namespace std;

const int inf=1000000007;
int dp[5002][5002];
int canm[5002][5002];
int n,m,t1,t2;

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>t1>>t2;
		canm[t1][t2]=1;
	}
	
	dp[0][0]=1;
	
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			if (i!=j){
				if (canm[i+1][j]==0) dp[i+1][j]+=dp[i][j];
				if (canm[i][j+1]==0) dp[i][j+1]+=dp[i][j];
			}
			else{
				if (canm[i+1][j]==0) dp[i+1][j]+=dp[i][j];
			}
		}
	}
	
	cout<<dp[n][n];
	
	return 0;
}
