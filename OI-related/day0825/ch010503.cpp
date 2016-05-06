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
		x+=temp;
	}
	printf("%d %.5lf\n",x,x/double(n) );
	return 0;
}