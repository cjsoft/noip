#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;
int n,m;
int a[100005],x[3];
int st[55],top;
int p1,p2,p3;
bool flag;
set<int> s;
set<int>::iterator it;
void print()
{
	x[0]=a[p1],x[1]=a[p2],x[2]=a[p3];
	sort(x,x+3);
	printf("%d %d %d\n",x[0],x[1],x[2]);
}
void check(int x,int y,int z)
{
	if(a[x]+a[y]<=a[z]||a[x]+a[z]<=a[y]||a[y]+a[z]<=a[x]) return;
	if(!flag) p1=x,p2=y,p3=z,flag=1;
	else
	{
		if(z<p3) p3=z,p2=y,p1=x;
		else if(z==p3&&y<p2) p2=y,p1=x;
		else if(z==p3&&y==p2&&x<p1) p1=x;
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]) s.insert(i);
	}
	cin>>m;
	for(int op,x,y,i=1;i<=m;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			if(y==0)
			{
				if(a[x]) s.erase(x);
				a[x]=0;
			}
			else
			{
				if(!a[x]) s.insert(x);
				a[x]=y;
			}
		}
		else
		{
			top=0;flag=0;
			for(it=s.begin();it!=s.end();it++)
			{
				st[++top]=*it;
				if(top>=50) break;
			}
			for(int i=1;i<=top;i++)
			{
				for(int j=i+1;j<=top;j++)
				{
					for(int k=j+1;k<=top;k++)
					{
						check(st[i],st[j],st[k]);
						if(flag&&p3<=st[k]) break;
					}
					if(flag&&p3<=st[j]) break;
				}
				if(flag&&p3<=st[i]) break;
			}
			if(!flag) puts("-1 -1 -1");
			else print();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
