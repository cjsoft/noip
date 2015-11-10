#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 5010
#define MOD 1000000007
using namespace std;
int n,m;
int map[N][N];

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>m;
	n++;
	memset(map,0x7f,sizeof(map));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x++,y++;
		map[x][y]=0;
	}
	for(int i=0;i<n;i++)map[i][0]=0,map[i][i+1]=0;
	map[1][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(map[i][j]==0)continue;
			map[i][j]=map[i-1][j]+map[i][j-1];
		}
	}
	cout<<map[n][n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

