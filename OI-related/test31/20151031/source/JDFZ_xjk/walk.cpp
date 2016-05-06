#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long
#define mod 1000000007
ll dp[1005],p[200005],inv[200005];
struct node
{
	int x,y;
	bool operator <(const node &a)const{
		if(x==a.x) return y<a.y;
		return x<a.x;
	}
}a[1005];
int n,c;
ll qpow(ll x,int k)
{
	ll ret=1;
	while(k)
	{
		if(k&1) ret=ret*x%mod;
		k>>=1;x=x*x%mod;
	}
	return ret;
}
ll calc(int x,int y)
{
	if(x<0||y<0) return 0;
	return p[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>c;
	for(int i=1;i<=c;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+c+1);
	p[0]=inv[0]=1;
	for(int i=1;i<=n*2;i++)
	{
		p[i]=p[i-1]*i%mod;
		inv[i]=qpow(p[i],mod-2);
	}
	a[++c].x=n;a[c].y=n;
	for(int i=1;i<=c;i++)
	{
		dp[i]=calc(a[i].x+a[i].y,a[i].x)-calc(a[i].x+a[i].y,a[i].y-1);
		for(int j=1;j<i;j++)
		if(a[j].y<=a[i].y)
		{
			dp[i]=(dp[i]-dp[j]*calc(a[i].x-a[j].x+a[i].y-a[j].y,a[i].y-a[j].y)%mod+mod)%mod;
			dp[i]=(dp[i]+dp[j]*calc(a[i].x-a[j].x+a[i].y-a[j].y,a[i].y-a[j].x-1)%mod)%mod;
		}
	}
	cout<<dp[c]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
