#include <cstdio>

int euler(int x){
	int cnt=x;
	for (int i = 2; i <=x; ++i)
	{
		if(x%i==0){
			cnt-=cnt/i;
			while(x%i==0)
				x/=i;
		}
	}
	return cnt;
}
int cn,n;
int main(){
	scanf("%d",&cn);
	for (int i = 0; i < cn; ++i)
	{
		scanf("%d",&n);
		printf("%d\n", euler(n));
	}
	return 0;
}