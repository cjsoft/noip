#include <iostream>

int main(){
#ifdef WIN32
	std::cout<<"WIN32";
#else
	std::cout<<"UNIX";
#endif
	return 0;
}