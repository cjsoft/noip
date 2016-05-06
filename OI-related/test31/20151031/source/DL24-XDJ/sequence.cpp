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

int n;
int m;
const int MAXN = 100033;
int a[MAXN];
int p[12];
int mx,x,y;
int tee;
int ansTI = 0;
inline void getAns(){
	++ansTI;
	f(k,2,n)f(j,1,k)f(i,0,j){
		if (a[i] + a[j] > a[k] && a[k] + a[j] > a[i] && a[i] + a[k] > a[j]){
			mx = k;
			p[1] = a[i];p[2] = a[j];p[3] = a[k];
			std::sort(p + 1,p + 4);
			printf("%d %d %d\n",p[1],p[2],p[3]);
			// printf("%d %d %d\n",p[1],p[2],p[3]);
			return;
		}
	}
	p[1] = -1;p[2] = -1;p[3] = -1;
	mx = n - 1;
}
int main(){
#ifndef LOCAL
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
#endif

#ifdef TI
	st = clock();
#endif

	scanf("%d",&n);
	f(i,0,n)scanf("%d",a + i);
	scanf("%d",&m);
	mx = -1;
	while (m--){
		scanf("%d",&tee);
		if (tee == 1){
			scanf("%d%d",&x,&y);
			--x;
			a[x] = y;
			if (x <= mx)mx = -1;
		}else {
			if (mx > -1){
				printf("%d %d %d\n",p[1],p[2],p[3]);
			}else {
				getAns();
			}
		}
	}

#ifdef TI
	ed = clock();
	fprintf(stderr,"%d %d\n",ansTI,mx);
	fprintf(stderr,"%lf\n",(ed - st) / CLOCKS_PER_SEC);
#endif

#ifndef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
