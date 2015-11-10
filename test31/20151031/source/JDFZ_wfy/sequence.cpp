#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 110000
using namespace std;
int a[N];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,i,op,x,y,z;
	bool flag;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		else
		{
			flag=0;
			for(z=1;z<=n;z++)
			{
				for(y=1;y<z;y++)
				{
					for(x=1;x<y;x++)
					{
						if(a[x]+a[y]>a[z]&&abs(a[x]-a[y])<a[z])
							flag=1;
						if(flag)	break;
					}
					if(flag)	break;
				}
				if(flag)	break;
			}
			if(flag)
			printf("%d %lld %d\n",min(a[x],min(a[y],a[z])),(long long)a[x]+a[y]+a[z]-min(a[x],min(a[y],a[z]))-max(a[x],max(a[y],a[z])),max(a[x],max(a[y],a[z])));
			else
			puts("-1 -1 -1");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
