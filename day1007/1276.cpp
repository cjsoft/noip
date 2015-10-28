#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
const ll MOD=200907;

ll quickpow(ll a,ll b){
	if(b==0)
		return 1;
	ll temp=quickpow(a,b>>1)%MOD;
	if(b&1){
		return (((temp*temp)%MOD)*a)%MOD;
	}else{
		return (temp*temp)%MOD;
	}
}
ll n;
ll a,b,c,k;
int main(){
	scanf("%lld",&n);
	for (ll i = 0; i < n; ++i)
	{
		scanf("%lld %lld %lld %lld",&a,&b,&c,&k);
		if(a+c==2*b){
			cout<<(a+((k-1)*(b-a))%MOD)%MOD<<endl;
		}else{
			cout<< (a*quickpow(b/a,k-1))%MOD<<endl;
		}
	}
	return 0;
}

/*
5
17 425 833 91
33 3003 5973 2
99 3960 7821 69
40 920 21160 62
20 920 42320 87

 */