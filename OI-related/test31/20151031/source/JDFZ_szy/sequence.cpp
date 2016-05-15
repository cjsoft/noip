#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 110000
int n,m;
int a[N];
struct pos
{
	int p1,p2,p3;
}p;
int tmp[5];
int t1,t2,t3;
int flag;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	n=min(n,50);
	p.p1=p.p2=p.p3=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{	
			for(int k=1;k<j;k++)
			{
				if(a[i]+a[j]>a[k]&&a[j]+a[k]>a[i]&&a[i]+a[k]>a[j])
				{
					p.p1=i;
					p.p2=j;
					p.p3=k;
					flag=1;
				}
				if(flag)
				break;
			}
			if(flag)
			break;
		}
		if(flag)
		break;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t3);
		if(t3==1)
		{
			scanf("%d%d",&t1,&t2);
			if(t1>50)
			{	
				continue;
			}
			a[t1]=t2;
			if(p.p1!=-1)
			{
				if(a[p.p1]+a[p.p2]<=a[p.p3]||a[p.p1]+a[p.p3]<=a[p.p2]||a[p.p2]+a[p.p3]<=a[p.p1])
				{	
					p.p1=p.p2=p.p3=-1;
					flag=0;
					for(int q=1;q<=n;q++)
					{
						for(int j=1;j<q;j++)
						{	
							for(int k=1;k<j;k++)
							{
								if(a[q]+a[j]>a[k]&&a[j]+a[k]>a[q]&&a[q]+a[k]>a[j])
								{
									p.p1=q;
									p.p2=j;
									p.p3=k;
									flag=1;
								}
								if(flag)
								break;
							}
							if(flag)
							break;
						}
						if(flag)
						break;
					}
				}
			}
			for(int j=1;j<=n;j++)
			if(j!=t1)
			{	
				for(int k=1;k<j;k++)
				if(k!=t1)
				{
					if(a[j]+a[k]>t2&&t2+a[j]>a[k]&&a[k]+t2>a[j])
					{
						tmp[1]=j;
						tmp[2]=k;
						tmp[3]=t1;
						sort(tmp+1,tmp+1+3);
						if(p.p1==-1||(tmp[3]<p.p1||(tmp[3]==p.p1&&tmp[2]<p.p2)||(tmp[3]==p.p1&&tmp[2]==p.p2&&tmp[1]<p.p3)))
						{
							p.p1=tmp[3];
							p.p2=tmp[2];
							p.p3=tmp[1];
						}
					}
				}
			}
		}
		else
		{
			if(p.p1==-1)
			printf("-1 -1 -1\n");
			else
			{
				tmp[1]=a[p.p1];
				tmp[2]=a[p.p2];
				tmp[3]=a[p.p3];
				sort(tmp+1,tmp+1+3);
				printf("%d %d %d\n",tmp[1],tmp[2],tmp[3]);
			}
		}
	}
	return 0;
}



