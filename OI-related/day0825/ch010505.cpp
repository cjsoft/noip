#include <iostream>
#include <cstdio>

using namespace std;
int n;
int x=0,y=0x7fffffff;
int main(){
	scanf("%d",&n);
	int temp;
	for(int i=0;i<n;++i){
		scanf("%d",&temp);
		x=max(x,temp);
		y=min(y,temp);
	}
	printf("%d\n",x-y);
	return 0;
}