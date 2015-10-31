#include <iostream>
#include <cstdio>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)

using namespace std;
typedef unsigned long long ll;
const ll MOD=1LL<<32;
ll d[500007],v[500007];
int n,q;
int l,r;
ll tm=MOD+1;
ll global_cnt=1,global_resu=0,global_sr;
void dfs(int cnt,int ll){
	if(cnt==1){
		global_sr=global_cnt;
		for(int i=ll;i<n;++i){
			if(v[i]!=tm)
			if(d[i]>=l & d[i]<=r){
				global_cnt*=v[i];
				global_cnt%=MOD;
				global_resu+=global_cnt;
				global_resu%=MOD;
				global_cnt=global_sr;
			}
		}
		return;
	}
	unsigned long long sr;
	sr=global_cnt;
	for(int i=ll;i<n-cnt+1;++i){
		if(v[i]!=tm)
		if(d[i]>=l && d[i]<=r){
			global_cnt*=v[i];
			global_cnt%=MOD;
			dfs(cnt-1,i+1);
			global_cnt=sr;
		}
	}
}

ll jiecheng[500007];

int main(){
	open("melancholy.in","melancholy.out");
	scanf("%d%d",&n,&q);
	jiecheng[1]=1;
	for(int i=2;i<500007;++i){
		jiecheng[i]=jiecheng[i-1]*i;
		jiecheng[i]%=MOD;
	}
	for(int i=0;i<n;++i){
		scanf("%I64d",d+i);
	}
	for(int i=0;i<n;++i){
		scanf("%I64d",v+i);
	}
	int k;
	for(int i=0;i<q;++i){
		scanf("%I64d%I64d%d",&l,&r,&k);
		global_cnt=1;
		global_resu=0;
		tm=MOD+1;
		for(int j=0;j<n;++j){
			if(d[j]<=r && d[j]>=l){
				tm=min(tm,v[j]);
			}
		}
		dfs(k,0);
		printf("%I64d\n",(jiecheng[k]* global_resu)%MOD);
	}
	return 0;
}
