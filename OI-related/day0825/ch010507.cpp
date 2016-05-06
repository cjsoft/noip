#include <iostream>
#include <cstdio>

using namespace std;
int m,n,sum=0;
int main(){
	scanf("%d %d",&m,&n);
	if(!(m&1))
		++m;
	for(int i=m;i<=n;i+=2){
		sum+=i;
	}
	printf("%d\n", sum);
	return 0;
}