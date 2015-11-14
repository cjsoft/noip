#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1100
#define M 201000
#define mod 1000000007
using namespace std;
typedef long long ll;
ll n,c;
struct Point
{
	ll x,y;
	friend bool operator < (Point a,Point b)
	{
		if(a.x==b.x)return a.y<b.y;
		return a.x<b.x;
	}
	friend istream& operator >> (istream &_,Point &a)
	{scanf("%lld%lld",&a.x,&a.y);return _;}
}pt[N];
ll fac[M],inv_fac[M];
ll quick_my(ll x,ll y)
{
	ll ret=1;
	while(y)
	{
		if(y&1)ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}
void init()
{
	fac[0]=1;
	for(ll i=1;i<=200100;i++)
		fac[i]=fac[i-1]*i%mod,inv_fac[i]=quick_my(fac[i],mod-2);
}
ll f[N];
ll get_c(ll x,ll y)
{
	if(y>x)return 0;
	return (fac[x]*inv_fac[y]%mod)*inv_fac[x-y]%mod;
}
ll calc(ll x1,ll y1,ll x2,ll y2)
{
	if(x2<x1||y2<y1)return 0;
	return get_c(x2-x1+y2-y1,x2-x1);
}
ll calc2(ll x1,ll y1,ll x2,ll y2)
{
	return ((calc(x1,y1,x2,y2)-calc(x1,y1,y2-1,x2+1))%mod+mod)%mod;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	init();
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=c;i++)
		cin>>pt[i];
	pt[++c].x=n,pt[c].y=n;
	sort(pt+1,pt+c+1);
	for(int i=1;i<=c;i++)
	{
		f[i]=calc2(0,0,pt[i].x,pt[i].y);
		for(int j=1;j<i;j++)
			if(pt[j].y<=pt[i].y)
				f[i]=((f[i]-f[j]*calc2(pt[j].x,pt[j].y,pt[i].x,pt[i].y)%mod)%mod+mod)%mod;
	}
	printf("%lld\n",f[c]);
}
