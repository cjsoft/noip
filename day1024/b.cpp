#include <iostream>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
char raw[3000007];
int tl;
int k;

int patterning(int lb,int k){
    if(k==0){
        return 0;
    }
    int fourk=1<<((k-1)<<1);
    int cnt=0;
    for (int i = 0; i < fourk; ++i){
        if(raw[lb+i]!='J')
            ++cnt;
    }
    for (int i = 0; i < fourk; ++i){
        if(raw[lb+i+fourk]!='O')
            ++cnt;
    }
    for (int i = 0; i < fourk; ++i){
        if(raw[lb+i+(fourk<<1)]!='I')
            ++cnt;
    }
    cnt+=patterning(lb+(fourk<<1)+fourk,k-1);
    return cnt;
}

int main(){
    open("b.in","b.out");
    memset(raw,0,sizeof(raw));
    scanf("%d",&k);
    scanf("%s",raw);
    tl=strlen(raw);
    memcpy(raw+tl,raw,tl);
    int mmm=INT_MAX;
    for (int i = 0; i < tl; ++i){
        mmm=min(patterning(i,k),mmm);
    }
    printf("%d\n", mmm);
    return 0;
}


