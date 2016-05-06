#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	if(a>=10 || b>=20)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}