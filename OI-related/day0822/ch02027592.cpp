#include <iostream>
#include <cstdio>

using namespace std;
int gcd(int a,int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int a,b;
int main(){
	scanf("%d %d",&a,&b);
	printf("%d\n", gcd(a,b));
	return 0;
}