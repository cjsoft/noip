// 然而再一次被 不（好好）读题 坑了、

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int mp[1007][1007];
queue<int>id,cntl;
int degree[1007];
int ts[1007];
int n,m;
bool tag[1007];
int main(){
	scanf("%d %d",&n,&m);
	memset(mp,0,sizeof(mp));
	memset(degree,0,sizeof(degree));
	int tsi,ttt;
	int st=9999,ed=0;
	for (int i = 0; i < m; ++i){
		scanf("%d",&tsi);
		memset(ts,0,sizeof(ts));
		memset(tag,false,sizeof(tag));
		st=9999;ed=0;
		for (int j = 0; j < tsi; ++j)
		{
			scanf("%d",ts+j);
			st=min(st,ts[j]);
			ed=max(ts[j],ed);
			tag[ts[j]]=true;
		}
		for (int j = st; j <= ed; ++j){
			if(tag[j])
				continue;
			for (int k = 0; k <tsi ; ++k)
			{
				if(!mp[j][ts[k]])
					degree[ts[k]]++;
				mp[j][ts[k]]=1;
			}
		}
	}
	for (int i = 1; i <=n; ++i)
	{
		if(!degree[i]){
			id.push(i);
			cntl.push(1);
		}
	}
	int tid,tcntl;
	while(!id.empty()){
		tid=id.front();id.pop();
		tcntl=cntl.front();cntl.pop();
		for (int i = 1; i <=n; ++i){
			if(mp[tid][i]){
				degree[i]--;
				if(!degree[i]){
					id.push(i);
					cntl.push(tcntl+1);
				}
			}
		}
	}
	printf("%d\n", tcntl);
	return 0;
}