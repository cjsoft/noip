#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char sa[257];
int a[257],c[257];
int b=13,la;
int main(){
	scanf("%s",sa);
	la=strlen(sa);
	for(int i=0;i<la;++i){
		a[la-1-i]=sa[i]-'0';
	}
	int mod=0;
	for(int i=la-1;i>=0;--i){
		mod*=10;
		mod+=a[i];
		c[i]=mod/b;
		mod%=b;
	}
	bool tag=true;
	for(int i=256;i>=0;--i){
		if(c[i])
			tag=false;
		if(!tag)
			putchar(c[i]+'0');
	}
	if(tag)
		putchar('0');
	putchar('\n');
	printf("%d\n", mod);
	return 0;
}