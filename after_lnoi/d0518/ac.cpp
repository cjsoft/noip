#include<iostream>
#include<string>
#include <cstdio>
using namespace std;

int dp[500005];
int q[500005];
int sum[500005];
int head,tail,n,m;

int getDP(int i,int j)
{
    return dp[j]+m+(sum[i]-sum[j])*(sum[i]-sum[j]);
}

int getUP(int j,int k)  //yj-yk的部分
{
    return dp[j]+sum[j]*sum[j]-(dp[k]+sum[k]*sum[k]);
}

int getDOWN(int j,int k) //xj-xk的部分
{
    return 2*(sum[j]-sum[k]);
}

int main()
{
    int i;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&sum[i]);
        sum[0]=dp[0]=0;
        for(i=1;i<=n;i++)
            sum[i]+=sum[i-1];
        head=tail=0;
        q[tail++]=0;
        for(i=1;i<=n;i++)
        {
            while(head+1<tail && getUP(q[head+1],q[head])<=sum[i]*getDOWN(q[head+1],q[head])) {
                printf("--- %d\n", tail - head);
                head++;
            }
            dp[i]=getDP(i,q[head]);
            printf("%d %d\n", dp[i], q[head]);
            while(head+1<tail && getUP(i,q[tail-1])*getDOWN(q[tail-1],q[tail-2])<=getUP(q[tail-1],q[tail-2])*getDOWN(i,q[tail-1])) {
                printf("--- %d\n *** %d %d", q[tail - 1], getUP(i,q[tail-1])*getDOWN(q[tail-1],q[tail-2]),getUP(q[tail-1],q[tail-2])*getDOWN(i,q[tail-1]));
                tail--;
            }
            q[tail++]=i;
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}