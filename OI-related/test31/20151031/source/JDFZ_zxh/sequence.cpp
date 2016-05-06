#include <stdio.h>
#include <string.h>
#define MAXN 150000
typedef long long ll;
ll n,m,op;
ll a[MAXN];
void swap(ll &a,ll &b)
{
	ll tmp=a;
	a=b;
	b=tmp;
}
bool judge(ll a,ll b,ll c)
{
	if(a>b)swap(a,b);		//a<b
	if(a>c)swap(a,c);		//a<c
	if(b>c)swap(b,c);		//b<c
	if(a+b>c)
	{
		printf("%lld %lld %lld\n",a,b,c);
		return true;
	}
	return false;
}
void get_ans()
{
	for(ll i=3;i<=50;i++)
	{
		for(ll j=2;j<=i-1;j++)
		{
			for(ll k=1;k<=j-1;k++)
			{
				if(judge(a[i],a[j],a[k]))
				{
					return ;
				}
			}
		}
	}
	puts("-1 -1 -1");
	return ;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&op);
		if(op==2)
		{
			get_ans();
		}
		if(op==1)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			a[x]=y;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}