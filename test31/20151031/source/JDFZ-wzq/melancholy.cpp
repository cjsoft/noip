#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200100
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define INF 2000000000
using namespace std;
typedef unsigned int ll;
int n,q;
struct node
{
	ll d,v;
	friend bool operator < (node a,node b)
	{
		if(a.d==b.d)return a.v<b.v;
		return a.d<b.d;
	}
}pt[N];
struct Element
{
	ll mi;
	ll sum[7];
}seg[N*4];
Element operator * (Element a,Element b)
{
	Element c;
	c.mi=min(a.mi,b.mi);
	memset(c.sum,0,sizeof(c.sum));
	c.sum[0]=1;
	for(int i=1;i<=6;i++)
		for(int j=0;j<=i;j++)
			c.sum[i]+=a.sum[j]*b.sum[i-j];
	return c;
}
void build(int l,int r,int rt)
{
	seg[rt].sum[0]=1;
	seg[rt].mi=INF;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(lson),build(rson);
}
void update(int p,ll v,int l,int r,int rt)
{
	if(l==r)
	{
		seg[rt].sum[1]=seg[rt].mi=v;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)update(p,v,lson);
	else update(p,v,rson);
	seg[rt]=seg[rt<<1]*seg[rt<<1|1];
}
Element query(int L,int R,int l,int r,int rt)
{
	Element ansl,ansr,ansx;
	if(L<=l&&r<=R)return seg[rt];
	int mid=(l+r)>>1;
	if(L<=mid)
		ansl=query(L,R,lson);
	else
	{
		ansl.mi=INF;
		memset(ansl.sum,0,sizeof(ansl.sum));
		ansl.sum[0]=1;
	}
	if(R>mid)
		ansr=query(L,R,rson);
	else 
	{
		ansr.mi=INF;
		memset(ansr.sum,0,sizeof(ansr.sum));
		ansr.sum[0]=1;
	}
	ansx=ansl*ansr;
	return ansx; 
}
int find(int x)
{
	int l=0,r=n+1,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(pt[mid].d<x)l=mid;
		else r=mid;
	}
	return l+1;
}
ll fac[11];
int main()
{
	freopen("melancholy.in","r",stdin);
	freopen("melancholy.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=6;i++)
		fac[i]=fac[i-1]*i;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>pt[i].d;
	for(int i=1;i<=n;i++)
		cin>>pt[i].v;
	sort(pt+1,pt+n+1);
	build(1,n,1);
	for(int i=1;i<=n;i++)
		update(i,pt[i].v,1,n,1);
	for(int i=1;i<=q;i++)
	{
		ll L,R,k;
		cin>>L>>R>>k;
		ll opt=R;
		L=find(L),R=find(R);
		if(pt[R].d!=opt)R--;
		if(L>R||R-L+1<k){puts("0");continue;}
		Element ans=query(L,R,1,n,1);
		ll print=0;
		ll Min=1;
		int flag=1;
		for(int i=k;i>=0;i--)
		{
			print+=ans.sum[i]*Min*flag;
			Min=Min*ans.mi;
			flag=-flag;
		}
		cout<<print*fac[k]<<endl;
    }
}
