#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const double pi=acos(-1);
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define Rep(i,u) for(int i=head[u];i;i=Next[i])
#define clr(a) memset(a,0,sizeof a)
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
ld eps=1e-9;
ll pp=1000000007;
ll mo(ll a,ll pp){if(a>=0 && a<pp)return a;a%=pp;if(a<0)a+=pp;return a;}
ll powmod(ll a,ll b,ll pp){ll ans=1;for(;b;b>>=1,a=mo(a*a,pp))if(b&1)ans=mo(ans*a,pp);return ans;}
ll read(){
	ll ans=0;
	char last=' ',ch=getchar();
	while(ch<'0' || ch>'9')last=ch,ch=getchar();
	while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
	if(last=='-')ans=-ans;
	return ans;
}
//head
int q[100];
int get(){
	return (rand()<<13)+rand();
}
int main(){
	freopen("tree20.in","w",stdout);
	srand((unsigned)time(NULL));
	int n=100000,m=n;
	printf("%d\n",n);
//	rep(i,2,n)printf("%d %d %d\n",1+get()%(i-1),i,1+get()%10000);
	rep(i,2,n)printf("%d %d %d\n",i-1,i,1+get()%10000);
	printf("%d\n",m);
	while(m--){
		rep(i,1,4)q[i]=1+get()%n;
		sort(q+1,q+5);
		while(q[1]==q[2] || q[2]==q[3] || q[3]==q[4]){
			rep(i,1,4)q[i]=1+get()%n;
			sort(q+1,q+5);
		}
		printf("%d %d %d %d\n",q[1],q[2],q[3],q[4]);
	}
	return 0;
}
