#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll fib[10007];


int main(){
	fib[1]=fib[2]=1;
	for(int i=3;i<=10006;++i){
		fib[i]=fib[i-1]+fib[i-2];
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int a;
		scanf("%d",&a);
		cout<<fib[a]<<endl;
	}
	return 0;
}
