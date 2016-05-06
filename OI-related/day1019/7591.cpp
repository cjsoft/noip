#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x7fffffff
#define ll long long 
using namespace std;
int ans=1,num=1;
ll m,n;
int p[15]={1,2,3,5,7,11,13,17,19,23,29,31};
ll temp[2000007];
int tot=1;
void dfs(int k,ll now,int cnt,int last)
{
	if(k==12)
	{
	if(now>= m && now <=n){
		if(temp[tot-1]!=now)
			temp[tot++]=now;
	}
		if(now>ans&&cnt>num){ans=now;num=cnt;}
		if(now<=ans&&cnt>=num){ans=now;num=cnt;}
		return;
	}
	int t=1;
	for(int i=0;i<=last;i++)
	{
		dfs(k+1,now*t,cnt*(i+1),i);
		t*=p[k];
		if(now*t>n)break;
	}
}
int main()
{
	cin>>m>>n;
	dfs(1,1,1,20);
	sort(temp+1,temp+tot);
	for (int i =1; i <tot; ++i)
	{
		cout<<temp[i];
		if(i!=tot-1)
			putchar(',');
	}
	putchar('\n');
	return 0;
}