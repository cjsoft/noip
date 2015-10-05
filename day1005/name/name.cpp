#include <iostream>
#include <cstdio>
#include <cstring>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;

bool asd[256];
int n;
char s[37][27];
int ls[37];
int main(){
	open("name.in","name.out");
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",s[i]);
		ls[i]=strlen(s[i]);
	}
	memset(asd,true,sizeof(asd));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < ls[i]; ++j)
		{
			asd[s[i][j]]=false;
		}
	}
	for (int i = 'a'; i <='z'; ++i)
	{
		if(asd[i]){
			printf("%c\n",char(i) );
			return 0;
		}
	}
	printf("aa\n");
	return 0;
}