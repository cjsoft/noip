#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>

typedef long long ll;
const ll MOD = 1000000007;

using namespace std;

ll dp[200007];


int n;
vector <int> mp[200007];

void dfs(int root,int from){
	dp[root]=1;
	for (vector<int>::iterator i = mp[root].begin(); i != mp[root].end(); ++i)
	{
		if(*i!=from)
			dfs(*i,root);
	}
	for (vector<int>::iterator i = mp[root].begin(); i != mp[root].end(); ++i)
	{
		if(*i!=from){
			dp[root]*=dp[*i]+1;
			dp[root]%=MOD;
		}
	}
	dp[root]%=MOD;
}

int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	int temp;
	for (int i = 2; i <=n; ++i){
		cin>>temp;
		mp[i].push_back(temp);
		mp[temp].push_back(i);
	}
	for (int i = 1; i <=n; ++i)
	{
		memset(dp,0,sizeof(dp));
		dfs(i,0);
		cout<<dp[i];
		if(i!=n)
			cout<<' ';
	}
	cout<<endl;
	return 0;
}