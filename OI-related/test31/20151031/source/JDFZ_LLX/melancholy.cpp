#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef unsigned int ui;
ui min(ui a,ui b)
{
	return a<b?a:b;
}
ui n;
ui q;
ui d[100005];
ui v[100005];
ui value[100005];
pair<ui,ui*>b[100005];
struct Segmenttree
{
	ui minval;
	ui sum[7];
	Segmenttree()
	{
		minval=0x3f3f3f3f;
		memset(sum,0,sizeof(sum));
		sum[0]=1;
	}
	friend Segmenttree operator*(Segmenttree a,Segmenttree b)
	{
		Segmenttree re;
		re.minval=min(a.minval,b.minval);
		for(ui i=1;i<=6;i++)
		{
			for(ui j=1;j<=i;j++)
			{
				re.sum[i]+=a.sum[j]*b.sum[i-j];
			}
		}
		return re;
	}
}tr[100005<<2];
void pushup(ui rt)
{
	tr[rt].minval=min(tr[rt<<1].minval,tr[rt<<1|1].minval);
	for(ui i=1;i<=6;i++)
	{
		for(ui j=0;j<=i;j++)
		{
			tr[rt].sum[i]+=tr[rt<<1].sum[j]*tr[rt<<1|1].sum[i-j];
		}
	}
}
void build(ui l,ui r,ui rt)
{
	if(l==r)
	{
		tr[rt].minval=value[l];
		tr[rt].sum[0]=1;
		tr[rt].sum[1]=value[l];
		return;
	}
	ui mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pushup(rt);
}
Segmenttree query(ui L,ui R,ui l,ui r,ui rt)
{
	if(L<=l&&r<=R)
	{
		return tr[rt];
	}
	ui mid=(l+r)>>1;
	Segmenttree re;
	if(L<=mid&&mid<R)
	{
		re=query(L,R,l,mid,rt<<1)*query(L,R,mid+1,r,rt<<1|1);
	}
	else
	{
		if(L<=mid)
		{
			re=query(L,R,l,mid,rt<<1);
		}
		if(mid<R)
		{
			re=query(L,R,mid+1,r,rt<<1|1);
		}
	}
	return re;
}
ui find(ui x)
{
	ui l=1;
	ui r=n;
	ui mid;
	ui re;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(b[mid].first>=x)
		{
			re=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return re;
}
int main()
{
	//freopen("melancholy.in","r",stdin);
	//freopen("melancholy.out","w",stdout);
	scanf("%u%u",&n,&q);
	for(ui i=1;i<=n;i++)
	{
		scanf("%u",&d[i]);
		b[i]=make_pair(d[i],&d[i]);
	}
	sort(b+1,b+1+n);
	ui t=0;
	for(ui i=1;i<=n;i++)
	{
		if(i==1||b[i].first!=b[i-1].first)
		{
			t++;
		}
		*b[i].second=t;
	}
	for(ui i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
	}
	for(ui i=1;i<=n;i++)
	{
		value[d[i]]=v[i];
	}
	build(1,n,1);
	ui l,r,k;
	for(ui i=1;i<=q;i++)
	{
		scanf("%u%u%u",&l,&r,&k);
		l=find(l);
		r=find(r);
		Segmenttree ans=query(l,r,1,n,1);
		printf("%u\n",ans.sum[k]-ans.sum[k-1]*ans.minval+(k>=2?ans.sum[k-2]:0));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
