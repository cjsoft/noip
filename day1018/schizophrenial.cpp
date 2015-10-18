#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int x,l,r,p;
bool tags[1000007];
void dfs(int a,int b,int tms){
    if(tms>p || a>r)return ;
    tags[a]=true;
    dfs(a,b+1,tms+1);
    dfs(a*b,b,tms+1);
}

int main(){
    memset(tags,0,sizeof(tags));
    cin>>l>>r>>p;
    dfs(1,0,0);
    int cnt=0;
    for (int i = l; i <=r; i++) {
        if(tags[i])++cnt;
    }
    cout<<cnt;
    return 0;
}