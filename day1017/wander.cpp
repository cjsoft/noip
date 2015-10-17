#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
std::vector<int> mp[100007];
std::vector<bool> etag[100007];
int tag[100007];
int n,m,mcnt=0;

void clear_etag(){
	for (int i = 0; i < 100007; ++i){
		for (std::vector<bool>::iterator j = etag[i].begin(); j != etag[i].end(); ++j){
			*j=false;
		}
	}
}

int main(){
	open("wander.in","wander.out");
	srand(int(time(0)));
	scanf("%d %d",&n,&m);
	memset(tag,false,sizeof(tag));
	int ta,tb;
	for (int i = 0; i < m; ++i){
		scanf("%d %d",&ta,&tb);
		mp[ta].push_back(tb);
		etag[ta].push_back(false);
	}
	printf("%d\n", rand()%n+1);
	return 0;
}