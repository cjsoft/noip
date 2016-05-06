#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int poww(int x,int y){
	if(y==1)
		return x;
	int temp=poww(x,y>>1);
	if(y%2){
		return (temp*temp*x);
	}else{
		return (temp*temp);
	}
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<poww(a,b)<<endl;
	return 0;
}