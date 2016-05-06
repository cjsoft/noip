#include <cstdio>

float abs(double a){
	return (a>=0)?a:-a;
}
double a;
int main(){
	scanf("%lf",&a);
	printf("%.2lf\n", abs(a));
	return 0;
}