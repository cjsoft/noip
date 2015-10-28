#include <cstdio>
int n;
int main(){
	scanf("%d",&n);
	if(n>0)
		printf("positive\n");
	else if(n==0)
		printf("zero\n");
	else
		printf("negative\n");
	return 0;
}