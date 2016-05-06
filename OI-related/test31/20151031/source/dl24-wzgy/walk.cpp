#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100017
#define M 1000000007
#define f(x,y,z) for (int x=(y); x<=(z); ++x)
using namespace std;
int a[maxn],b[maxn];
int n,c,po=1;

struct node
{
	int x,y;
}p[1007];

bool cmp(node a,node b)
{
	if (a.y!=b.y) return a.y<b.y;
	return  a.x<b.x;
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d",&n);scanf("%d",&c);f(i,1,c) scanf("%d %d",&p[i].x,&p[i].y);
	sort(p+1,p+c+1,cmp);
	f(i,0,n) b[i]=1; while (p[po].y==0&&po<=c) b[p[po++].x]=0;
	// f(i,0,n) printf("%d ",b[i]); printf("\n");
	f(i,1,n)
	{
		memset(a,0,sizeof(a));
		// f(k,0,n) printf("%d ",a[k]); printf("\n");
		// printf("%d\n",po);
		while (p[po].y==i&&po<=c) a[p[po++].x]=-1; 
		f(j,i,n) 
		{
		// printf("%d %d %d %d\n",j,a[j],a[j-1],b[j]);
		if (a[j]>=0) a[j]=(a[j-1]+b[j]) %M;else a[j]=0;
		}
		// f(k,0,n) printf("%d ",a[k]); printf("\n");
		f(l,i,n) b[l]=a[l];
	}
	printf("%d",b[n]);
}