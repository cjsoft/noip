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
int dt1[2007][2007],dt2[2007][2007];


int main(){
	scanf("%d%d",&n,&m);
	memset(dt1,0,sizeof(dt1));
	memset(dt2,0,sizeof(dt2));
	int temp;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&temp);
			if(temp)
				a[i][j]=true;
			else
				a[i][j]=false;
		}
	}
	for(int i=n;i>=1;--i){
		for(int j=m-1;j>=2;--j){
			if(i==n && j==m-1)
				dt1[i][j]=1;
			else
				if(!a[i][j])
					dt1[i][j]=(dt1[i+1][j]+dt1[i][j+1])%MOD;
		}
	}
	for(int i=n-1;i>=2;--i){
		for(int j=m;j>=1;--j){
			if(i==n-1 && j==m)
				dt2[i][j]=1;
			else
				if(!a[i][j])
					dt2[i][j]=(dt2[i+1][j]+dt2[i][j+1])%MOD;
		}
	}
	printf("%d %d\n", dt1[1][2],dt2[2][1]);
	return 0;
}