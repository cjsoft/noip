#include <iostream>
#include <cstdio>
#include <cstring>
#define self (*this)
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;


char sss[2007];
int lsss,n,m;
int sequence[2007];
int global_result=0;
int dp[2007][2007];
int cursor[2007][2007];
struct word
{
	char strs[2007]; // 从第一位开始
	int d[2007];
	int c,lstrs;
	word(){
		memset(strs,0,sizeof(strs));
		memset(d,0,sizeof(d));
		lstrs=0;
		c=0;
	}
	void lcs(){
		memset(dp,0,sizeof(dp));
		memset(cursor,0,sizeof(cursor));
		lstrs=strlen(strs+1);
		for(int j=1;j<=lstrs;++j){
			for(int i=1;i<=lsss;++i){
				if(sss[i]==strs[j]){
					dp[j][i]=dp[j-1][i-1]+1;
					cursor[j][i]=i;
				}else{
					if(dp[j-1][i]>dp[j][i-1]){
						dp[j][i]=dp[j-1][i];
						cursor[j][i]=cursor[j-1][i];
					}else{
						dp[j][i]=dp[j][i-1];
						cursor[j][i]=cursor[j][i-1];
					}
				}
			}
		}
		c=cursor[lstrs][lsss];
		// for (int i = 1; i < 4; ++i)
		// {
		// 	for (int j = 1; j < 8; ++j)
		// 	{
		// 		printf("%d ", cursor[i][j]);
		// 	}
		// 	putchar('\n');
		// }
		for (int i = 1; i <=lsss; ++i)
		{
			d[i]=dp[lstrs][lsss]-dp[lstrs][i-1];
		}
		// printf("%d\n", d[1]);
		// putchar('\n');
	}
}words[2007];

int main(){
	open("message.in","message.out");
	scanf("%d",&n);
	memset(sequence,0,sizeof(sequence));
	for (int i = 1; i <=n; ++i)
	{
		scanf("%s",words[i].strs+1);
	}
	scanf("%d",&m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",sequence+i);
	}
	scanf("%s",sss+1);
	lsss=strlen(sss+1);
	for (int i = 1; i <=n; ++i)
	{
		words[i].lcs();
	}
	int last=0;
	for (int i = 0; i < m; ++i){
		global_result+=words[sequence[i]].d[words[last].c+1];
		// printf("  %d\n", words[i].c);
		last=sequence[i];
	}
	printf("%d\n",global_result );
	return 0;
}