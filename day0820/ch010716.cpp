#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
string temp;
int main(){
	cin>>temp;
	if(temp.length()>2)
		if(temp.substr(temp.length()-2,2)=="er" || temp.substr(temp.length()-2,2)=="ly")
		{
			cout<<temp.substr(0,temp.length()-2)<<endl;
			return 0;
		}
	if(temp.length()>3)
		if(temp.substr(temp.length()-3,3)=="ing")
		{
			cout<<temp.substr(0,temp.length()-3)<<endl;
			return 0;
		}
	cout<<temp<<endl;
	return 0;
}