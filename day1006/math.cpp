#ifndef WIN_32
#define LLO "%I64d"
#else
#define LLO "%lld"
#endif
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstring>

#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
typedef unsigned long long ll;
const ll MOD=95542721LL;
ll raw[100007];
ll arr[100007];
char temp[7];
int n,m;

ll quickpow(ll a,ll b){
	if(!b)return 1LL;
	ll temp=quickpow(a,b>>1)%MOD;
	return (b&1)?(temp*temp*a)%MOD:(temp*temp)%MOD;
}

int main(){
	open("math.in","math.out");
	scanf("%d%d",&n,&m);
	int tl,tr;
	for (int i = 1; i <=n; ++i)
	{
		scanf(LLO,raw+i);
		arr[i]=1;
	}
	for (int i = 0; i < m; ++i)
	{
		memset(temp,0,7);
		scanf("%s",temp);
		if(!strcmp("query",temp)){
			ll tll=0;
			scanf("%d%d",&tl,&tr);
			if(tl>tr)swap(tl,tr);
			for (int j = tl; j <=tr; ++j)
			{
				tll+=quickpow(raw[j],arr[j]);
				tll%=MOD;
			}
			printf(LLO,tll);
			putchar('\n');
		}else if(!strcmp("change",temp)){
			scanf("%d%d",&tl,&tr);
			if(tl>tr)swap(tl,tr);
			for (int j = tl; j <=tr; ++j)
			{
				arr[j]*=3;
			}
		}
	}
	return 0;
}