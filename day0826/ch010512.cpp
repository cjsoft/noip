#include <iostream>
#include <cstdio>

using namespace std;
int x,n;
int main(){
	scanf("%d %d",&x,&n);
	double temp=x;
	for(int i=0;i<n;++i){
		temp*=1.001;
	}
	printf("%.4f\n", temp);
	return 0;
}