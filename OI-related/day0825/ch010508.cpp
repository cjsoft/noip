#include <iostream>
#include <cstdio>

using namespace std;
int m,n,sum=0;
int main(){
	scanf("%d %d",&m,&n);
	if(!(m%17))
		--m;
	for(int i=m/17*17+17;i<=n;i+=17){
		sum+=i;
	}
	printf("%d\n",sum );
	return 0;
}