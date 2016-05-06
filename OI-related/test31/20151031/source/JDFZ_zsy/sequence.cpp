#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
int a[100010];
int next[100010];
map <int, int >fir;
map <int, int >la;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(fir[a[i]]==0)
		{
			fir[a[i]]=i;
			la[a[i]]=i;
		}else
		{
			next[la[a[i]]]=i;
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d%d",&y,&z);
			a[y]=z;
		}else
		{
			int flag=0;
			for(int i=1;i<=n;i++)
			{
				if(flag)
				{
					break;
				}
				for(int j=1;j<i;j++)
				{
					if(flag)
					{
						break;
					}
					for(int k=1;k<j;k++)
					{
						int c[4];
						c[1]=a[i];
						c[2]=a[j];
						c[3]=a[k];
						sort(c+1,c+4);
						if(c[1]+c[2]>c[3])
						{
							printf("%d %d %d\n",c[1],c[2],c[3]);
							flag=1;
							break;
						}
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
