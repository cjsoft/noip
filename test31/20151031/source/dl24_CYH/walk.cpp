#include <iostream>
#include <cstdio>
#include <cstring>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)

using namespace std;
typedef long long ll;

const ll MOD=1000000007;
ll dp[5007][5007];
int n,m;
bool tag[5007][5007];
int main(){
	open("walk.in","walk.out");
	scanf("%d%d",&n,&m);
	memset(tag,false,sizeof(tag));
	memset(dp,0,sizeof(dp));
	int a,b;
	for(int i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		tag[a][b]=true;
	}
	dp[0][0]=1;
	for(int i=0;i<5007;++i){
		for(int j=0;j<=i;++j){
			if(tag[i][j])continue;
			if(i>0)dp[i][j]+=dp[i-1][j];
			if(j>0)dp[i][j]+=dp[i][j-1];
			dp[i][j]%=MOD;
		}
	}
	printf("%d\n",dp[n][n]);
	return 0;
}
