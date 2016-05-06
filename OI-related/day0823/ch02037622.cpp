#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
typedef long long ll;

bool cop(int a,int b){
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
int a[1000000];
int n;
int main(){
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<gbsort(a,0,n-1,cop)<<endl;
	return 0;
}