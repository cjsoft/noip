#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#define MXN 200007
using namespace std;

vector<int> nodeStack;
int n;
int dfn[MXN],low[MXN];
int fa[MXN];
char instack[MXN];
int depth=0;
int global_result=INT_MAX;

void dfs(int root){
	dfn[root]=low[root]=++depth;
	nodeStack.push_back(root);
	instack[root]=1;
	if(!instack[fa[root]]){
		dfs(fa[root]);
		low[root]=min(low[root],low[fa[root]]);
	}else{
		if(instack[fa[root]]==1)low[root]=min(low[root],dfn[fa[root]]);
	}
	if(low[root]==dfn[root]){
		int count=1;
		while(nodeStack.back()!=root){
			instack[nodeStack.back()]=2;
			count++;
			nodeStack.pop_back();
		}
		instack[nodeStack.back()]=2;
		nodeStack.pop_back();
		if(count>1)global_result=min(global_result,count);
	}
}

int main(){
	scanf("%d",&n);
	fill_n(fa,n+1,0);
	fill_n(instack,n+1,0);
	fill_n(dfn,n+1,0);
	fill_n(low,n+1,0);
	for(int i=1;i<=n;++i){
		scanf("%d",fa+i);
	}
	for(int i=1;i<=n;++i){
		if(!instack[i]){
			dfs(i);
		}
	}
	printf("%d\n", global_result);
	return 0;
}