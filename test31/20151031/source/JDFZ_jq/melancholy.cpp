#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 4294967296
struct dot
{
	ll d,v;
}edge[100005];
int cmp(dot a,dot b)
{
	if(a.d==b.d)return a.v<b.v;
	return a.d<b.d;
}
int cmp2(dot a,dot b)
{
	return a.v<b.v;
}
int n,q;
int erfenst(ll x)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(edge[mid].d>=x)
		{
			r=mid;
		}else
		{
			l=mid+1;
		}
	}
	return r;
}
int erfenen(ll x)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(edge[mid].d>=x)
		{
			r=mid;
		}else
		{
			l=mid+1;
		}
	}
	return r;
}
ll sum[100005];
int main()
{
	freopen("melancholy.in","r",stdin);
	freopen("melancholy.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&edge[i].d);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&edge[i].v);
	}
	sort(edge+1,edge+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		sum[i]=(sum[i-1]+edge[i].v)%mod;
	}
	while(q--)
	{
		ll a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		int st=erfenst(a);
		int en=erfenen(b);
		if(en-st<c)
		{
			printf("0\n");
			continue;
		}
		sort(edge+st,edge+en+1,cmp2);
		if(c==1)
		{	
			printf("%lld\n",((sum[en]-sum[st-1]+mod)%mod-edge[st].v+mod)%mod);
		}else if(c==2)
		{
			ll ans=0;
			for(int i=st+1;i<en;i++)
			{
				for(int j=i+1;j<=en;j++)
				{
					ans=(edge[i].v*edge[j].v%mod+ans)%mod;
				}
			}
			ans=(ans*2)%mod;
			printf("%lld\n",ans);
		}
		sort(edge+st,edge+en+1,cmp);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
