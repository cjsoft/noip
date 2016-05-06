#include <stdio.h>
#include <string.h>
#define MAXN 2002
#define MOD 1000000007
typedef long long ll;
ll n,c,x=1,y,ret;
ll map[MAXN][MAXN],f[MAXN][MAXN],a[MAXN];
ll Exgcd(ll a,ll b)
{
	if(b==0)
	{
		x=1;
		y=0;
		ret=a;
	}
	else
	{
		ret=Exgcd(b,a%b);
		ll t=x;
		x=y;
		y=t-a/b*x;
	}
	return ret;
}
void cal()
{
	ll mul1=1,mul2=1;
	for(ll i=n+1;i<=2*n;i++)
	{
		mul1*=i; mul1%=MOD;
	}
	for(ll i=1;i<=n+1;i++)
	{
		mul2*=i; mul2%=MOD;
	}
	// ans : mul1/mul2 
	ll d=Exgcd(mul2,MOD);
	x=((x*(1/d))%(MOD/d)+(MOD/d))%(MOD/d);
	printf("%lld\n",(mul1%MOD*x%MOD)%MOD);
}
void rp()
{
	a[1]=1;
	for(ll i=2;i<=n;i++)
	{
		a[i]=a[i-1]*(4*i-2)/(i+1);	
	}
	printf("%lld\n",a[n]-1);
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&c);
	for(ll i=1;i<=c;i++)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		map[x][y]=1;
	}
	if(c==0)
	{
		cal();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(c==1&&x==n)
	{
		rp();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	f[0][0]=1;
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=n;j++)
		{
			if(i==0&&j==0)continue;
			if(i==j-1) f[i][j]=f[i-1][j]%MOD;
			if(i!=j-1) f[i][j]=(f[i][j-1]+f[i-1][j])%MOD;
			if(map[i][j]==1)f[i][j]=0;
		}
	}
	printf("%lld\n",f[n][n]%MOD);
	fclose(stdin);
	fclose(stdout);
	return 0;
}