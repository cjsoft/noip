#include <iostream>
#include <cstdio>
#define self (*this)
using namespace std;
struct PR
{
	int lp,rp;

	bool operator<(const PR &b)const{
		return self.lp<self.rp;
	}
}citys[50007];
int n;
int main(){
	scanf("%d",&n);
	for (int i = 1; i <=n; ++i)
	{
		scanf("%d %d",&citys[i].lp,&citys[i].rp);
	}
	sort(citys+1,citys+1+n);
	for (int i = 1; i <=n; ++i)
	{
		
	}
	return 0;
}