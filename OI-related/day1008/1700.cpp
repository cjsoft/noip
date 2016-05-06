#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

bool mmp[8][8];
bool mk1[8],mk2[15],mk3[15];
int global_cnt=1;
void dfs(int n){
	if(n==8){
		printf("No. %d\n", global_cnt++);
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				printf("%d ",mmp[j][i] );
			}
			putchar('\n');
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		if(!mk1[i] && !mk2[i-n+8] && !mk3[n+i]){
			mmp[n][i]=true;
			mk1[i]=true;
			mk2[i-n+8]=true;
			mk3[n+i]=true;
			dfs(n+1);
			mmp[n][i]=false;
			mk1[i]=false;
			mk2[i-n+8]=false;
			mk3[n+i]=false;
		}
	}
}

int main(){
	memset(mmp,false,sizeof(mmp));
	memset(mk1,false,sizeof(mk1));
	memset(mk2,false,sizeof(mk2));
	memset(mk2,false,sizeof(mk3));
	dfs(0);
	return 0;
}