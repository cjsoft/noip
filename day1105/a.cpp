#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream asd;
int main(){
	string temp,s;
	cin>>temp;
	asd.open(temp.c_str());
	asd>>s;
	cout<<s;
}
