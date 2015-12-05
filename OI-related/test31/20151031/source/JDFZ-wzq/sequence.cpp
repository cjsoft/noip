#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100100
using namespace std;
int n,m;
int a[N];
int use[5];
struct node
{
	int x,y,z;
	node(){}
	node(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
	friend ostream& operator << (ostream &_,node a)
	{printf("%d %d %d\n",a.x,a.y,a.z);return _;}
};
bool check(int x,int y,int z)
{
	use[0]=x,use[1]=y,use[2]=z;
	sort(use,use+3);
	return use[0]+use[1]>use[2]?1:0;
}
node query()
{
	int up=min(n,50);
	for(int i=3;i<=up;i++)
		for(int j=2;j<i;j++)
			for(int k=1;k<j;k++)
				if(check(a[i],a[j],a[k]))return node(a[i],a[j],a[k]);
	return node(-1,-1,-1);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]=y;
		}else 
		{
			node tmp=query();
			use[0]=tmp.x,use[1]=tmp.y,use[2]=tmp.z;
			sort(use,use+3);
			tmp.x=use[0],tmp.y=use[1],tmp.z=use[2];
			cout<<tmp;
		}
	}
}
