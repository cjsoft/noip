#include<stdio.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int n;
int m;
int a[100005];
bool judge(int a,int b,int c)
{
	int d=min(min(a,b),c);
	int f=max(max(a,b),c);
	int e=a^b^c^d^f;
	if(d+e>f)
	{
		printf("%d %d %d\n",d,e,f);
		return 1;
	}
	else
	{
		return 0;
	}
}
void find()
{
	for(int i=3;i<=50;i++)
	{
		for(int j=2;j<i;j++)
		{
			for(int k=1;k<j;k++)
			{
				if(judge(a[i],a[j],a[k]))
				{
					return;
				}
			}
		}
	}
	printf("-1 -1 -1\n");
	return;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	int opt,x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&opt);
		if(opt&1)
		{
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		else
		{
			find();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}