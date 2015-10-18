#include <iostream>
#include <cstdio>
const long long mOD=1000000009;
using namespace std;
typedef long long ll;

ll jiecheng[4007];
void init_jiecheng(){
	jiecheng[0]=1;
	for (int i = 1; i < 4007; ++i)
	{
		jiecheng[i]=(jiecheng[i-1]*i)%mOD;
	}
}
ll n,w,b;

void calc(int x,int y,int z){

}
int main(){
	init_jiecheng();
	cin>>n>>w>>b;
	return 0;
}