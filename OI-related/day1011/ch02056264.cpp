#include <iostream>
#include <cstdio>
#include <memory.h>
#include <climits>
#define self (*this)

using namespace std;
typedef long long ll;

char mp[107][107];
int dist[107][107];
int n,m,sx,sy,tx,ty;
void dfs(int x,int y,int cdist){
	if(mp[y][x]=='T'){
		dist[y][x]=min(cdist,dist[y][x]);
		return ;
	}
	if(mp[y][x]!='.' && mp[y][x]!='S')
		return ;
	if(dist[y][x]==INT_MAX)
		goto D;
	if(cdist>=dist[y][x])
		return ;
	D:;
	dist[y][x]=cdist;
	dfs(x+1,y,cdist+1);
	dfs(x-1,y,cdist+1);
	dfs(x,y+1,cdist+1);
	dfs(x,y-1,cdist+1);
}
int main(){
	cin>>n>>m;
	memset(mp,0,sizeof(mp));
	for(int i=0;i<107;++i){
		for(int j=0;j<107;++j){
			dist[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>mp[i][j];
			if(mp[i][j]=='S')
				sx=j,sy=i;
			if(mp[i][j]=='T')
				tx=j,ty=i;
		}
	}
	dfs(sx,sy,0);
	cout<<dist[ty][tx]<<endl;
	return 0;
}