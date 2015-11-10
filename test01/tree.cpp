#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
int n,x,y,z,m;
int mp [3007][3007];
int dis[3007][3007];
void dfs(int root,int from,int id,int depth){
	dis[id][root]=min(dis[id][root],depth);
	for(int i=0;i<3007;++i){
		if(mp[root][i] && i!=from){
			dfs(i,root,id,depth+mp[root][i]);
		}
	}
}
int main(){
	open("tree.in","tree.out");
	scanf("%d",&n);
	for(int i=0;i<n-1;++i){
		scanf("%d%d%d",&x,&y,&z);
		mp[x][y]=mp[y][x]=z;
	}
	for(int i=0;i<3007;++i){
		for(int j=0;j<3007;++j){
			dis[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;++i){
		dfs(i,0,i,0);
	}
	scanf("%d",&m);
	int a,b,c,d,mmm=0;
	for(int i=0;i<m;++i){
		mmm=0;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int j=a;j<=b;++j){
			for(int k=c;k<=d;++k){
				mmm=max(dis[j][k],mmm);
			}
		}
		printf("%d\n",mmm);
		
	}
	return 0;
}
