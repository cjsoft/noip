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

int main(){
	scanf("%d %d",&n,&m);
	memset(mp,0,sizeof(mp));
	memset(degree,0,sizeof(degree));
	int tsi,ttt;
	for (int i = 0; i < m; ++i){
		scanf("%d",&tsi);
		memset(ts,0,sizeof(ts));
		for (int j = 0; j < tsi; ++j)
		{
			scanf("%d",ts+j);
		}
		for (int j = 1; j <= n; ++j){
			for (int k = 0; k <tsi ; ++k){
				if(ts[k]==j)
					goto JMP;
			}
			for (int k = 0; k <tsi ; ++k)
			{
				if(mp[j][ts[k]])
					degree[ts[k]]++;
				else
					mp[j][ts[k]]=1;
			}
			JMP:;
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
		printf("%d\n",tcntl );
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