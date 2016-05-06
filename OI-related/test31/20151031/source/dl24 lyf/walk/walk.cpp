#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif
#define maxn 5001
#define maxm 100001

typedef unsigned int longint;
typedef long long ll;
bool map[maxn][maxn];
longint dp[maxn][maxn];
const ll p = 1000000007;
int n,c;
int x,y;

ll h[maxm]={1};


int sm[10001];
int sa[10001];
int flag[100001];
int pri[100001],pl=0;

void Eula(int n)
{
	memset(flag,0,sizeof(flag));
	flag[1]=flag[0]=1;
	for (int i=2;i<n;++i)
	{
		if (flag[i]==0) pri[pl++]=i;
		for (int j=0;j<pl&&i*pri[j]<n;++j)
		{
			flag[i*pri[j]]=1;
			if (i&pri[j]==0) break;
		}
	}
}

int extgcd(int a,int b,int &x,int &y){
	if (b==0){
		x=1;y=0;
		return a;
	}
	int r =extgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return r;
}

ll catalan(int n){
	Eula(n);
	ll sum=1,res=1;
	ll pi=0;
	ll tm = pi;
	for (int i=0;pri[i]*pri[i]<=tm;++i){
		if (tm%pri[i]==0){
			sm[pi++]=pri[i];
			while (tm%pri[i]==0) tm/=pri[i];
		}
	}
	if (tm>1) sm[pi++]=tm;
	memset(sa,0,sizeof(sa));
	for (int i=2;i<=n;++i){
		int t;
		t=4*i-2;
		for (int j=0;j<pi;++j){
			while (t%sm[j]==0){
				sa[j]--;
				t/=sm[j];
			}
		}
		res=res*t%p;
		t=i+1;
		for (int j=0;i<pi;++j){
			while (t%sm[j==0]){
				sa[j--];
				t/=sm[j];
			}
		}
		if (t>1){
			int x,y;
			int r=extgcd(t,p,x,y);
			x=(x%p+p)%p;
			res=res*x%p;
		}
		ll tmp=res;
		for (int j=0;j<pi;++j){
			for (int k=0;k<sa[j];++k){
				tmp=tmp*sm[j]%p;
			}
		}
		sum=(sum+tmp)%p;
	}
	return res;
}

int main(){	
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	memset(map,true,sizeof(map));
	scanf("%d%d",&n,&c);
	if (c==0){
		printf(lld"\n",catalan(n));
		goto end;
	}
	for (int i=1;i<=c;++i){
		scanf("%d%d",&x,&y);
		map[x][y]= false;
	}
	dp[0][0]=1;
	for (int i=0;i<=n;++i)
		for (int j=0;j<=i;++j){
			if (!map[i][j]) continue;
			if (i>=1) dp[i][j] += dp[i-1][j];
			if (j>=1) dp[i][j] += dp[i][j-1];
			dp[i][j]%=p;
		}
	printf("%u\n",dp[n][n]);
	end:;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

