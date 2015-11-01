#include <iostream>
#include <cstdio>
#include <cstring>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
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
int n,m;
int a[100007],b[100007];
int main(){
	open("lyk.in","lyk.out");
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
	}
	memcpy(b,a,sizeof(a));
	uint tempx=gbsort(0,n-1,b);
	scanf("%d",&m);
	int x,y;
	for(int i=0;i<m;++i){
		scanf("%d%d",&x,&y);
		for(int j=x+1;j<y;++j){
			tempx+=10;
			if(a[j]<a[y-1])++tempx;
			if(a[j]>a[y-1])--tempx;
			if(a[x-1]<a[j])++tempx;
			if(a[x-1]>a[j])--tempx;
			tempx%=2;
		}
		tempx+=4;
		if(a[x-1]<a[y-1])++tempx;
		else --tempx;
		tempx%=2;
		printf("%u\n",tempx);
	}
	return 0;
}
