#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[256],b[256],c[256];
char sa[256],sb[256];
int la,lb;

bool cmp(){
	if(la>lb)
		return true;
	if(la<lb)
		return false;
	for (int i = 0; i < la; ++i)
	{
		if(a[i]!=b[i])
			return a[i]>b[i];
	}
	return true;
}
int main(){
	scanf("%s\n%s",sa,sb);
	la=strlen(sa);lb=strlen(sb);
	for (int i = 0; i < la; ++i)
	{
		a[la-1-i]=sa[i]-'0';
	}
	for (int i = 0; i < lb; ++i)
	{
		b[lb-1-i]=sb[i]-'0';
	}
	bool tag=cmp();
	int *z,*x;
	if(tag){
		z=a;x=b;
	}else{
		z=b;x=a;
	}
	for(int i=0;i<max(la,lb);++i){
		c[i]=z[i]-x[i];
		while(c[i]<0){
			--z[i+1];
			c[i]+=10;
		}
	}
	if(!tag)
		putchar('-');
	bool ttt=true;
	for(int i=255;i>=0;--i){
		if(c[i])
			ttt=false;
		if(!ttt)
			putchar(c[i]+'0');
	}
	if(ttt)
		putchar('0');
	putchar('\n');
	return 0;
}


