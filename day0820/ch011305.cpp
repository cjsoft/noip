#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <memory.h>
using namespace std;

int prime[1000007];
bool isprime[10000007];
int tot=0;
int n,cnt=0;
string tostring(int x){
	stringstream temp;
	temp<<x;
	return temp.str();
}
bool check(int x){
	string z=tostring(x);
	for (int i = 0; i < (z.length()>>1); ++i)
	{
		if(z.substr(i,1)!=z.substr(z.length()-1-i))
			return false;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	for (int i = 2; i <=n; ++i)
	{
		if(isprime[i]){
			prime[tot++]=i;
		}
		for (int j = 0; j < tot; ++j)
		{
			if(i*prime[j]>n)
				break;
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
	for (int i = 11; i <=n; ++i)
	{
		if(isprime[i])
			if(check(i))
				++cnt;
	}
	printf("%d\n", cnt);
	return 0;
}