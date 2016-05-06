#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define x1 x11
#define y1 y11
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <set>
 
#define f(x,y,z) for(int x = (y),__ = (z);x < __;++x)
#define g(x,y,z) for(int x = (y),__ = (z);x <= __;++x)
#define gd(x,y,z) for(int x = (y),__ = (z);x >= __;--x)
#define fd(x,y,z) for(int x = (y),__ = (z);x > __;--x)
 
typedef long long LL;
typedef long double real;

double st,ed;
const int MO = 1000000007;
int dp[100033];
std::vector<int> G[100033];
int x,y;
int n,m;
int mm;
int main(){
#ifndef LOCAL
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
#endif

#ifdef TI
	st = clock();
#endif

	scanf("%d%d",&n,&m);
	mm = n + 1;
	while (m--){
		scanf("%d%d",&x,&y);
		G[y].push_back(x);
		if (y == 0 && x < mm)mm = x;
	}
	f(i,0,mm)dp[i] = 1;
	g(i,1,n){
		// memset(dp,-1,sizeof dp);
		if (i)dp[i - 1] = 0;
		f(j,0,G[i].size())dp[ G[i][j] ] = -i;
		g(j,i,n){
			if (dp[j] != -i){
				if (dp[j] < 0)dp[j] = 0;
				if (dp[j - 1] > 0)(dp[j] += dp[j - 1]) %= MO;
			}
		}
		// g(j,0,n)printf("%d ",dp[j]);puts("");
	}
	printf("%d\n",dp[n]);

#ifdef TI
	ed = clock();
	fprintf(stderr,"%lf\n",(ed - st) / CLOCKS_PER_SEC);
#endif

#ifndef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
