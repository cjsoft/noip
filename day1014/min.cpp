#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
const int POI=1000007;
int a[POI];
int b[POI];
int n;

template <typename T>
T mabs(T a){
	return a<0?-a:a;
}

int main(){
	open("min.in","min.out");
	scanf("%d",&n);
	for (int i = 0; i <n; ++i)
	{
		scanf("%d",a+i);
		a[i]=mabs(a[i]);
	}
	sort(a,a+n);
	int minn=INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if(a[i]!=0)
			minn=min(minn,a[i]);
	}
	for (int i = 0; i < n-1; ++i)
	{
		if(a[i+1]%a[i]!=0)
			minn=min(mabs(a[i+1]%a[i]),minn);
		if(a[i+1]-a[i]!=0)
			minn=min(mabs(a[i+1]-a[i]),minn);
	}
	printf("%d\n",minn );
	return 0;
}