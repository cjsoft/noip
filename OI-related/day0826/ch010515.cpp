#include <iostream>
#include <cstdio>

using namespace std;
int n;
int a[27],b[27];
int main(){
	scanf("%d\n%d %d",&n,a,b);
	float x=*b,y;
	x/=*a;
	for(int i=1;i<n;++i){
		scanf("%d %d",a+i,b+i);
		y=b[i];
		y/=a[i];
		if(y-x>0.05)
			printf("better\n");
		else if(x-y>0.05)
			printf("worse\n");
		else
			printf("same\n");
	}
	return 0;
}