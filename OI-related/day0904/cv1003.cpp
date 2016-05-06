#include <iostream>
#include <cstdio>
#include <memory.h>
#include <climits>
using namespace std;
bool v[107];
int arr[107][107];
int n;
int done=0;
int a[107],b[107];
int tot=0,total=0;
int main(){
	memset(v,false,sizeof(v));
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>arr[i][j];
		}
	}
	v[1]=true;
	int ti,tj,tl=INT_MAX;
	while(done!=n-1){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(v[i]==false && v[j]==true){
					if(arr[i][j]==0){
						v[i]=true;
						++done;
						goto DTAG;
					}else{
						if(arr[i][j]<tl){
							tl=arr[i][j];
							ti=i;tj=j;
						}
					}
				}
			}
		}
		v[ti]=true;
		if(ti>tj)
			swap(ti,tj);
		total+=arr[ti][tj];
		a[tot]=ti;
		b[tot++]=tj;
		++done;
		DTAG:
		ti=0;tj=0;tl=INT_MAX;
	}
	cout<<tot<<endl;
	for(int i=0;i<tot;++i){
		cout<<a[i]<<' '<<b[i]<<endl;
	}
	cout<<total<<endl;
	return 0;
}