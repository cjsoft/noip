#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long
#define N 100005
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
int n,Q;
int num[N];
struct node
{
	int d,v;
	bool operator <(const node &a)const{
		return d<a.d;
	}
}x[N];
struct Segment
{
	int mn,len;
	unsigned int sum[7],sum2[7];
}tmp,a[N<<2];
void pushup(Segment &a,Segment b,Segment c)
{
	a.len=b.len+c.len;
	a.mn=min(b.mn,c.mn);
	for(int i=0;i<=min(6,a.len);i++)
	{
		a.sum[i]=0;
		for(int j=0;j<=min(b.len,i);j++)
		if(i-j<=c.len)
			a.sum[i]=b.sum[j]*c.sum[i-j]+a.sum[i];
	}
	if(b.mn<c.mn)
	{
		for(int i=0;i<=min(6,a.len-1);i++)
		{
			a.sum2[i]=0;
			for(int j=0;j<=min(b.len-1,i);j++)
			if(i-j<=c.len)
				a.sum2[i]=b.sum2[j]*c.sum[i-j]+a.sum2[i];
		}
	}
	else
	{
		for(int i=0;i<=min(6,a.len-1);i++)
		{
			a.sum2[i]=0;
			for(int j=0;j<=min(c.len-1,i);j++)
			if(i-j<=b.len)
				a.sum2[i]=c.sum2[j]*b.sum[i-j]+a.sum2[i];
		}
	}
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		a[rt].len=1;
		a[rt].sum[0]=a[rt].sum2[0]=1;
		a[rt].mn=a[rt].sum[1]=x[l].v;
		return;
	}
	int mid=(l+r)>>1;
	build(lson);
	build(rson);
	pushup(a[rt],a[rt<<1],a[rt<<1|1]);
}
Segment get_ans(int l,int r,int rt,int L,int R)
{
	if(L==l&&R==r) return a[rt];
	int mid=(l+r)>>1;
	if(R<=mid) return get_ans(lson,L,R);
	else if(L>mid) return get_ans(rson,L,R);
	else
	{
		Segment ret;
		memset(&ret,0,sizeof(ret));
		pushup(ret,get_ans(lson,L,mid),get_ans(rson,mid+1,R));
		return ret;
	}
}
unsigned int p[7]={1,1,2,6,24,120,720};
int main()
{
	freopen("melancholy.in","r",stdin);
	freopen("melancholy.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i].d),num[i]=x[i].d;
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i].v);
	sort(x+1,x+n+1);
	sort(num+1,num+n+1);
	build(1,n,1);
	for(int l,r,k,i=1;i<=Q;i++)
	{
		scanf("%d%d%d",&l,&r,&k);
		l=lower_bound(num+1,num+n+1,l)-num;
		r=upper_bound(num+1,num+n+1,r)-num-1;
		if(r-l<k)
		{
			puts("0");
			continue;
		}
		tmp=get_ans(1,n,1,l,r);
		printf("%u\n",tmp.sum2[k]*p[k]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
