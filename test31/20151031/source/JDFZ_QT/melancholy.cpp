#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
typedef long long ll;
struct node
{
	int d,v;
};
node a[N];
int n,m;
ll sum[4][N<<2];
ll f[N<<2];
const ll MOD=4294967296ll;
const ll inf=9223372036854775807ll;

bool cmp(node x,node y)
{
	return x.d<y.d;
}

void PushUp(int rt)
{
	sum[1][rt]=(sum[1][rt<<1]+sum[1][rt<<1|1])%MOD;
	sum[2][rt]=(sum[2][rt<<1]+sum[2][rt<<1|1])%MOD;
	sum[3][rt]=(sum[3][rt<<1]+sum[3][rt<<1|1])%MOD;
	f[rt]=min(f[rt<<1],f[rt<<1|1]);
}

void fix(int x,int c,int l,int r,int rt)
{
	if(l==r)
	{
		f[rt]=c;
		sum[1][rt]=c;
		sum[2][rt]=(ll)c*(ll)c%MOD;
		sum[3][rt]=sum[2][rt]*(ll)c%MOD;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>=x)fix(x,c,lson);
	else fix(x,c,rson);
	PushUp(rt);
}

ll query(int L,int R,int k,int l,int r,int rt)
{
	if(l>=L&&r<=R)return sum[k][rt];
	int mid=(l+r)>>1;
	ll ans=0;
	if(mid>=L)ans=(ans+query(L,R,k,lson))%MOD;
	if(mid<R)ans=(ans+query(L,R,k,rson))%MOD;
	return ans;
}

ll query_min(int L,int R,int l,int r,int rt)
{
	if(l>=L&&r<=R)return f[rt];
	int mid=(l+r)>>1;
	ll ans=inf;
	if(mid>=L)ans=min(ans,query_min(L,R,lson));
	if(mid<R)ans=min(ans,query_min(L,R,rson));
	return ans;
}

int doing_l(int l,int r,int x)
{
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid].d==x)return mid;
		if(a[mid].d>x&&a[mid-1].d<x)return mid;
		if(a[mid].d<x&&a[mid+1].d>x)return mid+1;
		if(a[mid].d<x)l=mid+1;
		else if(a[mid].d>x)r=mid-1;
	}
	if(l==1)return 1;
	else return -1;
}

int doing_r(int l,int r,int x)
{
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid].d==x)return mid;
		if(a[mid].d>x&&a[mid-1].d<x)return mid-1;
		if(a[mid].d<x&&a[mid+1].d>x)return mid;
		if(a[mid].d<x)l=mid+1;
		else if(a[mid].d>x)r=mid-1;
	}
	if(r==n)return n;
	else return -1;
}

int main()
{
	freopen("melancholy.in","r",stdin);
	freopen("melancholy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i].d);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].v);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		fix(i,a[i].v,1,n,1);
	for(int i=1;i<=m;i++)
	{
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		int l=doing_l(1,n,x);
		int r=doing_r(1,n,y);
		if(k==1)printf("%lld\n",query(l,r,k,1,n,1)-query_min(l,r,1,n,1));
		else if(k==2)
		{
			ll minx=query_min(l,r,1,n,1);
			ll cnt1=(query(l,r,1,1,n,1)-minx+MOD)%MOD;
			cnt1=cnt1*cnt1%MOD;
			ll cnt2=(query(l,r,2,1,n,1)-minx*minx%MOD+MOD)%MOD;
			printf("%lld\n",((cnt1-cnt2)%MOD+MOD)%MOD);
		}else if(k==3)
		{
			ll minx=query_min(l,r,1,n,1);
			ll cnt1=(query(l,r,1,1,n,1)-minx+MOD)%MOD;
			ll cnt2=(query(l,r,2,1,n,1)-minx*minx%MOD+MOD)%MOD;
			ll cnt3=(query(l,r,3,1,n,1)-minx*minx%MOD*minx%MOD+MOD)%MOD;
			ll p=cnt1*cnt1%MOD*cnt1%MOD;
			ll q=3*cnt1%MOD*cnt2%MOD;
			cnt3=cnt3*2%MOD;
			printf("%lld\n",(p-q+cnt3+MOD)%MOD);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
