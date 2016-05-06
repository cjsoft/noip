// zhu yi ti mu yao qiu zi dianxu

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

bool tag [37][37];
int path[37][2];
int p,q;

bool dfs(int x,int y,int cnt){
	if(tag[x][y])
		return false;
	if(x>q || y>p || y<1 || x<1){
		return false;
	}
	tag[x][y]=true;
	path[cnt][0]=x;
	path[cnt][1]=y;
	if(cnt==p*q){
		for(int i=1;i<=cnt;++i){
			printf("%c%d",char(path[i][0]+'A'-1),path[i][1]);
		}
		putchar('\n');
		return true;
	}
	if(dfs(x-2,y-1,cnt+1))return true;
	if(dfs(x-2,y+1,cnt+1))return true;
	if(dfs(x-1,y-2,cnt+1))return true;
	if(dfs(x-1,y+2,cnt+1))return true;
	if(dfs(x+1,y-2,cnt+1))return true;
	if(dfs(x+1,y+2,cnt+1))return true;
	if(dfs(x+2,y-1,cnt+1))return true;
	if(dfs(x+2,y+1,cnt+1))return true;
	tag[x][y]=false;
	return false;
}


int main(){
	int n;
	cin>>n;
	int cnt=1;
	while(n--){
		printf("Scenario #%d:\n",cnt++);
		cin>>p>>q;
		bool ta=false;
		for(int i=1;i<=p;++i)
			for( int j=1;j<=q;++j){
				memset(tag,false,sizeof(tag));
				if (dfs(1,1,1)){
					ta=true;
					goto DO;
				}
			}
	DO:;
		if(!ta)cout<<"impossible"<<endl;
		putchar('\n');
	}
	return 0;
}
