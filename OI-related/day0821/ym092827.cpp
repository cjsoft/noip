#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef long long ll;

struct dna
{
	char sarr[507];
	ll nxd;
	dna(){
		memset(sarr,0,sizeof(sarr));
		nxd=0;
	}
	bool operator<(const dna &b)const{
		return nxd<=b.nxd;
	}
}arr[107],brr[107];

bool cop(char a,char b){
	return a<=b;
}

template<typename T>
ll gbsort(T arr[],int l,int r,bool (*cmp)(T,T)){
	if(l==r)
		return 0;
	int m=(l+r)>>1;
	ll a=gbsort<T>(arr,l,m,cop);
	ll b=gbsort<T>(arr,m+1,r,cop);
	T *ar=new T[r-l+1];
	memset(ar,0,sizeof(T));
	for (int i = l; i <=r; ++i)
	{
		ar[i-l]=arr[i];
	}
	int lp=l,rp=m+1,ap=0;
	ll nxd=0;
	while(ap!=r-l+1){
		if(lp!=m+1 && rp!=r+1){
			if(cmp(ar[lp-l],ar[rp-l])){
				nxd+=rp-m-1;
				arr[ap+l]=ar[lp-l];
				++lp;
				++ap;
			}else{
				arr[ap+l]=ar[rp-l];
				++rp;
				++ap;
			}
		}else{
			if(lp==m+1){
				arr[ap+l]=ar[rp-l];
				++rp;
				++ap;
			}else{
				nxd+=r-m;
				arr[ap+l]=ar[lp-l];
				++lp;
				++ap;
			}
		}
	}
	delete[] ar;
	return a+b+nxd;
}
int m,n;
int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;++i){
		scanf("%s",arr[i].sarr);
		strcpy(brr[i].sarr,arr[i].sarr);
		for(int j=0;j<m-1;++j){
			for(int k=j+1;k<m;++k){
				if(arr[i].sarr[j]>arr[i].sarr[k])
					++brr[i].nxd;
			}
		}
	}
	sort(brr,brr+n);
	for(int i=0;i<n;++i){
		printf("%s\n", brr[i].sarr);
	}
	return 0;
}