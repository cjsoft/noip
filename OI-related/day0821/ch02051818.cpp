#include <iostream>
#include <cstdio>
#include <stack>
#include <memory.h>
using namespace std;

int main(){
	while(1){
		int w,h;
		bool tag[27][27];
		char mp[27][27];
		stack<int>sx,sy;
		int cnt=0;
		memset(tag,false,sizeof(tag));
		memset(mp,0,sizeof(mp));
		scanf("%d %d",&w,&h);
		if(w==0 && h==0)break;
		for(int i=0;i<h;++i){
			scanf("%s",mp[i]);
		}
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				if(mp[i][j]=='@'){
					sx.push(j);
					sy.push(i);
				}
			}
		}
		while(!sx.empty() && !sy.empty()){
			int tx=sx.top(),ty=sy.top();
			sx.pop();sy.pop();
			if(tx>=0 && tx<w && ty>=0 && ty<h){
				if(tag[ty][tx])
					continue;
				if(!tag[ty][tx] && !(mp[ty][tx]!='.' && mp[ty][tx]!='@'))
					++cnt;
				tag[ty][tx]=true;
				if(mp[ty][tx]!='.' && mp[ty][tx]!='@')
					continue;
			}else continue;
			sx.push(tx+1);sy.push(ty);
			sx.push(tx-1);sy.push(ty);
			sx.push(tx);sy.push(ty+1);
			sx.push(tx);sy.push(ty-1);
		}
		printf("%d\n",cnt );
	}
	return 0;
}