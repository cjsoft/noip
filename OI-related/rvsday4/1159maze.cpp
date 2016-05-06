#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>


const short up=1,right=2,down=3,left=4;
using namespace std;
typedef long long ll;
int n,m;
short kcnt[256];
short tag[21][21];
char mp[21][21];
struct STAT{
	short ks[5];
	bool tag[21][21];
	int x,y;
};
queue<STAT> q;
bool bfs(){
	STAT temp;
	while(!q.empty()){
		putchar('#');
		temp=q.front();
		q.pop();
		if (mp[temp.y][temp.x]=='G')return true;
		if (mp[temp.y][temp.x]=='X')continue;
		if (mp[temp.y][temp.x]>='a' && mp[temp.y][temp.x]<='e' && temp.tag[temp.y][temp.x]==false){
			temp.ks[mp[temp.y][temp.x]-'a']++;
			temp.tag[temp.y][temp.x]=true;
		}
		if (mp[temp.y][temp.x]>='A' && mp[temp.y][temp.x]<='E' && temp.ks[mp[temp.y][temp.x]-'A']!=kcnt[mp[temp.y][temp.x]-'A']){
			continue;
		}
		temp.x--;
		if(temp.x>0 && temp.x<=n)
		q.push(temp);
		temp.x+=2;
		if(temp.x>0 && temp.x<=n)
		q.push(temp);
		temp.x--;
		temp.y++;
		if(temp.y>0 && temp.y<=m)
		q.push(temp);
		temp.y-=2;
		if(temp.y>0 && temp.y<=m)
		q.push(temp);
	}
	return false;
//	while(!lx.empty()){
//		short tx=lx.front();lx.pop();
//		short ty=ly.front();ly.pop();
//		short tdir=ld.front();ld.pop();
//		if(tdir==up){
//			if(tx-1>=1){lx.push(tx-1);ly.push(ty);ld.push(left);}
//			if(tx+1<=n){lx.push(tx+1);ly.push(ty);ld.push(right);}
//			if(ty+1<=m){lx.push(tx);ly.push(ty+1);ld.push(up);}
//		}else if(tdir==right){
//			if(tx+1<=n){lx.push(tx+1);ly.push(ty);ld.push(right);}
//			if(ty+1<=m){lx.push(tx);ly.push(ty+1);ld.push(up);}
//			if(ty-1>=1){lx.push(tx);ly.push(ty-1);ld.push(down);}
//		}else if(t
}

short ks[256];

bool dfs(int x,int y){
	if(x<1 || x>n || y<1 || y>m){
		return false;
	}
	if(mp[y][x]=='G')return true;
	if(tag[y][x]<=0 || mp[y][x]=='X'){
		return false;
	}
	if(mp[y][x]>='A' && mp[y][x]<='E'){
		if(ks[mp[y][x]])return false;
	}
	if(mp[y][x]>='a' && mp[y][x]<='e'){
		ks[mp[y][x]-'a'+'A']--;
	}
	tag[y][x]--;
	if(dfs(x+1,y))return true;
	if(dfs(x-1,y))return true;
	if(dfs(x,y+1))return true;
	if(dfs(x,y-1))return true;
	if(mp[y][x]>='a' && mp[y][x]<='e'){
		ks[mp[y][x]-'a'+'A']++;
	}
	tag[y][x]++;
	return false;
	
}

int main(){
	for(int i=0;i<21;++i){
		for(int j=0;j<21;++j){
			tag[i][j]=6;
		}
	}
	while (1){
		scanf("%d%d",&m,&n); //y,x
		if(m==0)break;
		memset(ks,0,sizeof(ks));
		int xx,yy;
		for(int i=1;i<=n;++i){
			scanf("%s",mp[i]+1);
			for(int j=1;j<=m;++j){
				if(mp[i][j]>='a' && mp[i][j]<='e'){
					kcnt[mp[i][j]-'a']++;
				}
				if(mp[i][j]=='S'){
					xx=j;
					yy=i;
				}
			}
		}
		STAT a;
		while(!q.empty())q.pop();
		a.x=xx;a.y=yy;
		q.push(a);
		if(bfs()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
