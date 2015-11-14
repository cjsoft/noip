#include <iostream>
#include <cstdio>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
typedef long long ll;
typedef unsigned int uint;

uint gbsort(int l,int r,int arr[]){
	if(l>=r)return 0;
	int m=(l+r)>>1;
	uint tll=gbsort(l,m,arr),trr=gbsort(m+1,r,arr);
	int *ta=new int[r-l+1];
	memcpy(ta,arr+l,4*(r-l+1));
	uint nxd=0;
	int tl=l,tr=m+1,cursor=l;
	while(tl<=m && tr<=r){
		if(ta[tl-l]>ta[tr-l]){
			arr[cursor++]=ta[tr++-l];
		}else{
			nxd+=tr-m-1;
			arr[cursor++]=ta[tl++-l];
		}
	}
	if(tr>r){
		while(cursor<=r){
			nxd+=tr-m-1;
			arr[cursor++]=ta[tl++-l];
		}
	}else{
		while(cursor<=r){
			arr[cursor++]=ta[tr++-l];;
		}
	}
	delete[] ta;
	return (nxd+tll+trr)%2;
}
int main(){
	
	return 0;
}
