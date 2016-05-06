#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
bitset<32> bst;
int n;
int main(){
	scanf("%d",&n);
	bst=bitset<32>(n);
	cout<<bst<<endl;
	return 0;
}
