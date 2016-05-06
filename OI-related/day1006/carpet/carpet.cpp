#include <iostream>
#include <cstdio>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
int n,m,k;
int main(){
	open("carpet.in","carpet.out");
	cin>>n>>m>>k;
	char temp;
	if(k==1){
		for (int i = 0; i < n; ++i)
		{
			if(i!=n-1){
				for (int j = 0; j < m-1; ++j)
				{
					cin>>temp;
					if(temp=='N'){
						cout<<"NO"<<endl;
						return 0;
					}
				}
				for (int j = 0; j < m; ++j)
				{
					if(temp=='N'){
						cout<<"NO"<<endl;
						return 0;
					}
				}
			}else{
				for (int j = 0; j < m-1; ++j)
				{
					cin>>temp;
					if(temp=='N'){
						cout<<"NO"<<endl;
						return 0;
					}
				}
			}
		}
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}