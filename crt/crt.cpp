#include <iostream>
#include <cstdio>

using namespace std;

int p,e,i,d;
int M=21252;
int mp=28*33,me=23*33,mi=23*28;
int tp,te,ti;
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	int temp=exgcd(b,a%b,x,y);
	int tx=x,ty=y;
	x=ty;
	y=tx-a/b*ty;
	return temp;
}

int mod_reverse(int a,int p){
	int x,y;
	exgcd(a,p,x,y);
	return (x%p+p)%p;
}

int main(){
	int cnt=1;
	int ap,ae,ai;
	do{
		int d;
		cin>>ap>>ae>>ai>>d;
		if(ap==-1)break;
		tp=mod_reverse(mp,23);
		te=mod_reverse(me,28);
		ti=mod_reverse(mi,33);
		int asd=1;
		asd=ap*tp*mp+ae*te*me+ai*ti*mi;
		int res=asd%M-d;
		if(res<=0)res+=M;
		printf("Case %d: the next triple peak occurs in %d days.\n",cnt++,res);
	}while(ap!=-1);
	return 0;
}
