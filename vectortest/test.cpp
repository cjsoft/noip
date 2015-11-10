#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector <int>a;
const int n=100000007;
int arr[n];
int main(){
	clock_t asd=clock(),b;
	printf("init with clock at %d\n",int(asd));
	asd=clock();
	for(int i=1;i<=n;++i){
		a.push_back(i);
	}
	b=clock();
	printf("adding used %lf\n",double(b-asd)/CLOCKS_PER_SEC);
	asd=clock();
	for(vector<int>::iterator i=a.begin();i!=a.end();i++){
		*i=*i+1;
	}
	b=clock();
	printf("normally iterating used %lf\n",double(b-asd)/CLOCKS_PER_SEC);
	asd=clock();
	vector<int>::iterator e=a.end();
	for(vector<int>::iterator i=a.begin();i!=e;i++){
		*i=*i+1;
	}
	b=clock();
	printf("better iterating used %lf\n",double(b-asd)/CLOCKS_PER_SEC);
	asd=clock();
	for(int i=0;i<a.size();++i){
		a[i]=a[i]+1;
	}
	b=clock();
	printf("using[] used %lf\n",double(b-asd)/CLOCKS_PER_SEC);
	asd=clock();
	for(int i=0;i<n;++i){
		arr[i]=arr[i]+1;
	}
	b=clock();
	printf("using array used %lf\n",double(b-asd)/CLOCKS_PER_SEC);
	return 0;
}
