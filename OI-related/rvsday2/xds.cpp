// 线段树任何对于节点的操作都pushdown一下，肯定没有坏处
// 把所有节点更新操作都交给pushdown来搞，放心！、
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
const int MXN=1000007;
ll stree[MXN];
ll res[MXN];
ll tag[MXN];
inline int lson(int n){
	return n<<1;
}
inline int rson(int n){
	return n<<1|1;
}

void update(int root){
	stree[root]=stree[lson(root)]+stree[rson(root)];
}

void pushdown(int root,int sl,int sr){
	if(tag[root]){
		int m=(sl+sr)>>1;
		tag[lson(root)]+=tag[root];
		tag[rson(root)]+=tag[root];
		stree[lson(root)]+=tag[root]*(m-sl+1);;
		stree[rson(root)]+=tag[root]*(sr-m);
		tag[root]=0;
	}
}

ll query(int root,int al,int ar,int ql,int qr){
	if(ql<=al && qr>=ar)
		return stree[root];
	if(ql>ar || qr<al)
		return 0;
	pushdown(root,al,ar);
	int m=(al+ar)>>1;
	ll templ=query(lson(root),al,m,ql,qr);
	ll tempr=query(rson(root),m+1,ar,ql,qr);
	return templ+tempr;
}

void add(int root,int al,int ar,int addl,int addr,int adddata){
	if(addl>ar || addr<al)
		return;
	if(al>=addl && ar<=addr){
		tag[root]+=adddata;
		stree[root]+=adddata*(ar-al+1);
		return;
	}
	pushdown(root,al,ar);
	int m=(al+ar)>>1;
	add(lson(root),al,m,addl,addr,adddata);
	add(rson(root),m+1,ar,addl,addr,adddata);
	update(root);
}

void buildtree(int root,int al,int ar){
	tag[root]=0;
	if(al==ar){
		stree[root]=res[al];
		return;
	}
	int m=(al+ar)>>1;
	buildtree(lson(root),al,m);
	buildtree(rson(root),m+1,ar);
	update(root);
}

int n;


int main(){
	cin>>n;
	for (int i = 1; i <=n; ++i)
	{
		cin>>res[i];
	}
	buildtree(1,1,n);
	int q,tx,a,b,x;
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		cin>>tx;
		if(tx==1){
			cin>>a>>b>>x;
			add(1,1,n,a,b,x);
		}else{
			cin>>a>>b;
			cout<<query(1,1,n,a,b)<<endl;
		}
	}
	return 0;
}