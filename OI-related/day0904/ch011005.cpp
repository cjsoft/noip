#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int arr[107],n;
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	n=unique(arr,arr+n)-arr;
	cout<<n<<endl;
	for(int i=0;i<n;++i){
		cout<<arr[i];
		if(i!=n-1)
			putchar(' ');
	}
	putchar('\n');
	return 0;
}