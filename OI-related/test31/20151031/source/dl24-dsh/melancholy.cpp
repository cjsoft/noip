#include<cstdio>
#include<iostream>
#include<set>
#include<cstdlib>
#include<ctime>
using namespace std;

int n,m;
bool flag;

struct aland{
	long long l,v;
};

aland ta[100001];

bool operator<(const aland& lhs, const aland& rhs) {
    if (lhs.l<rhs.l) return 1;
	if (lhs.v<rhs.v) return 1;
	return 0;
}

multiset<aland>ww;
multiset<aland>::iterator q;
multiset<aland>::iterator w;
multiset<aland>::iterator e;
multiset<aland>::iterator r;
long long t1,t2,t3,t4,t5,sum;

const long long inf=4294967296;

int main(){
	freopen ("melancholy.in","r",stdin);
	freopen ("melancholy.out","w",stdout);
	cin>>n>>m;
	
	for (int i=1;i<=n;i++) cin>>ta[i].l;
	for (int i=1;i<=n;i++){
		cin>>ta[i].v;
		ww.insert((aland){ta[i].l,ta[i].v});
	}
	
	for (int i=1;i<=m;i++){
		sum=0;
		cin>>t1>>t2>>t3;
		q=ww.lower_bound((aland){t1,0});
		w=ww.lower_bound((aland){t2,1000000001});
		if (t3==1){
			t4=inf;
			for (e=q;e!=w;e++){
				if ((*e).v<t4) t4=((*e).v);
			}
			for (e=q;e!=w;e++){
				if (((*e).v!=t4)) sum+=(*e).v%inf;
			}
		}
		cout<<sum%inf;
	}
	
	
	return 0;
}