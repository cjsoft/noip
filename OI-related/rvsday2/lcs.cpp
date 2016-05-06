#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char sa[256],la;
char sb[256],lb;
int dp[256][256];

int main(){
	cin>>(sa+1);la=strlen(sa+1);
	cin>>(sb+1);lb=strlen(sb+1);
	for (int i = 1; i <= la; ++i)
	{
		for (int j = 1; j <= lb; ++j)
		{
			if(sa[i]==sb[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[la][lb]<<endl;
	return 0;
}