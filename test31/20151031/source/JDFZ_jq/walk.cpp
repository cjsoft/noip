#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define mod 1000000007
typedef long long ll;
ll quick(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)
		{
			ans=ans*x%mod;
		}
		x=x*x%mod;
		y/=2;
	}
	return ans;
}
ll sum[200005];
ll iva[200005];
int n,m;
bool map[5005][5005];
ll f[5005][5005];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m==0)
	{
		sum[0]=1;
		iva[0]=1;
		for(int i=1;i<=2*n;i++)
		{
			sum[i]=sum[i-1]*i%mod;
			iva[i]=iva[i-1]*quick(i,mod-2)%mod;
		}
		printf("%lld\n",(sum[n*2]*iva[n]%mod)*iva[n+1]%mod);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		map[a][b]=1;
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		if(!map[i][0])f[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			if(map[i][j])f[i][j]=0;
			else f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
		}
	}
	printf("%lld\n",f[n][n]%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
