#include <cstdio>
#include <iostream>
#include <memory.h>
#include <climits>
#include <algorithm>
#define MATSIZE 2
using namespace std;
typedef long long ll;
ll p,q,a1,a2,n,mm;
struct matrix
{
	ll m[MATSIZE][MATSIZE];
	int rn,cn;
	matrix(){
		memset(m,0,sizeof(m));
	}
	matrix(int m_,int n_){
		memset(m,0,sizeof(m));
		rn=m_;
		cn=n_;
	}
	matrix operator*(matrix b){
		matrix rtn(rn,b.cn);
		if(cn!=b.rn){
			printf("Error.\n");
			return rtn;
		}
		for (int i = 0; i < rtn.rn; ++i)
		{
			for (int j = 0; j < rtn.cn; ++j)
			{
				for (int k = 0; k < cn; ++k)
				{
					rtn.m[i][j]+=(m[i][k]*b.m[k][j])%mm;
				}
				rtn.m[i][j]%=mm;
			}
		}
		return rtn;
	}
	matrix operator+(matrix b){
		matrix rtn(rn,cn);
		if(cn!=b.cn || rn!=b.rn){
			printf("Error.\n");
			return rtn;
		}
		for (int i = 0; i < rtn.rn; ++i)
		{
			for (int j = 0; j < rtn.cn; ++j)
			{
				rtn.m[i][j]=m[i][j]+b.m[i][j];
			}
		}
		return rtn;
	}
	void print(){
		for (int i = 0; i < rn; ++i)
		{
			for (int j = 0; j < cn; ++j)
			{
				printf("%d",m[i][j]);
				if(j!=cn-1)
					printf(" ");
			}
			printf("\n");
		}
	}
};
template <class T>
T qpow(T a,ll b){
	if(b==1)
		return a;
	T temp(qpow(a,b>>1));
	if(b%2)
		return temp*temp*a;
	else
		return temp*temp;
}
int main(){
	mm=100000000007;
	ll nn;
	while(!cin.fail()){
		cin>>n;
		if(cin.fail())
			break;
		matrix res(2,1);
		res.m[0][0]=1;
		res.m[1][0]=0;
		matrix hhh(2,2);
		hhh.m[0][0]=1;
		hhh.m[0][1]=1;
		hhh.m[1][0]=1;
		matrix result(qpow(hhh,n));
		matrix final(result*res);
		cout<<final.m[1][0]<<endl;
	}
	return 0;
}