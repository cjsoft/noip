#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int prime[10007];
bool isprime[10007];
int cn[10007],un[10007];
int tot=0;

void sc(){
	memset(isprime,true,sizeof(isprime));
	for (int i = 2; i < 10007; ++i)
	{
		if(isprime[i])
			prime[tot++]=i;
		for (int j = 0; j < tot; ++j)
		{
			if(i*prime[j]>=10007)
				break;
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
}

int dn;
int tt=0;
void ksd(int dn){
	for (int i = 0; i < tot; ++i)
	{
		if(dn==1)
			break;
		if(dn%prime[i]==0){
			cn[tt]=prime[i];
			while(dn%prime[i]==0){
				dn/=prime[i];
				un[tt]++;
			}
			tt++;
		}
	}
}

int main(){
	sc();
	cin>>dn;
	memset(un,0,sizeof(un));
	memset(cn,0,sizeof(cn));
	ksd(dn);
	int total=1;
	for (int i = 0; i <tt; ++i)
	{
		total*=(un[i]+1);
		printf("%d^%d",cn[i],un[i] );
		if(i!=tt-1)
			putchar('+');
	}
	putchar('\n');
	printf("%d\n",total );
	return 0;
}