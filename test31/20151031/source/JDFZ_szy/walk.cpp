#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define mod 1000000007
#define ll long long 
#define N 210000
int n,c;
struct poi 
{
	int x,y;
}a[N];
ll njc[N],jc[N],f[N];
ll res;
ll pow(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)
		{	
			ans=ans*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int cmp(poi q,poi w)
{
	if(q.x==w.x)
	return q.y<w.y;
	return q.x<w.x;
}
ll zh(ll x,ll y)
{
	if(x==0)
	return 1;
	return jc[y]*njc[x]%mod*njc[y-x]%mod;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&c);
	jc[1]=1;
	jc[0]=1;
	
	for(ll i=2;i<=n*2+1;i++)
	jc[i]=jc[i-1]*i%mod;
	
	njc[0]=1;
	for(ll i=1;i<=n*2+1;i++)
	njc[i]=pow(jc[i],mod-2);
	
	for(int i=1;i<=c;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=0;i<n;i++)
	{
		a[++c].x=i;
		a[c].y=i+1;
	}
	sort(a+1,a+1+c,cmp);
	for(int i=1;i<=c;i++)
	{
		f[i]=zh(a[i].x,a[i].y+a[i].x);
		for(int j=1;j<i;j++)
		if(a[j].x<=a[i].x&&a[j].y<=a[i].y)
		{
			f[i]-=zh(a[i].x-a[j].x,a[i].x+a[i].y-a[j].x-a[j].y)*f[j]%mod;
			f[i]%=mod;
		}
		f[i]=(f[i]+mod)%mod;
	}
	res=zh(n,n+n);
	for(int i=1;i<=c;i++)
	{	
		res-=f[i]*zh(n-a[i].x,n-a[i].x+n-a[i].y)%mod;
		res%=mod;
	}
	res=(res+mod)%mod;
	printf("%lld\n",res);
	return 0;
}





