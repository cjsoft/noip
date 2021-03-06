#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

const int MXN=1000007;

ll stree[MXN];
ll arr[MXN];
ll tag[MXN];

inline int lson(int root){
	return root<<1;
}
inline int rson(int root){
	return root<<1|1;
}

void update(int root){
	stree[root]=stree[lson(root)]+stree[rson(root)];
}

void pushdown(int root,int l,int r){
	if(l==r)return;
	if(tag[root]){
		tag[lson(root)]+=tag[root];
		tag[rson(root)]+=tag[root];
		int m=(l+r)>>1;
		stree[lson(root)]+=tag[root]*(m-l+1);
		stree[rson(root)]+=tag[root]*(r-m); //手残害死人，m打成l
		tag[root]=0;
	}
	update(root);
}

ll query(int root,int l,int r,int queryl,int queryr){
	if(l>queryr || r<queryl)
		return 0;
	if(l>=queryl && r<=queryr)
		return stree[root];
	pushdown(root,l,r);
	int m=(l+r)>>1;
	return query(lson(root),l,m,queryl,queryr)+query(rson(root),m+1,r,queryl,queryr);
}

void add(int root,int l,int r,int addl,int addr,ll adddata){
	pushdown(root,l,r);
	if(l>addr || r<addl)
		return ;
	if(l>=addl && r<=addr){
		tag[root]+=adddata;
		stree[root]+=adddata*(r-l+1);
		return;
	}
	int m=(l+r)>>1;
	add(lson(root),l,m,addl,addr,adddata);
	add(rson(root),m+1,r,addl,addr,adddata);
	pushdown(root,l,r);
}

void build(int root,int l,int r){
	tag[root]=0;
	if(l==r){
		stree[root]=arr[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson(root),l,m);
	build(rson(root),m+1,r);
	update(root);
}
int n,q;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	build(1,1,n);
	cin>>q;
	int a,b,c;
	ll d;
	for (int i=0;i<q;++i){
		cin>>a;
		if(a==1){
			cin>>b>>c;
			cin>>d;
			add(1,1,n,b,c,d);
		}else{
			cin>>b>>c;
			cout<<query(1,1,n,b,c)<<endl;
		}
	}
	return 0;
}
