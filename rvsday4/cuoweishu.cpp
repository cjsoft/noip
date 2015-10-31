#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
ll jiecheng[57];
ll qes[57];
ll C(int a,int b){
	return jiecheng[a]/jiecheng[b]/jiecheng[a-b];
}

int main(){
	printf("safa");
	jiecheng[1]=1;
	for (int i=2;i<57;i++){
		jiecheng[i]=jiecheng[i-1]*i;
	}
	qes[1]=0;
	qes[2]=1;
	for(int i=3;i<57;++i){
		qes[i]=jiecheng[i]-1;
		for(int j=1;j<=i-1;++i){
			qes[i]-=C(i,j)*qes[i-j];

		}
	}
//	for(int i=0;i<57;++i)
//		printf("%d %lld",i,qes[i]);
	return 0;
}

