#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
double x,y;
int a;
double totaltime=0;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%lf %lf %d",&x,&y,&a);
		totaltime+=a*1.5;
		totaltime+=sqrt(x*x+y*y)/25.0;
	}
	printf("%d\n", (int)ceil(totaltime));
	return 0;
}