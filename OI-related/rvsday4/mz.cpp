#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
int n,m;
char mp[21][21];
bool tag[21][21];
int kneed[5];
inline int qaq(int x,int y){
	return mp[y][x]-'a';
}
struct KSS{
	int cnt[5];
	KSS(){
		memset(cnt,0,sizeof(cnt));
	}
};
bool global_resu=false;
void floodfill(int x,int y,KSS &k,KSS b){
	if(x<1 || x>n || y<1 || y>m)return;
	if(tag[y][x] || mp[y][x]=='X')return;
	tag[y][x]=true;
	if(mp[y][x]=='G'){
		global_resu=true;
		return;
	}
	if(mp[y][x]>='a' && mp[y][x]<='e'){
		k.cnt[qaq(x,y)]++;
	}
	
	if(mp[y][x]>='A' && mp[y][x]<='E'){
		if(b.cnt[mp[y][x]-'A']!=kneed[mp[y][x]-'A']){
			return;
		}
	}
	floodfill(x+1,y,k,b);
	floodfill(x-1,y,k,b);
	floodfill(x,y+1,k,b);
	floodfill(x,y-1,k,b);
}

int main(){
	while(true){
		int xx,yy;
		scanf("%d%d",&m,&n);
		if(m==0)return 0;
		memset(kneed,0,sizeof(kneed));
		global_resu=false;
		for(int i=1;i<=m;++i){
			scanf("%s",mp[i]+1);
			for(int j=1;j<=n;++j){
				if(mp[i][j]=='S'){
					xx=j;yy=i;
				}
				if(mp[i][j]>='a' && mp[i][j]<='e'){
					kneed[qaq(j,i)]++;
				}
			}
		}
		int totalk=0;
		KSS ss,tt;
		memset(tag,false,sizeof(tag));
		floodfill(xx,yy,ss,tt);
		tt=ss;
		totalk=0;
		for(int i=0;i<5;++i){
			totalk+=tt.cnt[i];
		}
		if(global_resu){
			printf("YES\n");
			goto CNTI;
		}
		while(true){
			memset(tag,false,sizeof(tag));
			ss=KSS();
			floodfill(xx,yy,ss,tt);
			int t=0;
			for(int i=0;i<5;++i){
				t+=ss.cnt[i];
			}
			tt=ss;
			if(global_resu){
				printf("YES\n");
				goto CNTI;
			}
			if(t<=totalk){
				printf("NO\n");
				goto CNTI;
			}
			totalk=t;
		}

		CNTI:;
	}
	return 0;
}
