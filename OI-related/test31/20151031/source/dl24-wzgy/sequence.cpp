#include<cstdio>
#include<queue>
using namespace std;
#define f(x,y,z) for(int x=(y);x<=(z);++x)
#define maxn 100017
int a[maxn];
int n,m,l,x,y;
bool tri(int x,int y,int z)
{
	if (x+y<=z) return false;
	if (x+z<=y) return false;
	if (z+y<=x) return false;
	return true;
}
void p(int x,int y,int z)
{
	priority_queue <int,vector<int>,greater<int> > Q;
	Q.push(x);
	Q.push(y);
	Q.push(z);
	printf("%d ",Q.top());
	Q.pop();
	printf("%d ",Q.top());
	Q.pop();
	printf("%d\n",Q.top());
	return;
}
void res(int l)
{
		if (l==1)
		{
			scanf("%d %d",&x,&y);
			a[x]=y;
			return;
		}
		else
		{
			f(j,3,n)
			f(k,2,j-1)
			f(l,1,k-1)
			if (tri(a[j],a[k],a[l])) 
			{	
			p(a[j],a[k],a[l]);
			return;
			}
			printf("-1 -1 -1");
		}
		return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	f(i,1,n) scanf("%d",&a[i]);
	scanf("%d",&m);
	f(i,1,m)
	{
		scanf("%d",&l);
		res(l);
	}
}