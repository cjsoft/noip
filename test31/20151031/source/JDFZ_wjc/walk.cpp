#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll jc[200010],Hive,Bosh,f[1010],ans;
struct node
{
	ll x,y;
	bool operator < (const node &cmp) const{
		return x<cmp.x;
	}
}n[1010];
ll quick_mod(ll x)
{
	ll ret=1,y=MOD-2;
	while(y)
	{
		if(y&1) ret=ret*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ret;
}
ll C(ll x,ll y)
{
	if(x<y)
	{
		swap(x,y);
	}
	ll ret=1;
	ret=jc[x+y]*quick_mod(jc[x])%MOD*quick_mod(jc[y])%MOD*quick_mod(x+1)%MOD*(x-y+1)%MOD;
	return ret;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<=200000;i++)
	{
		jc[i]=jc[i-1]*i%MOD;
	}
	scanf("%lld%lld",&Hive,&Bosh);
	for(int i=1;i<=Bosh;i++)
	{
		scanf("%lld%lld",&n[i].x,&n[i].y);
	}
	sort(n+1,n+1+Bosh);
	ans=C(Hive,Hive);
	for(int i=1;i<=Bosh;i++)
	{
		f[i]=C(n[i].x,n[i].y);
		for(int j=1;j<i;j++)
		{
			if(n[i].x>=n[j].x&&n[i].y>=n[j].y)
			{
				f[i]=(f[i]-C(n[i].x-n[j].x,n[i].y-n[j].y)+MOD)%MOD;
			}
		}
		f[i]=f[i]*C(Hive-n[i].x,Hive-n[i].y)%MOD;
	}
	for(int i=1;i<=Bosh;i++)
	{
		ans=(ans-f[i]+MOD)%MOD;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
