#include <iostream>
#include <cstdio>

using namespace std;
float a,b,c,d;
float abs(float x){
	return (x>=0)?x:-x;
}
bool equal(float a,float b){
	if(abs(a-b)<=0.001)
		return true;
	return false;
}
inline float calc(float x){
	return a*x*x*x+b*x*x+c*x+d;
}
float solve(float l,float r){
	float m=(l+r)/2;
	while(!equal(calc(m),0.0)){
		if(calc(m)*calc(l)<0)
			r=m;
		else
			l=m;
		m=(l+r)/2;
	}
	return m;
}
int main(){
	scanf("%f %f %f %f",&a,&b,&c,&d);
	int cnt=0;
	for(int i=-100;i<102;++i){
		if(calc(float(i)-0.01)*calc(float(i+1)-0.01)<0){
			printf("%.2f",solve(float(i)-0.01,float(i+1)-0.01));
			if(++cnt!=3)
				putchar(' ');
		}
	}
	putchar('\n');
	return 0;
}