#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
ull mp[13][13];
char s[37];
int k;
ull arr[13];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	for(int i=0;i<13;++i){
		for(int j=0;j<13;++j){
			mp[i][j]=INT_MAX;
			if(i==j)
				mp[i][j]=0;
		}
		arr[i]=0;
	}
	cin>>s>>k;
	int a,b;
	for(int i=0;i<k;++i){
		cin>>a>>b;
		mp[a][b]=1;
	}/*
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			cout<<((mp[i][j]==INT_MAX)?INT_MAX:mp[i][j])<<' ';
		}
		cout<<endl;
	}*/
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			for(int k=0;k<10;++k){
				if(mp[j][k]>mp[j][i]+mp[i][k])
					mp[j][k]=mp[j][i]+mp[i][k];
			}
		}
	}
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			if(mp[i][j]<INT_MAX)
				++arr[i];
		}
	}
	ull total=1;
	int len=strlen(s);
	for(int i=0;i<len;++i){
		total*=arr[s[i]-'0'];
	}
	cout<<total<<endl;
	return 0;
}
