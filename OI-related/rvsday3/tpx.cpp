// dfs版，比较鸡肋，只能求出一个可行解，不能求出分级、

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
std::vector<int> mp[1007];
int tot=0;
int shunxu[1007];
bool tag[1007];

void visit(int root){
	if(tag[root]==false && !mp[root].empty()){
		tag[root]=true;
		for (std::vector<int>::iterator i = mp[root].begin(); i != mp[root].end(); ++i){
			visit(*i);
		}
		shunxu[tot++]=root;
	}
}

int main(){

	return 0;
}