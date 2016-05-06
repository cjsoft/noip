#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct DIR{
	string name;
	vector <DIR> dirs;
	vector <string> files;
	DIR(string temp){
		name=temp;
	}
	bool operator<(const DIR &b)const{
		return name<b.name;
	}

	void print(string n){
		printf("%s",n.c_str());
		printf("%s\n",name.c_str());
		sort(files.begin(),files.end());
		for(vector<DIR>::iterator j=dirs.begin();j!=dirs.end();j++){
			j->print(n+"|     ");
		}
		for(vector<string>::iterator j=files.begin();j!=files.end();j++){
			printf("%s",n.c_str());
			printf("%s\n",j->c_str());
		}

	}
	int load(){
		string temp;
		do{
			cin>>temp;
			if(temp=="#")return 2;
			if(temp.substr(0,1)=="*")return 0;
			if(temp.substr(0,1)=="f"){
				files.push_back(temp);
			}
			if(temp.substr(0,1)=="d"){
				dirs.push_back(DIR(temp));
				if((dirs.end()-1)->load()==0)return 0;
			}
		}while(temp!="]");
		return 1;
	}
}*root;


int main(){
	string temp="";
	root =new DIR("ROOT");
	int cnt=1;
	while (temp!="#"){
		if(root->load()==2){
			return 0;
		}
		if(cnt!=1)printf("\n");
		printf("DATA SET %d:\n",cnt++);
		root->print("");
		delete root;
		root=new DIR("ROOT");
	}
	return 0;
}
