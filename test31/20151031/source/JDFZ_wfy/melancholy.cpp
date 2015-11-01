#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 110000
#define K 6
#define lson l,mid,no<<1
#define rson mid+1,r,no<<1|1
using namespace std;
typedef unsigned int it;
struct node
{
	it mi,sum[7];
}tr[N<<2];
it D[N];
it V[N],fact[K];
it dis[N],pos[N];
node Pushup(node l,node r)
{
	static node ret;
	static it i,j;
	ret.mi=min(l.mi,r.mi);
	ret.sum[0]=1;
	for(i=1;i<=K;i++)
	{
		ret.sum[i]=0;
		for(j=0;j<=i;j++)
		{
			ret.sum[i]+=l.sum[j]*r.sum[i-j];
		}
	}
	for(i=K;i>=1;i--)
	{
		ret.sum[i]+=max(l.mi,r.mi)*ret.sum[i-1];
	}
	return ret;
}
void Build(it l,it r,it no)
{
	if(l==r)
	{
		tr[no].mi=V[pos[l]];
		tr[no].sum[0]=1;
	}
	else
	{
		it mid=(l+r)>>1;
		Build(lson);
		Build(rson);
		tr[no]=Pushup(tr[no<<1],tr[no<<1|1]);
	}
}
node query(it l,it r,it no,it st,it en)
{
	if(st<=l&&r<=en)
		return tr[no];
	else
	{
		it mid=(l+r)>>1;
		if(en<=mid)		return query(lson,st,en);
		else if(st>mid)	return query(rson,st,en);
		else	return Pushup(query(lson,st,en),query(rson,st,en));
	}
}
int main()
{
	freopen("melancholy.in","r",stdin);
	freopen("melancholy.out","w",stdout);
	it n,m,i,k,l,r;
	scanf("%u%u",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%u",D+i);
		dis[i]=D[i];
	}
	sort(dis+1,dis+n+1);
	for(i=1;i<=n;i++)
	{
		scanf("%u",V+i);
		D[i]=lower_bound(dis+1,dis+n+1,D[i])-dis;
		pos[D[i]]=i;
	}
	Build(1,n,1);
	fact[0]=1;
	for(i=1;i<=K;i++)
		fact[i]=fact[i-1]*i;
	for(i=1;i<=m;i++)
	{
		scanf("%u%u%u",&l,&r,&k);
		l=lower_bound(dis+1,dis+n+1,l)-dis;
		r=upper_bound(dis+1,dis+n+1,r)-dis-1;
		printf("%u\n",fact[k]*query(1,n,1,l,r).sum[k]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

