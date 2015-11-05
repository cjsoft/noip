// panda is stupid
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
int s,t;
template <typename T1,typename T2>
class P{
	public:
	T1 first;T2 second;
	P(T1 a,T2 b){
		first=a;second=b;
	}
	P(){
		
	}
};

std::vector < P<int,int> > mp[107];
int dist[107];
bool tag[107];
std::queue <int> q;
int nx[107],ny[107];
int n,m;
int spfa(){
	memset(tag,false,sizeof(tag));
	while(!q.empty()){
		q.pop();
	}
	for(int i=0;i<=106;++i){
		dist[i]=INT_MAX;
	}
	q.push(s);
	tag[s]=true;
	dist[s]=0;
	int ooo;
	while(!q.empty()){
		ooo=q.front();q.pop();
		tag[ooo]=false;
		for(vector<P<int,int> >::iterator j=mp[ooo].begin();j!=mp[ooo].end();j++){
			if(dist[ooo]+(j->second)<dist[j->first]){
				dist[j->first]=dist[ooo]+(j->second);
				if(!tag[j->first]){
					q.push(j->first);
					tag[j->first]=true;
				}
			}
		}
	}
	return dist[t];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d %d",nx+i,ny+i);
	}
	scanf("%d",&m);
	int ttt;
	int a,b;
	for(int i=1;i<=m;++i){
		scanf("%d %d",&a,&b);
		mp[a].push_back(P<int,int>(b,int(sqrt((nx[a]-nx[b])*(nx[a]-nx[b])+(ny[a]-ny[b])*(ny[a]-ny[b]))*1000+0.5)));
		mp[b].push_back(P<int,int>(a,int(sqrt((nx[a]-nx[b])*(nx[a]-nx[b])+(ny[a]-ny[b])*(ny[a]-ny[b]))*1000+0.5)));
	}
	scanf("%d %d",&s,&t);
	printf("%.2f\n",spfa()/1000.0);
	return 0;
}
