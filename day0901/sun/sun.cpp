#include <cstdio>
#include <deque>
int n;
char s[2007];
std::deque<char> q;
int main(){
	freopen("sun.in","r",stdin);
	freopen("sun.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s);
	for (int i = 0; i < n; ++i){
		q.push_back(s[i]);
	}
	while(!q.empty()){
		if(q.front()<q.back()){
			putchar(q.front());
			q.pop_front();
		}else{
			putchar(q.back());
			q.pop_back();
		}
	}
	putchar('\n');
	return 0;
}