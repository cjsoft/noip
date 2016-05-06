#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int prime[]={1,2,3,5,7,11,13,17,19,23,29,31};
int result[1007];
void dfs(int k,int cnt_yinzi,int cur_num,int last){
	if(k==12){
		result[cnt_yinzi]=min(result[cnt_yinzi],cur_num);
		return;
	}
	int now=cur_num;
	for (int i = 0; i <=last; ++i){
		dfs(k+1,cnt_yinzi*(i+1),now,i);
		now*=prime[k];
		if(now> 20000000)
			break;
	}
}
int tot=0;
int asd[1007];
int m,n;
int main(){
	for (int i = 0; i < 1007; ++i)
	{
		result[i]=INT_MAX;
	}
	dfs(1,1,1,21);
	cin>>m>>n;
	for (int i = 0; i < 1007; ++i)
	{
		if(result[i]>=m && result[i]<=n)
			asd[tot++]=result[i];
	}
	sort(asd,asd+tot);
	bool tag=false;
	for (int i = 0; i < tot; ++i)
	{
		tag=true;
		cout<<asd[i];
		if(i!=tot-1)
			putchar(',');
	}
	if(!tag)
		cout<<"NO";
	putchar('\n');
	printf("%d\n", result[1]);
	return 0;
}