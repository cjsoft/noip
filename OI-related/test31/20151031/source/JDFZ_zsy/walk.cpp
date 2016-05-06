#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
struct node
{
	int x;
	int y;
	friend bool operator <(const node &a,const node &b)
	{
		if(a.x==b.x)
		{
			return a.y<b.y;
		}
		return a.x<b.x;
	}
}a[1010];
ll f[5010][5010];
ll g[100010];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);	
	if(n<=5000)
	{
		for(int i=0;i<=n;i++)
		{
			f[i][0]=1;
		}
		for(int i=1;i<=k;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			f[x][y]=-1;
			if(y==0)
			{
				f[x][y]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(f[i][j]==-1)
				{
					f[i][j]=0;
					continue;
				}
				f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
			}
		}
		printf("%lld\n",f[n][n]);
	}else if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			g[i]=1;
			for(int j=1;j<i;j++)
			{
				g[i]=(g[i]+g[j]*g[i-j])%mod;
			}
		}
		printf("%lld\n",g[n]);
	}else 
	{
		puts("Wrong Answer");
	}
	fclose(stdin);
	fclose(stdout);
}
