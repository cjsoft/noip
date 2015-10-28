#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int n,arr[100007],k;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",arr+i);
	}
	sort(arr,arr+n);
	scanf("%d",&k);
	for(int i=n-1;i>=n-k;--i){
		printf("%d\n",arr[i] );
	}
	return 0;
}