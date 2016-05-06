#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct num
{
	int pos,data;
	bool operator<(const num &b)const{
		return data<b.data;
	}
}a[200007];
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i].data);
		a[i].pos=i;
	}
	sort(a,a+n);
	int last=a[0].data;
	int cnt=0;
	for(int i=0;i<n;++i){
		if(a[i].data==last)
			++cnt;
		else{
			printf("%d %d\n", last,cnt);
			last=a[i].data;
			cnt=1;
		}
	}
	printf("%d %d\n", last,cnt);
	return 0;
}