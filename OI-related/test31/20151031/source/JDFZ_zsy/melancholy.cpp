#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define mod 4294967296ll
using namespace std;
typedef long long ll;
struct poi
{
	ll d,v;
	friend bool operator <(const poi &a,const poi &b)
	{
		return a.d<b.d;
	}
}a[100010];
ll b[100010];
ll c[10];
ll mul[10]={1,1,2,6,24,120,720,5040};
ll n,q,cnt;
ll x,y,k;
ll query(ll x)
{
	ll l=1,r=n+1,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(a[mid].d<=x)
		{
			l=mid+1;
		}else
		{
			r=mid;
		}
	}
	return r;
}
ll dfs(ll dep,ll la)
{
	ll ans=0;
	if((cnt-la)<(k-dep))
	{
		return 0;
	}
	if(dep==k)
	{
		ll ret=1;
		for(ll i=0;i<k;i++)
		{
			ret=(ret*c[i])%mod;
		}
		ans+=ret;
		return ans;
	}
	for(ll i=la+1;i<=cnt;i++)
	{
		c[dep]=b[i];
		ans+=dfs(dep+1,i);
		c[dep]=0;
	}
	return ans;
}
int main()
{
	freopen("melancholy.in","r",stdin);
	freopen("melancholy.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].d);
	}
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].v);
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=q;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&k);
		ll l=query(x-1);
		ll r=query(y);
		cnt=0;
		ll sum1=0,sum2=0;
		for(ll j=l;j<r;j++)
		{
			b[++cnt]=a[j].v; 
			sum1+=b[cnt];
			sum2+=b[cnt]*b[cnt];
			sum1%=mod;
			sum2%=mod;
		}
		sort(b+1,b+1+cnt);
		sum1=((sum1-b[1])%mod+mod)%mod;
		sum2=((sum2-(b[1]*b[1])%mod)%mod+mod)%mod;
		ll ans;
		if(k==1)
		{
			ans=sum1;
		}else if(k==2)
		{
			ans=(((sum1*sum1)%mod-sum2)%mod+mod%mod);
		}else
		{
			ans=(mul[k]*dfs(0,1))%mod;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
}
