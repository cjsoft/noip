#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ag
{
	std::vector<string> v;
}tag[13][32];

bool cmp(string a,string b){
	if(a.length()!=b.length())
		return a.length()<b.length();
	return a<b;
}

int main(){
	int n;
	int a,b;
	string temp;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp>>a>>b;
		tag[a][b].v.push_back(temp);
	}
	bool t=false;
	for (int i = 1; i < 13; ++i)
	{
		for (int j = 1; j < 32; ++j)
		{
			if(tag[i][j].v.size()>1){
				t=true;
				sort(tag[i][j].v.begin(), tag[i][j].v.end(),cmp);
				cout<<i<<' '<<j<<' ';
				for (std::vector<string>::iterator k = tag[i][j].v.begin(); k != tag[i][j].v.end(); ++k)
				{
					cout<<*k;
					if(k+1!=tag[i][j].v.end())
						putchar(' ');
				}
				putchar('\n');
			}
		}
	}
	if(!t)
		cout<<"None"<<endl;
	return 0;
}