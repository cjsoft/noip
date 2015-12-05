**细心！！！**  
明明第一题那么有机会A的  
坑点也不是太坑  
好好读题就能A、  
怎么一点也不仔细呢！！、  
  
```c++
#include <iostream>
#include <cstdio>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
int arr[100007];
int n,m;
inline void print(int &a,int &b,int &c){
	if(a>= b && b>=c){
		printf("%d %d %d\n",c,b,a);
	}else if(a>=c && c>=b){
		printf("%d %d %d\n",b,c,a);
	}else if(b>=c && c>=a){
		printf("%d %d %d\n",a,c,b);
	}else if(b>=a && a>=c){
		printf("%d %d %d\n",c,a,b);
	}else if(c>=b && b>=a){
		printf("%d %d %d\n",a,b,c);
	}else if(c>=a && a>=b){
		printf("%d %d %d\n",b,a,c);
	}
}
void solve(){
	// 这个循环顺序啊，怎么就是不仔细读题呢！、
	for(int i=2;i<n;++i){
		for(int j=1;j<i;++j){
			for(int k=0;k<j;++k){
				if(arr[i]+arr[j]>arr[k] && arr[i]+arr[k]>arr[j] && arr[j]+arr[k]>arr[i]){ //多写个等式，程序不会因为你多一个判断就T掉，多一个判断反而更令人放心，更稳当
					print(arr[i],arr[j],arr[k]);
					return;
				}
			}
		}
	}
	printf("-1 -1 -1\n");
}
int main(){
	open("sequence.in","sequence.out");
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",arr+i);
	}
	scanf("%d",&m);
	int temp,t2,t;
	for(int i=0;i<m;++i){
		scanf("%d",&temp);
		if(temp==2){
			solve();
		}else{
			scanf("%d%d",&t2,&t);
			arr[t2-1]=t;
		}
	}
	return 0;
}
```
