#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define maxn 100001

int N;
int a[maxn];
int M;
int order;
int x,y;
int a1,a2,a3;

int trimax(int a,int b,int c){
	a=std::max(a,b);
	a=std::max(a,c);
	return a;
}

int trimin(int a,int b,int c){
	a=std::min(a,b);
	a=std::min(a,c);
	return a;
}

bool istri(int a,int b,int c){
	if (a>=b+c) return false;
	if (b>=a+c) return false;
	if (c>=b+a) return false;
	return true;
}

void solve(){
	a1=a2=a3=-1;
	for (int k=3;k<=N;++k)
		for (int j=2;j<k;++j)
			for(int i=1;i<j;++i)
				if (istri(a[i],a[j],a[k])){
					a1 = trimin(a[i],a[j],a[k]);
					a3 = trimax(a[i],a[j],a[k]);
					a2 = a[i]+a[j]+a[k]-a1-a3;
					return;
				}
}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;++i) scanf("%d",&a[i]);
	scanf("%d",&M);
	for (int i=1;i<=M;++i){
		scanf("%d",&order);
		if (order & 1){
			scanf("%d%d",&x,&y);
			a[x]=y;
		}else{
			solve();
			printf("%d %d %d\n",a1,a2,a3);
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}