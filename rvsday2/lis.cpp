#include <iostream>
#include <cstdio>

using namespace std;

int arr[1007];
int dp[1007];

int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		dp[i]=1;
	}
	for (int i = 0; i < n-1; ++i){
		for (int j = i+1; j < n; ++j){
			if(arr[j]>arr[i])
				dp[j]=max(dp[i]+1,dp[j]);
		}
	}
	int m=0;
	for (int i = 0; i < n; ++i){
		m=max(m,dp[i]);
	}
	cout<<m<<endl;
	return 0;
}