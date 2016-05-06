#include <iostream>
#include <cstdio>

using namespace std;
int a,b,c;
int main(){
	scanf("%d %d %d",&a,&b,&c);
	if(a+b > c && a+c>b && b+c>a)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}