#include <iostream>
#include <cstdio>
#include <string>
#include <memory.h>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
// #include <bitset>

using namespace std;
bool arr[10007];
struct ware
{
	int id;
	int ddd,pos;
	bool ava;

	ware(){
		ddd=pos=0;
		ava=false;
	}

	bool &operator()(){
		return ava;
	}
}aws[107];
int id=1,q,m;
int main(){
	open("warehouse.in","warehouse.out");
	memset(arr,false,sizeof(arr));
	ios::sync_with_stdio(false);
	cin>>q>>m;
	string temp;
	int tint;
	for (int i = 0; i < q; ++i)
	{
		cin>>temp;
		if(temp=="get"){
			cin>>tint;
			if(aws[tint]()){
				aws[tint]()=false;
				memset(arr+aws[tint].pos,false,aws[tint].ddd);
			}else{
				cout<<"cannot get."<<endl;
			}
			
		}else if(temp=="arrange"){
			memset(arr,false,sizeof(arr));
			tint=0;
			for (int j = 1; j < id; ++j)
			{
				if(aws[j]())
					tint+=aws[j].ddd;
			}
			memset(arr,true,tint);
			
		}else if(temp=="put"){
			cin>>tint;
			bool ftag=true;
			for (int j = 0; j < m-tint+1; ++j)
			{
				if(!arr[j]){
					for (int k = 0; (k < tint); ++k)
					{
						if(arr[j+k] || j+k>=m){
							ftag=true;
							j=j+k+1;
							goto DI;
						}
					}
					aws[id].ddd=tint;
					aws[id].pos=j;
					memset(arr+aws[id].pos,true,tint);
					aws[id++].ava=true;
					ftag=false;
					break;
				}
				DI:;
			}
			if(!ftag){
				cout<<(id-1)<<endl;
			}else{
				cout<<"cannot put."<<endl;
			}
		}
	}
	return 0;
}