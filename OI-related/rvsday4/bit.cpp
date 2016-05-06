#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

const int MXN=100007;
ll tree[MXN];

int lowbit(int x){
	return x&(-x);
}

ll sum(int end){
	ll rtn=0;
	while(end>0){
		rtn+=tree[end];
		end-=lowbit(end);
	}
	return rtn;
}

void add(int end,ll adddata){
	while(end<MXN){
		tree[end]+=adddata;
		end+=lowbit(end);
	}
}


int main(){
	int n;
	cin>>n;
	int b;
	for(int i=1;i<=n;++i){
		cin>>b;
		add(i,b);
	}
	int m;
	cin>>m;
	int a,c;
	for (int i=0;i<m;++i){
		cin>>a;
		if(a==1){
			cin>>b>>c;
			add(b,c);
		}else{
			cin>>b>>c;
			cout<<sum(c)-sum(b-1)<<endl;
		}
	}
	return 0;
}

