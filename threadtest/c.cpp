#include <iostream>
#include <cstdio>
#include <pthread.h>
#include <cstdlib>

using namespace std;
bool a=true,b=true;
void sleep(){
	while(a || b);
}
void *hello(void *aa){
	for(int i=0;i<1000000000;++i);
	printf("hello\n");
	a=false;
}
void *world(void *aa){
	printf("world\n");
	b=false;
}
pthread_t t1,t2;
int main(){
	int **r1,**r2;
	pthread_create(&t1,0,hello,0);

	pthread_create(&t2,0,world,0);
	//sleep();
	pthread_join(t2,0);
	printf("t2 join done\n");
	pthread_join(t1,0);
	printf("t1 join done\n");
	printf("done\n");
	return 0;
}