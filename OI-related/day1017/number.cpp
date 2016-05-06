#include <iostream>
#include <cstdio>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
#ifdef WIN32
void printLL(long long a){printf("%I64d", a);}
#else
void printLL(long long a){printf("%lld", a);}
#endif
using namespace std;
typedef long long ll;
const int MOD=1000000007;
ll global_result=0;
int n,k,s;
void dfs(int tl,int tr,int ts,int tk){
	if(ts==0){
		++global_result;
		global_result%=MOD;
	}
	if((0.5*(tr-tk+1+tr)*tk)<ts)
		return;
	for (int i = tl; i <=tr-tk+1; ++i)
	{
		if(ts-i<0)
			break;
		dfs(i+1,tr,ts-i,tk-1);
	}
}
int main(){
	open("number.in","number.out");
	scanf("%d %d %d",&n,&k,&s);
	if(int(0.5*(n+n-k+1)*k)<s+1){
		printf("0\n");
		return 0;
	}
	dfs(1,n,s,k);
	printLL(global_result);
	putchar('\n');
	return 0;
}