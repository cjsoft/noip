#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(int(log10(n))==1)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}