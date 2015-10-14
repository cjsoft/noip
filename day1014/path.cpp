#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstdlib>
#include <ctime>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
const int MOD=5462617;

using namespace std;

int n,m;
bool a[2007][2007];
int dt[2007][2007];

int dfs(int rn,int lx){
	for (int i =2; i < n; ++i)
	{
		
	}
}

int main(){
	open("path.in","path.out");
	srand((int)time(0));
	srand(rand()*rand());
	srand(rand()*rand());
	srand(rand()*rand());
	scanf("%d%d",&n,&m);
	int temp;
	for (int i = 1; i <=n; ++i){
		for (int j = 1; j <=m; ++j){
			scanf("%d",&temp);
			if(temp)a[i][j]=true;else a[i][j]=false;
		}
	}
	memset(dt,0,sizeof(dt));
	for (int i = n; i >0; --i){
		for (int j = m; j >0; --j)
		{
			if(i==n && j==m){
				dt[i][j]=1;
			}else{
				if(!a[i][j])dt[i][j]=(dt[i+1][j]+dt[i][j+1])%MOD;
			}
		}
	}
	srand(rand()*(int)time(0));
	printf("%d\n", rand()%(dt[1][1]*dt[1][1])+1);
	return 0;
}