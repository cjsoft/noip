// 还没过
#include <iostream>
#include <cstdio>

using namespace std;
char mp[107][107];
int w,h;
struct node{
	int x,y;
	node(){
		x=y=0;
	}
	node(int xx,int yy){
		x=xx;y=yy;
	}
	bool operator==(const node &b)const{
		return x==b.x && y==b.y;
	}
	bool operator!=(const node &b)const{
		return !((*this)==b);
	}
};

node fa[107][107];

node getfa(node x){
	while(x!=fa[x.y][x.x]){
		x=fa[x.y][x.x];
	}
	return x;
}

void setfa(node a,node b){
	node ax=getfa(a);
	node bx=getfa(b);
	fa[ax.y][ax.x]=bx;
}

void init(){
	for(int i=0;i<107;++i){
		for(int j=0;j<107;++j){
			fa[i][j]=node(j,i);
		}
	}
}
node a[100007];
int tot=0;
int main(){
	init();
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;++i){
		scanf("%s",mp[i]);
		for(int j=1;j<=w;++j){
			if(mp[i][j]==mp[i-1][j]){
				setfa(node(j,i),node(j,i-1));
			}
			if(mp[i][j]==mp[i-1][j+1]){
				setfa(node(j,i),node(j+1,i-1));
			}
			if(mp[i][j]==mp[i][j-1]){
				setfa(node(j,i),node(j-1,i));
			}
			if(mp[i][j]==mp[i-1][j-1]){
				setfa(node(j,i),node(j-1,i-1));
			}
		}
	}
	for(int i=1;i<=h;++i){
		for(int j=1;j<=w;++j){
			if(mp[i][j]=='W'){
				node te=getfa(node(j,i));
				for(int k=0;k<tot;++k){
					if(a[k]==te){
						goto NXT;
					};
				}
				a[tot++]=te;
				NXT:;
			}
		}
	}
	printf("%d\n",tot);
	return 0;
}
