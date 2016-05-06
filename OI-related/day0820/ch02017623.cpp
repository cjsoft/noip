#include <iostream>
#include <cstdio>

using namespace std;
int a,b,c,d,e;
int n1,n2,n3,n4,n5;
int k;
int main(){
	scanf("%d%d%d%d%d%d",&k,&n1,&n2,&n3,&n4,&n5);
	k*=100;
	for (int i = 1; i <=k; ++i)
	{
		for (a =1; a <=i/n1; ++a)
		{
			b=i-n1*a;
			c=i-n2*b;
			d=i-n3*c;
			e=i-n4*d;
			if(a*n1+b==i && b*n2+c==i && c*n3+d==i && d*n4+e==i && e*n5+a==i &&a>0&&b>0&&c>0&&d>0&&e>0){
				printf("%d %d %d %d %d %d\n",i,a,b,c,d,e );
				return 0;
			}
		}
	}
	printf("not found\n");
	return 0;
}