#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;
int prime[10007];
bool isprime[10007];
int ptr[10007];
int tot=0;
void generateprime(){
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	for(int i=2;i<10007;++i){
		if(isprime[i]){
			prime[tot++]=i;
			ptr[i]=tot-1;
		}else
			ptr[i]=ptr[i-1];
		for(int j=0;j<tot;++j){
			if(i*prime[j]>=10007)
				break;
			isprime[prime[j]*i]=false;
			if(i%prime[j]==0)
				break;
		}
	}
}
int m,n;
int main(){
	generateprime();
	scanf("%d %d",&m,&n);
	if(m>n)
		swap(m,n);
	for(int i=m;i<=n;++i){
		for(int j=ptr[i];j>=0;--j){
			if(i%prime[j]==0){
				printf("%d",prime[j] );
				if(i!=n)
					putchar(',');
				break;
			}
		}
	}
	putchar('\n');
	return 0;
}