#include <iostream>
#include <cstdio>

using namespace std;
int k,a=0,b=0,c=0;
int main(){
	scanf("%d\n",&k);
	int t;
	for(int i=0;i<k;++i){
		scanf("%d",&t);
		if(t==1)
			++a;
		else if(t==5)
			++b;
		else if(t==10)
			++c;
	}
	printf("%d\n%d\n%d\n", a,b,c);
	return 0;
}