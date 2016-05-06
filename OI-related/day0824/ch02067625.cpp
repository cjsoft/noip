#include "iostream"
#include "cstdio"
#include "climits"
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int a[200];
int b[200];
int c[200];
void ref(int n){
	for (int i = 0; i <=n; ++i)
	{
		b[i]=c[i];
	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			scanf("%d",&a[j]);
		}
		for (int j = 1; j <= i; ++j)
		{
			c[j]=max(b[j]+a[j],b[j-1]+a[j]);
		}
		ref(i);
	}
	cout.sync_with_stdio();
	
	int m=INT_MIN;
	for (int i =1; i <=n; ++i)
	{
		m=max(m,b[i]);
	}
	cout<<m;
	return 0;
}