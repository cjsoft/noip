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
	if(l==r)
		return true;
	int m=(l+r)>>1;
	bool tag=merge(l,m)&&merge(m+1,r);
	if(!tag){
		if(larr[l].r>=larr[m+1].r){
			return true;
		}else{
			return false;
		}
	}
	if(larr[l].r>=larr[m+1].l){
		larr[l].r=max(larr[l].r,larr[m+1].r);
		return true;
	}else{
		return false;
	}
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