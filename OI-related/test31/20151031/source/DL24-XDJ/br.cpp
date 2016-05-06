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
 
typedef unsigned long long LL;
typedef long double real;

#ifdef WIN32
#define LLD "%I64d"
#define LLU "%I64u"
#else
#define LLD "%lld"
#define LLU "%llu"
#endif

double st,ed;
const LL fac[] = {0,1,2,6,24,120,720};
int l,r,k,n,q;
const int MAXN = 100033;
struct node{
	int d,v;
	inline bool operator < (const node& T)const {
		return d < T.d;
	}
} a[MAXN],tee;
int ll,rr;
std::vector<int> V;
int sz;
LL sd[MAXN];//a[].d^1
LL sb[MAXN];//a[].d^2
LL sf[MAXN];//a[].d^3
int main(){
#ifndef LOCAL
	freopen("melancholy.in","r",stdin);
	freopen("melancholy.out","w",stdout);
#endif

#ifdef TI
	st = clock();
#endif

	scanf("%d%d",&n,&q);
	g(i,1,n)scanf("%d",&a[i].d);
	g(i,1,n)scanf("%d",&a[i].v);
	std::sort(a + 1,a + n + 1);tee.v = 0;
	g(i,1,n){
		sd[i] = a[i].v;
		sb[i] = (LL)a[i].v * (LL)a[i].v;
		sf[i] = ((LL)a[i].v * a[i].v) * (LL)a[i].v;
		sd[i] += sd[i - 1];
		sb[i] += sb[i - 1];
		sf[i] += sf[i - 1];
	}
	// g(i,1,n)printf("%d ",a[i].d);puts("");
	// g(i,1,n)printf("%d ",a[i].v);puts("");
	while (q--){
		scanf("%d%d%d",&l,&r,&k);
		tee.d = l;ll = std::lower_bound(a + 1,a + n + 1,tee) - a;
		// if (ll >= n)ll = n - 1;
		if (ll < 1)ll = 1;
		g(i,ll,n + 1)if (a[i].d >= l){
			ll = i;break;
		}
		tee.d = r;rr = std::lower_bound(a + 1,a + n + 1,tee) - a;
		// printf("``%d %d\n",ll,rr);
		if (rr > n)rr = n;
		// if (rr < 0)rr = 0;
		gd(i,rr,0)if (a[i].d <= r){
			rr = i;break;
		}
		// printf("``%d %d\n",ll,rr);
		if (rr < ll + k){
			puts("0");
			continue;
		}
		// V.clear();
		// g(i,ll,rr)V.push_back(a[i].v);
		LL ad = sd[rr] - sd[ll - 1],ab = sb[rr] - sb[ll - 1],af = sf[rr] - sf[ll - 1],am = a[ll].v;
		g(i,ll,rr){
			if (a[i].v < am)am = a[i].v;
		}
		// printf("%I64u\n",am);
		if (k == 1){
			printf(LLU,ad - am);
			puts("");
		}else if (k == 2){
			ad -= am;ab -= am * am;
			printf(LLU,(ad * ad) - ab);
			puts("");
		}else {
			// g(i,ll,rr)printf("%d ",a[i].v);puts("");
			// printf("%d %d\n",ll,rr);
			ad -= am;ab -= am * am;af -= (am * am) * am;
			LL res = ad * ad * ad - af;
			// printf("`%I64u %I64u`\n",ab,am);
			g(i,ll,rr)if (a[i].v != am){
				res -= 3 * (LL)a[i].v * (ab - a[i].v * a[i].v);
			}
			printf(LLU,res);
			puts("");
		}
	}

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
