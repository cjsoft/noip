#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct student
{
	char name[203];
	int chengji;
}arr[203];
bool cmp(student a,student b){
	if(a.chengji==b.chengji){
		if(strcmp(a.name,b.name)>=0)
			return false;
		else
			return true;
	}
	return a.chengji>b.chengji;
}
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%s %d",arr[i].name, &arr[i].chengji);
	}
	sort(arr,arr+n,cmp);
	for(int i=0;i<n;++i){
		printf("%s %d\n",arr[i].name,arr[i].chengji );
	}
	return 0;
}