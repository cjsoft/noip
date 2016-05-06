#include <iostream>
#include <cstdio>

using namespace std;

double abs(double x){
	return x<0?-x:x;
}
double f(double x){
	return x*x*x*x*x-15.0*x*x*x*x+85.0*x*x*x-225.0*x*x+274.0*x-121.0;
}

int main(){
	double l=1.5,r=2.4;
	double m=(l+r)/2;
	while(abs(f(m))>0.000000001){
		if(f(m)>0){
			l=m;
		}else{
			r=m;
		}
		m=(l+r)/2;
	}
	printf("%.6lf\n",m);
	return 0;
}
