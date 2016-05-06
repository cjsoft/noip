#include <cstdio>
#include <deque>
int n;
char s[2007];
std::deque<char> q,lq,rq;
int main(){
	//freopen("sun.in","r",stdin);
	//freopen("sun.out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s);
	for (int i = 0; i < n; ++i){
		q.push_back(s[i]);
	}
	while(!q.empty()){
		if(q.front()<q.back()){
			putchar(q.front());
			q.pop_front();
		}else if(q.front()>q.back()){
			putchar(q.back());
			q.pop_back();
		}else{
			if(q.size()==1){
				putchar(q.front());
				break;
			}
			while(q.front()==q.back() && q.size()!=1){
				lq.push_back(q.front());
				rq.push_back(q.front());
				if(q.front()>q.back()){
					while(!rq.empty()){
						putchar(rq.front());
						rq.pop_front();
					}
					putchar(q.back());
					q.pop_back();
					while(!lq.empty()){
						q.push_front(lq.back());
						lq.pop_back();
					}
				}else{
					while(!rq.empty()){
						putchar(rq.front());
						rq.pop_front();
					}
					putchar(q.back());
					q.pop_front();
					while(!lq.empty()){
						q.push_back(lq.back());
						lq.pop_back();
					}
				}
			}

			
		}
	}
	putchar('\n');
	return 0;
}