#include<stdio.h>
#include<algorithm>
using namespace std;
#define MOD 1000000007
typedef long long ll;
ll quickpower(ll x,ll y)
{
	ll re=1;
	while(y)
	{
		if(y&1)
		{
			re=(re*x)%MOD;
		}
		x=(x*x)%MOD;
		y>>=1;
	}
	return re;
}
ll n;
ll c;
ll fact[100005<<1];
ll inv[100005<<1];
void pre()
{
	fact[0]=1;
	inv[0]=1;
	for(ll i=1;i<=(n<<1);i++)
	{
		fact[i]=fact[i-1]*i%MOD;
		inv[i]=inv[i-1]*quickpower(i,MOD-2)%MOD;
	}
}
ll getc(ll n,ll m)
{
	ll re=1;
	re=(re*fact[n])%MOD;
	re=(re*inv[m])%MOD;
	re=(re*inv[n-m])%MOD;
	return re;
}
struct Data
{
	ll x;
	ll y;
}keng[1005];
bool cmp(Data a,Data b)
{
	if(a.x^b.x)
	{
		return a.x<b.x;
	}
	else
	{
		return a.y<b.y;
	}
}
ll cal(ll frx,ll fry,ll tox,ll toy)
{
	if(frx>tox||fry>toy)
	{
		return 0;
	}
	else
	{
		return getc(tox-frx+toy-fry,tox-frx);
	}
}
ll calc(ll frx,ll fry,ll tox,ll toy)
{
	return ((cal(frx,fry,tox,toy)-cal(frx,fry,toy-1,tox+1))%MOD+MOD)%MOD;
}
ll f[1005];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&c);
	pre();
	for(ll i=1;i<=c;i++)
	{
		scanf("%lld%lld",&keng[i].x,&keng[i].y);
	}
	sort(keng+1,keng+1+c,cmp);
	keng[c+1].x=n;
	keng[c+1].y=n;
	for(ll i=1;i<=c+1;i++)
	{
		f[i]=calc(0,0,keng[i].x,keng[i].y);
		for(ll j=1;j<i;j++)
		{
			if(keng[j].x<=keng[i].x&&keng[j].y<=keng[i].y)
			{
				f[i]=((f[i]-f[j]*calc(keng[j].x,keng[j].y,keng[i].x,keng[i].y)%MOD)%MOD+MOD)%MOD;
			}
		}
	}
	printf("%lld\n",f[c+1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
