// euler is cleared on 2015/10/27 21:51

#include <iostream>
#include <cstdio>

using namespace std;

int oula(int n){
	int rtn=n;
	for(int i=2;i<=n;++i){
		if(n%i==0){
			rtn=rtn/i*(i-1);
			while(n%i==0)
				n/=i;
		}
	}
	if(n>1)
		rtn=rtn/n*(n-1);
	return rtn;
}

int main(){
	for(int i=2;i<22;++i){
		printf("%d\n", oula(i));
	}
	return 0;
}