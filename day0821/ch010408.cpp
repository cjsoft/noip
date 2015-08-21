#include <iostream>
#include <cstdio>

using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n%5==0 && n%3==0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}