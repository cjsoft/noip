#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	char a[256];
	cin.getline(a,256);
	for (int i = 0; i < 256; ++i)
	{
		if(!a[i])return 0;
		if(a[i]>='a' && a[i]<='z'){
			putchar(a[i]+'A'-'a');
		}else if(a[i]>='A' && a[i]<='Z'){
			putchar(a[i]+'a'-'A');
		}
		else{
			putchar(a[i]);
		}
	}
	return 0;
}