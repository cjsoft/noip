#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;
struct student
{
	int id;
	float rank;
	bool operator<(const student &b)const{
		return rank>b.rank;
	}
}arr[107];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%d %f",&arr[i].id,&arr[i].rank);
	}
	sort(arr,arr+n);
	printf("%d %g\n",arr[k-1].id,arr[k-1].rank);
	return 0;
}