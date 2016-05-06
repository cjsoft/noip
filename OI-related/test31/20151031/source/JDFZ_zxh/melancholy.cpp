#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 150000
#define MOD 4294967296ll
using namespace std;
typedef long long ll;
ll n,q,l,r,k,ans,x,add;
ll D[MAXN],V[MAXN],tmp[MAXN],a[MAXN],book[MAXN];
void dfs(ll last,ll step)
{
	if(step==k+1)
	{
		ll mul=1;
		for(ll i=1;i<=k;i++)
		{
			mul=(mul*tmp[i])%MOD;
		}	
		add=(add+mul)%MOD;
		return ;
	}
	for(ll i=last;i<=x;i++)
	{
		if(!book[i])
		{
			book[i]=1;
			tmp[step]=a[i];
			dfs(i,step+1);
			book[i]=0;
		}
	}
}
int main()
{
	freopen("melancholy.in","r",stdin);
	freopen("melancholy.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&D[i]);
	}
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&V[i]);
	}
	while(q--)
	{
		scanf("%lld%lld%lld",&l,&r,&k);
		ll cnt=0;
		for(ll i=1;i<=n;i++)
		{
			if(D[i]>=l&&D[i]<=r)
			{
				tmp[++cnt]=V[i];
			}
		}		
		if((cnt-1)<k)puts("0");
		else
		{
			sort(tmp+1,tmp+1+cnt);
			if(cnt==2)printf("%lld\n",tmp[2]%MOD);
			else
			{
				ans=1;
				for(ll i=1;i<=k;i++)
				{
					ans=(ans*i)%MOD;
				}
				x=add=0;
				for(ll i=2;i<=cnt;i++)
				{
					a[++x]=tmp[i]%MOD;
				}
				dfs(1,1);
				printf("%lld\n",(ans*add%MOD)%MOD);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}