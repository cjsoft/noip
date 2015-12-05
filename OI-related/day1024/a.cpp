#include <iostream>
#include <cstdio>
#include <string>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout)
using namespace std;
int k,m,n;
string aaa;
string final;
int main(){
    open("a.in","b.out");
    scanf("%d%d",&k,&m);
    cin>>aaa;
    scanf("%d",&n);
    int a,b,c;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        aaa=aaa.substr(0,c)+aaa.substr(a,b-a)+aaa.substr(c,aaa.length()-c);
        if(aaa.length()>m)
            aaa=aaa.substr(0,m);
    }
    printf("%s\n",aaa.substr(0,min(k,(int)aaa.length())).c_str() );
    return 0;
}