
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N (100000+10)
using namespace std;
int num[N];
							int temp[5];
bool judge(int x,int y,int z)
{
	if(!x || !y ||!z) return false;
	if(z>max(0,x-y)&&z<x+y) return true;
	return false;
}
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int Hive;
	scanf("%d",&Hive);
	for(int i=1;i<=Hive;i++)
	{
		scanf("%d",&num[i]);
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ju;
		scanf("%d",&ju);
		if(ju==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			num[x]=y;
		}else
		{
			bool flag=false;
			for(int k=3;k<=Hive;k++)
			{
				if(flag) break;
				for(int j=2;j<k;j++)
				{
					if(flag) break;
					for(int i=1;i<j;i++)
					{
						if(judge(num[i],num[j],num[k]))
						{
							memset(temp,0x3f,sizeof(temp));
							temp[0]=num[i];
							temp[1]=num[j];
							temp[2]=num[k];
							sort(temp,temp+3,cmp);
							printf("%d %d %d\n",temp[0],temp[1],temp[2]);
							flag=true;
							break;
						}
					}
				}
			}
			if(!flag)
			{
				puts("-1 -1 -1");
			}		
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
