// exgcd is cleared on 2015/10/27 22:11

#include <iostream>
#include <cstdio>

using namespace std;

int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int temp=exgcd(b,a%b,x,y);
	int tx=x;
	x=y;
	y=tx-a/b*y;
	return temp;
}

int main(){
	int x,y;
	int t=exgcd(514,4686,x,y);
	printf("%d %d %d\n", t,x,y);
	return 0;
}