#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int arr[100007];
int n;
int mm;

void find(int x);
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",arr+i);
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
	if(abs(arr[m+1]-x)<abs(arr[m-1]-x))
		while(abs(arr[m]-x)>abs(arr[m+1]-x) && m+1!=n)
			++m;
	else
		while(abs(arr[m]-x)>abs(arr[m-1]-x) && m-1!=-1)
			--m;
	printf("%d\n",arr[m] );
}