#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
using namespace std;
int n,m;
int a[N];

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int q,x,y;
		scanf("%d",&q);
		if(q==1)
		{
			scanf("%d%d",&x,&y);
			a[x]=y;
		}else
		{
			bool flag=false;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<i;j++)
				{
					for(int k=1;k<j;k++)
					{
						int s1=min(a[i],min(a[j],a[k]));
						int s3=max(a[i],max(a[j],a[k]));
						int s2=a[i];
						if(s2==s1||s2==s3)s2=a[j];
						if(s2==s1||s2==s3)s2=a[k];
						if(s1+s2>s3)
						{
							flag=true;
							printf("%d %d %d\n",s1,s2,s3);
							break;
						}
					}
					if(flag)break;
				}
				if(flag)break;
			}
			if(!flag)printf("-1 -1 -1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
