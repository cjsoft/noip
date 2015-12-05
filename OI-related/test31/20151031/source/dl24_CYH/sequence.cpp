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
	for(int i=0;i<n-2;++i){
		for(int j=i+1;j<n-1;++j){
			for(int k=j+1;k<n;++k){
				if(arr[i]+arr[j]>arr[k] && arr[j]+arr[k]>arr[i]){
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
