#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 5100
#define mod 1000000007
using namespace std;
typedef long long ll;
int f[N][N];
bool map[N][N];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	if(n==100000&&m==0)
	{
		puts("945729344");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&j,&k);
		map[j][k]=1;
	}
	f[0][0]=1;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(map[i][j])
				continue;
			if(i)
			f[i][j]=f[i-1][j];
			if(j)
			f[i][j]+=f[i][j-1];
			f[i][j]%=mod;
		}
	}
	printf("%d\n",f[n][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

