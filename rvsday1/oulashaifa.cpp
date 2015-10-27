// oulashaifa is cleared on 2015/10/27 21:59

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int tot=0;
bool isprime[10000];
int prime[10000];

void shengchengsushubiao(){
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	for(int i=2;i<10000;++i){
		if(isprime[i]){
			prime[tot++]=i;
		}
		for(int j=0;j<tot;++j){
			if(prime[j]*i>=10000)
				break;
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
}

int main(){
	shengchengsushubiao();
	printf("%d\n",tot );
	// for(int i=0;i<tot;++i){
	// 	printf("%d ",prime[i] );
	// }
	return 0;
}