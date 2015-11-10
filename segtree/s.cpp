#include <cstdio>
#include <iostream>

using namespace std;
const int MXN=10007;
int stree[MXN];
int arr[MXN];

inline int lson(int root){
	return root<<1;
}

inline int rson(int root){
	return root<<1|1;
}

void build_tree(int root,int l,int r){
	if(r==l){
		stree[root]=arr[l];
		return;
	}
	int m=l+(r-l)>>1;
	build_tree(lson(root),l,m);
	build_tree(rson(root),m+1,r);
	stree[root]=min(stree[lson(root)],stree[rson(root)]);
	return ;
}

int main(){
	
	return 0;
}
