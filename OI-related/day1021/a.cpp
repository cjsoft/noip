#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n;
long long limit;
long long p[15]={1,2,3,5,7,11,13,17,19,23,29,31};
struct node
{
long long ans,num;
}out[10000];
long long tail=0;
bool mark[10000];
void dfs(long long k,long long now,long long cnt,long long last)
{
if(k==12)
{
bool flag=false;
for(long long i=1;i<=tail;i++)
{
if(mark[i]==false&&now<=out[i].ans&&cnt>=out[i].num)mark[i]=true;
if(mark[i]==false&&now>out[i].ans&&cnt<=out[i].num)flag=true;
}
if(flag==false)
{
tail++;
out[tail].num=cnt;out[tail].ans=now;
}
return;
}
long long t=1;
for(long long i=0;i<=last;i++)
{
dfs(k+1,now*t,cnt*(i+1),i);
t*=p[k];
if(now*t>n)break;
}
}
long long real[1000];
int main()
{
long long gg=0;
scanf("%I64d%I64d",&limit,&n);
dfs(1,1,1,30);
long long a;
long long cnt=0;
for(a=1;a<=tail;a++)if(mark[a]==false&&out[a].ans>=limit)
{
cnt++;
real[cnt]=out[a].ans;
}
if(cnt==0)
{
cout<<"NO";
return 0;
}
sort(real+1,real+cnt+1);
cout<<real[1];
for(a=2;a<=cnt;a++)cout<<","<<real[a];
return 0;
}