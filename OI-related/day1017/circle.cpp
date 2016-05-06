#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
const int ASIZE=2*1000000+13;

using namespace std;
typedef long long ll;
ll global_result=0;

int lowbit(int &x){return x&(-x);}
struct Circ
{
	int l,r;
	bool operator<(const Circ &b)const{
		if(l==b.l)
			return r>b.r;
		return l<b.l;
	}
}lns[5007];
class TreeArray{
private:
	ll rawdata[ASIZE];
	ll _sum(int n){
		ll rtn=0;
		while(n>0){
			rtn+=rawdata[n];
			n-=lowbit(n);
		}
		return rtn;
	}

	void _add(int x,ll ad){
		while(x<ASIZE && x>0){
			rawdata[x]+=ad;
			x+=lowbit(x);
		}
	}
public:
	TreeArray(){
		memset(rawdata,0,sizeof(rawdata));
	}
	void test(){
		for (int i = 1; i < 10; ++i)
		{
			_add(i,i);
		}
		cout<<_sum(8);
	}
	int cv(int x){
		return x+1000001;
	}
	ll sum(int ll,int rr){
		if(ll > rr)
			swap(ll,rr);
		return _sum(cv(rr))-_sum(cv(ll-1));
	}

	void add(int x,ll ad){
		_add(cv(x),ad);
	}
	void inc(int x){
		_add(cv(x),1);
	}
}asd;
int n;
int main(){
	open("circle.in","circle.out");
	scanf("%d",&n);
	int tx,tr;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d",&tx,&tr);
		lns[i].l=tx-tr;lns[i].r=tx+tr;
	}
	sort(lns,lns+n);
	for (int i = 0; i < n; ++i)
	{
		global_result+=asd.sum(lns[i].l+1,lns[i].r-1)+1;
		asd.inc(lns[i].l);asd.inc(lns[i].r);
	}
	cout<<global_result+1<<endl;
	return 0;
}

/*
用树状数组+排序递推试一试？
**damn!样例都过不了**
*/