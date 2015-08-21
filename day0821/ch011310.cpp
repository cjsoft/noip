#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

int x,y;
int prime[100007];
bool isprime[100007];
int tot=0;
int arr[100007];
inline int lowbit(int x){
	return x&(-x);
}
int qsum(int pos){
	int rtn=0;
	while(pos>0){
		rtn+=arr[pos];
		pos-=lowbit(pos);
	}
	return rtn;
}
void add(int pos){
	while(pos<=y){
		++arr[pos];
		pos+=lowbit(pos);
	}
}
int main(){
	scanf("%d %d",&x,&y);
	if(y<x)
		swap(x,y);
	memset(isprime,true,sizeof(isprime));
	memset(arr,0,sizeof(arr));
	isprime[0]=isprime[1]=false;
	for(int i=2;i<=y;++i){
		if(isprime[i]){
			prime[tot++]=i;
			add(i);
		}
		for(int j=0;j<tot;++j){
			if(i*prime[j]>y)
				break;
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
	printf("%d\n", qsum(y)-qsum(x-1));
	return 0;
}