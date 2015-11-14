#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 110000
#define ui unsigned int 
int n,q;
ui d[N],v[N];
ui tree[N*4],mi[N*4];
struct node
{
	int dis,val;
}a[N];
int cmp(node x,node y)
{
	return x.dis<y.dis;
}
ui l,r,k;
void pushup(int now)
{
	tree[now]=tree[now*2]+tree[now*2+1];
	mi[now]=min(mi[now*2],mi[now*2+1]);
}
void build(int l,int r,int now)
{
	if(l==r)
	{
		tree[now]=v[l];
		mi[now]=v[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,now*2);
	build(mid+1,r,now*2+1);
	pushup(now);
}
ui query(int l,int r,int lq,int rq,int now)
{
	if(lq<=l&&r<=rq)
	return tree[now];
	int mid=(l+r)>>1;
	ui ret;
	if(mid>lq)
	ret+=query(l,mid,lq,rq,now*2);
	if(mid<rq)
	ret+=query(mid+1,r,lq,rq,now*2+1);
	return ret;
}
ui query1(int l,int r,int lq,int rq,int now)
{
	if(lq<=l&&r<=rq)
	return mi[now];
	int mid=(l+r)>>1;
	ui ret=1<<30;
	if(mid>lq)
	ret=min(ret,query(l,mid,lq,rq,now*2));
	if(mid<rq)
	ret=min(ret,query(mid+1,r,lq,rq,now*2+1));
	return ret;
}
int main()
{
	freopen("Melancholy.in","r",stdin);
	freopen("Melancholy.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].dis);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i].dis;
		v[i]=a[i].val;
	}
	build(1,n,1);
	for(int i=1;i<=q;i++)
	{	
		//scanf("%d%d%d",&l,&r,&k);
		cin>>l>>r>>k;
		int t1=upper_bound(d+1,d+1+n,l-1)-d;
		int t2=lower_bound(d+1,d+1+n,r)-d;
		if(t1==t2)
		printf("0\n");
		else
		cout<<query(1,n,t1,t2,1)-query1(1,n,t1,t2,1)<<endl;
	}
	return 0;
}




