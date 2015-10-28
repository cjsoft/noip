#include <iostream>
#include <cstdio>

using namespace std;
int a=0,b=0,c=0,n;
int main(){
	int ta,tb,tc;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d %d %d",&ta,&tb,&tc);
		a+=ta;b+=tb;c+=tc;
	}
	printf("%d %d %d %d\n",a,b,c,a+b+c );
	return 0;
}