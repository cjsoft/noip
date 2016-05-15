#include <iostream>
#include <cstdio>

using namespace std;
int n;
int x=0;
int main(){
	scanf("%d",&n);
	int temp;
	for(int i=0;i<n;++i){
		scanf("%d",&temp);
		x=max(x,temp);
	}
	printf("%d\n",x);
	return 0;
}