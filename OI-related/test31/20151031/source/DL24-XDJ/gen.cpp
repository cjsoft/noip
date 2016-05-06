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
int main(){
#ifndef LOCAL
	// freopen("sequence.out","w",stdout);
#endif
	freopen("sequence.in","w",stdout);
	int n = 100000;
	int m = 1000;
	srand(time(0));
	fprintf(stderr,"%d\n",RAND_MAX);
	printf("%d\n",n);
	f(i,0,n){
		printf("%d ",rand() % 10000 * (rand() % 10000));
	}
	puts("");
	printf("%d\n",m);
	f(i,0,m){
		if (rand() & 1){
			puts("2");
		}else {
			printf("1 %d %d\n",rand() % n + 1,rand());
		}
	}

#ifdef TI
	st = clock();
#endif

#ifdef TI
	ed = clock();
	printf("%lf\n",(ed - st) / CLOCKS_PER_SEC);
#endif

#ifndef LOCAL
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
