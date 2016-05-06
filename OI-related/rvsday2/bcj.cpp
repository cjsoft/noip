#include <iostream>
#include <cstdio>

using namespace std;

struct BCJ
{
	int fa[1007];
	BCJ(){
		for (int i = 0; i < 1007; ++i)
		{
			fa[i]=i;
		}
	}
	int getfa(int x){
		while(fa[x]!=x)
			x=fa[x];
		return x;
	}
	void setfa(int a,int b){
		fa[getfa(b)]=getfa(a);
	}
	bool check(int a,int b){
		return getfa(a)==getfa(b);
	}
}a;

int main(){
	a.setfa(1,2);
	cout<<a.check(2,1)<<' '<<a.check(1,2)<<endl;
	cout<<a.check(2,3);
	return 0;
}