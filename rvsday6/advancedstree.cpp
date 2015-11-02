// becareful with the seg comparing !!!
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const int MXN=100007;

ll stree[MXN],taga[MXN],tage[MXN];
ll arr[MXN];
inline int lson(int root){
	return root<<1;
}
inline int rson(int root){
	return root<<1|1;
}
inline void pushdown(int root,int l,int r){
	int m=(l+r)>>1;
	if(taga[root]){
		taga[lson(root)]+=taga[root];
		taga[rson(root)]+=taga[root];
		stree[lson(root)]+=taga[root]*(m-l+1);
		stree[rson(root)]+=taga[root]*(r-m);
		taga[root]=0;
	}
	if(tage[root]){
		tage[lson(root)]=tage[root];
		tage[rson(root)]=tage[root];
		stree[lson(root)]=tage[root]*(m-l+1);
		stree[rson(root)]=tage[root]*(r-m);
		tage[root]=0;
	}
}

void buildtree(int root,int l,int r){
	if(l==r){
		stree[root]=arr[l];
		return;
	}
	int m=(l+r)>>1;
	buildtree(lson(root),l,m);
	buildtree(rson(root),m+1,r);
	stree[root]=stree[lson(root)]+stree[rson(root)];
}

ll query(int root,int l,int r,int ql,int qr){
	if(l>qr || r<ql)return 0;
	if(l>=ql && r<=qr){
		pushdown(root,l,r);
		return stree[root];
	}
	pushdown(root,l,r);
	int m=(l+r)>>1;
	return query(lson(root),l,m,ql,qr)+query(rson(root),m+1,r,ql,qr);
}

void add(int root,int l,int r,int addl,int addr,ll addd){
	if(l>addr || r<addl)return ;
	pushdown(root,l,r);
	if(l>=addl && r<=addr){
		taga[root]+=addd;
		stree[root]+=addd*(r-l+1);
		return;
	}
	int m=(l+r)>>1;
	add(lson(root),l,m,addl,addr,addd);
	add(rson(root),m+1,r,addl,addr,addd);
	stree[root]=stree[lson(root)]+stree[rson(root)];
}

void edit(int root,int l,int r,int editl,int editr,ll editd){
	if(l>editr || r<editl)return ;
	pushdown(root,l,r);
	if(l>=editl && r<=editr){
		tage[root]=editd;
		stree[root]=editd*(r-l+1);;
		return;
	}
	int m=(l+r)>>1;
	edit(lson(root),l,m,editl,editr,editd);
	edit(rson(root),m+1,r,editl,editr,editd);
	stree[root]=stree[lson(root)]+stree[rson(root)];
}
const int n=10000;
int main(){
	memset(arr,0,sizeof(arr));
	memset(stree,0,sizeof(stree));
	buildtree(1,1,n);
	edit(1,1,n,200,300,100);
	add(1,1,n,100,250,50);
	cout<<query(1,1,n,200,250)<<endl;
	return 0;
}
