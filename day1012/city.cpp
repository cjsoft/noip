#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
typedef long long ll;
const ll MOD = 1000000007;

using namespace std;

ll dp[200007];
ll jiecheng[200007];

int n;
vector <int> mp[200007];

void init_jiecheng(){
	jiecheng[0]=1;
	for (int i = 1; i < 200007; ++i){
		jiecheng[i]=jiecheng[i-1]*i;
		jiecheng[i]%=MOD;
	}
}


ll select_C(int a,int in_b){
	return (jiecheng[in_b]/jiecheng[a]/jiecheng[in_b-a]);
}



int main(){
	ios::sync_with_stdio(false);
	init_jiecheng();
	cin>>n;
	int temp;
	for (int i = 2; i <=n; ++i){
		cin>>temp;
		mp[i].push_back(temp);
		mp[temp].push_back(i);
	}

	return 0;
}