#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[5007],b[5007];
int dp[5007][5007];
int la,lb;
int main(){
	scanf("%s\n%s",a+1,b+1);
	la=strlen(a+1);lb=strlen(b+1);
	for (int i = 1; i <= la; ++i)
	{
		for (int j = 1; j <= lb; ++j)
		{
			if(a[i]==b[j]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d\n", dp[la][lb]);
	return 0;
}