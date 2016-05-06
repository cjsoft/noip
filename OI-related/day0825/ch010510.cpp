#include <iostream>
#include <cstdio>

using namespace std;
int k,a=0,b;
int main(){
	scanf("%d %d\n",&k,&b);
	int t;
	for(int i=0;i<k;++i){
		scanf("%d",&t);
		if(t==b)
			++a;
	}
	printf("%d\n", a);
	return 0;
}