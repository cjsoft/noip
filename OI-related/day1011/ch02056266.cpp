#include <iostream>
#include <cstdio>
#include <memory.h>
#define self (*this)
using namespace std;
typedef long long ll;
int a,b;
int main(){
	cin>>a>>b;
	while(a && b){
		dfs(a,b);
		cin>>a>>b;
	}
	return 0;
}