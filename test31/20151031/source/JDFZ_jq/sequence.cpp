#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,q;
int num[100005];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	scanf("%d",&q);
	while(q--)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			int b,c;
			scanf("%d %d",&b,&c);
			num[b]=c;
		}else
		{
			int si=0;
			for(int i=3;i<=n;i++)
			{
				for(int j=2;j<i;j++)
				{
					for(int k=1;k<j;k++)
					{
						int lon=max(num[i],max(num[j],num[k]));
						if(num[i]+num[j]+num[k]-lon>lon)
						{
							int minn=min(num[i],min(num[j],num[k]));
							int sec=num[i]+num[j]+num[k]-lon-minn;
							printf("%d %d %d\n",minn,sec,lon);
							si=1;
							break;
						}
					}
					if(si==1)break;
				}
				if(si==1)break;
			}
			if(si==0)
			{
				printf("-1 -1 -1\n");
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
