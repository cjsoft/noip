#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[507];
int tot=0,n;
int main(){
	int temp;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&temp);
		if(temp&1)
			arr[tot++]=temp;
	}
	sort(arr,arr+tot);
	for(int i=0;i<tot;++i){
		printf("%d",arr[i] );
		if(i!=tot-1)
			putchar(',');
	}
	putchar('\n');
	return 0;
}