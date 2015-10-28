#include <iostream>
#include <cstdio>

using namespace std;
int n;
float x=0;
int main(){
	scanf("%d",&n);
	float temp;
	for(int i=0;i<n;++i){
		scanf("%f",&temp);
		x+=temp;
	}
	printf("%.4f\n",x/n );
	return 0;
}