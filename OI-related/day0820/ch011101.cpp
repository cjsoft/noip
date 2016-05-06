#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int arr[100007];
int pre[100007],nxt[100007];
int n;
int mm;

void find(int x);
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",arr+i);
	}
	pre[0]=0;
	for (int i = 1; i < n; ++i)
	{
		if(arr[i-1]!=arr[i]){
			pre[i]=i-1;
		}else{
			pre[i]=pre[i-1];
		}
	}
	nxt[n-1]=n-1;
	for (int i = n-2; i >=0; --i)
	{
		if(arr[i+1]!=arr[i]){
			nxt[i]=i+1;
		}else{
			nxt[i]=nxt[i+1];
		}
	}
	scanf("%d",&mm);
	int temp;
	for (int i = 0; i < mm; ++i)
	{
		scanf("%d",&temp);
		find(temp);
	}
	return 0;
}


void find(int x){
	int pp,lp,rp;
	{
		int l=0,r=n-1;
		int m=(l+r)>>1;
		while(l!=r && arr[m]!=x){
			if(arr[m]<x){
				l=m+1;
				m=(l+r)>>1;
			}else{
				r=m;
				m=(l+r)>>1;
			}
		}
		pp=m;
	}
	{
		int l=0,r=n-1;
		int m=(l+r)>>1;
		while(l!=r && arr[m]!=arr[pre[pre[pp]]]){
			if(arr[m]<arr[pre[pre[pp]]]){
				l=m+1;
				m=(l+r)>>1;
			}else{
				r=m;
				m=(l+r)>>1;
			}
		}
		lp=m;
	}
	{
		int l=0,r=n-1;
		int m=(l+r)>>1;
		while(l!=r && arr[m]!=arr[nxt[nxt[pp]]]){
			if(arr[m]<=arr[nxt[nxt[pp]]]){
				l=m+1;
				m=(l+r)>>1;
			}else{
				r=m;
				m=(l+r)>>1;
			}
		}
		rp=m;
	}

	int mmm=lp;
	for (int i = lp; i <=rp; ++i)
	{
		if(abs(arr[i]-x)<abs(arr[mmm]-x))
			mmm=i;
	}
	printf("%d\n", arr[mmm]);
}