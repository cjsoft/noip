// 这道题其实可以打表（错位数） （雾）
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
ll jiecheng[21];
ll qes[21];
ll C(int a,int b){
	printf("%d %d\n",a,b);
	// return 1;
	return jiecheng[a]/jiecheng[b]/jiecheng[a-b];
}

int main(){
	printf("safa");
	jiecheng[1]=1;
	for (int i=2;i<21;i++){
		jiecheng[i]=jiecheng[i-1]*i;
	}
	qes[1]=0;
	qes[2]=1;
	for(int i=3;i<21;++i){
		qes[i]=jiecheng[i]-1;
		for(int j=1;j<=i-1;++j){
			qes[i]-=C(i,j)*qes[i-j];

		}
	}
	for(int i=0;i<21;++i)
		printf("%d %lld\n",i,qes[i]);
	return 0;
}

