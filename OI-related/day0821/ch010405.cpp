#include <cstdio>
long long x,y;
int main(){
	scanf("%lld %lld",&x,&y);
	if(x>y)
		printf(">\n");
	else if(x==y)
		printf("=\n");
	else
		printf("<\n");
	return 0;
}