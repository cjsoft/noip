#include <iostream>
#include <cstdio>
const long long mOD=1000000009;
using namespace std;
typedef long long ll;

ll jiecheng[4007];
void init_jiecheng(){
	jiecheng[0]=1;
	for (int i = 1; i < 4007; ++i)
	{
		jiecheng[i]=(jiecheng[i-1]*i)%mOD;
	}
	jiecheng[0]=0;
}
ll n,w,b;

ll dfs_split(int t_left,int day_left){
	if(day_left==1)return jiecheng[t_left];
	ll temp=0;
	for (int i = 1; i <= t_left-day_left; i++) {
		temp+=dfs_split(t_left-i,day_left-1);
		temp%=mOD;
	}
	return temp;
}

int main(){
	init_jiecheng();
	cin>>n>>w>>b;
	
	return 0;
}