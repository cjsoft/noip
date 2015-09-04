#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
struct student
{
	int id,chinese,math,english,total;
}arr[307];
bool cop(student a,student b){
	if(a.total>b.total)
		return true;
	else if(a.total<b.total)
		return false;
	else{
		if(a.chinese>b.chinese)
			return true;
		else if(a.chinese<b.chinese)
			return false;
		else
			return a.id<b.id;
	}
}
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>arr[i].chinese>>arr[i].math>>arr[i].english;
		arr[i].id=i+1;
		arr[i].total=arr[i].chinese+arr[i].math+arr[i].english;
	}
	sort(arr,arr+n,cop);
	for(int i=0;i<5;++i){
		cout<<arr[i].id<<' '<<arr[i].total<<endl;
	}
	return 0;
}