#include <iostream>
#include <cstdio>
#include <pthread>
using namespace std;

void hello(){
	int n=10000;
	while(n--);
	printf("hello\n");
}
void world(){
	printf("world\n");
}
int main(){
	thread a(hello),b(world);
	a.join();
	b.join();
	return 0;
}