#include<iostream>
#include<stdio.h>
#include<cstring>
#define ULL unsigned long long
using namespace std;
char s[50];
int n,a,b,len;
int mp[15][15];

void in()
{
    cin>>s;
    cin>>n;
    len=strlen(s);
    while(n--){cin>>a>>b;mp[a][b]=1;}
}

void floyd()
{
    for(int k=0; k<10; k++)
     for(int i=0; i<10; i++)
      for(int j=0; j<10; j++)
       if(mp[i][j]>mp[i][k]+mp[k][j])
       mp[i][j]=mp[i][k]+mp[k][j];
}


int main ()
{
    for(int i=0; i<=10; i++)
    for(int j=0; j<=10; j++)
        if(i==j) mp[i][j]=0;
        else mp[i][j]=100;

    in();
    for(int i=0;i<10;++i){
    for(int j=0;j<10;++j){
      cout<<((mp[i][j]==LONG_LONG_MAX)?-1:mp[i][j])<<' ';
    }
    cout<<endl;
  }
    floyd();

    int c[10]= {0};
    for(int i=0; i<=9; i++){
     for(int j=0; j<=9; j++){
        if(mp[i][j]<100) c[i]++;
     }
    }


    ULL ans=1;
    for(int i=0; i<len; i++)
        ans*= (c[s[i]-'0']);
    cout<<ans<<endl;
}