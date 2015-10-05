#include <iostream>
#include <memory.h>
#include <cstdio>
#include <algorithm>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
#define self (*this)
using namespace std;


int n,m;
struct ROW
{
	int id;
	int data[1007];
	ROW(){
		memset(data,0,sizeof(data));
	}

	int &operator[](int n){
		return self.data[n];
	}

	bool operator<(const ROW &b)const{
		for(int i=1;i<=n;++i){
			if(self.data[i]!=-1 && b.data[i]!=-1)
			if(self.data[i]>b.data[i])
				return false;
		}
		return true;
	}

}arr[1007];

bool check(){
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 1; j <m; ++j)
		{
			if(arr[j][i]==-1 || arr[j+1][i]==-1)
				continue;
			if(arr[j][i]>arr[j+1][i])
				return false;
		}
	}
	return true;
}

int main(){
	open("table.in","table.out");
	scanf("%d%d",&n,&m);
	for (int i = 1; i <=n; ++i)
	{
		arr[i].id=i;
		for (int j = 1; j <=m; ++j)
		{
			scanf("%d",&arr[j][i]);
		}
	}
	sort(arr+1,arr+m+1);
	if(!check())
		printf("-1\n");
	else{
		for (int i = 1; i <=m; ++i)
		{
			printf("%d",arr[i].id );
			if(i!=m)
				putchar(' ');
		}
	}
	return 0;
}