#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[512],b[512],c[512];
char sa[512],sb[512];
int la,lb;
int main(){
	scanf("%s\n%s",sa,sb);
	la=strlen(sa);
	lb=strlen(sb);
	for (int i = 0; i < la; ++i)
	{
		a[la-1-i]=sa[i]-'0';
	}
	for (int i = 0; i < lb; ++i)
	{
		b[lb-1-i]=sb[i]-'0';
	}
	for (int i = 0; i < la; ++i)
	{
		for (int j = 0; j < lb; ++j)
		{
			c[i+j]+=a[i]*b[j];
		}
	}
	for (int i = 0; i < 511; ++i)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	bool tag=true;
	for (int i =511; i >=0; --i)
	{
		if(c[i])
			tag=false;
		if(!tag)
			putchar(c[i]+'0');
	}
	if(tag)
		putchar('0');
	putchar('\n');
	return 0;
}