#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct line
{
	int l,r;
	bool operator<(const line &b)const{
		if(l==b.l)
			return r<b.r;
		return l<b.l;
	}
}larr[50007];
int n;
bool merge(int l,int r){
	for(int i=l;i<=r;++i){
		if(larr[i].l<=larr[0].r)
			larr[0].r=max(larr[0].r,larr[i].r);
		else
			return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d %d",&larr[i].l,&larr[i].r);
	}
	sort(larr,larr+n);
	bool tag=merge(0,n-1);
	if(!tag)
		printf("no\n");
	else
		printf("%d %d\n",larr[0].l,larr[0].r);
	return 0;
}