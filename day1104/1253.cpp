// minute 多打了一个s qaq，认真一点、
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <climits>
using namespace std;
queue<int>xl,yr,zc,tms;
int l,r,c;
const int ax[]={
	0,1,0,-1,0,0,0
},ay[]={
	0,0,1,0,0,-1,0
},az[]={
	0,0,0,0,1,0,-1
};
int tag[37][37][37];
char maze[37][37][37];
int bfs(){
	int tx,ty,tz,tt;
	for(int i=1;i<=37;++i){
		for(int j=1;j<=37;++j){
			for(int k=1;k<=37;++k){
				tag[i-1][j-1][k-1]=INT_MAX;
			}
		}
	}

	while(!xl.empty()){
		tx=xl.front();xl.pop();
		ty=yr.front();yr.pop();
		tz=zc.front();zc.pop();
		tt=tms.front();tms.pop();
		if(tx>l || tx<1 || ty>r || ty<1 || tz>c || tz<1)continue;
		if(maze[tx][ty][tz]=='E')return tt;
		if(tag[tx][ty][tz]<=tt || maze[tx][ty][tz]=='#')continue;
		tag[tx][ty][tz]=tt;
		for(int i=1;i<=6;++i){
			xl.push(tx+ax[i]);
			yr.push(ty+ay[i]);
			zc.push(tz+az[i]);
			tms.push(tt+1);
		}
	}
	return 0;
}
int main(){
	while(1){
		scanf("%d%d%d",&l,&r,&c);
		if(l==0)return 0;
		memset(maze,0,sizeof(maze));
		while(!zc.empty()){
			xl.pop();yr.pop();zc.pop();tms.pop();
		}
		for(int i=1;i<=l;++i){
			for(int j=1;j<=r;++j){
				scanf("%s",maze[i][j]+1);
				for(int k=1;k<=c;++k){
					if(maze[i][j][k]=='S'){
						xl.push(i);
						yr.push(j);
						zc.push(k);
						tms.push(0);
					}
				}
			}
		}
		int temp=bfs();
		if(temp){
			printf("Escaped in %d minute(s).\n",temp);
		}else{
			printf("Trapped!\n");
		}
	}
	return 0;
}
