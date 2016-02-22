#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>

using namespace std;


int n;
double a[20][20],b[20][20]={0},ans[20];

int main()
{
    cin>>n;
    for(int i=1;i<=n+1;++i)
        for(int j=1;j<=n;++j)
        {
            cin>>b[i][j];
            b[i][n+1]+=b[i][j]*b[i][j];
        }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            a[i][j]=b[i+1][j]-b[i][j];
        a[i][n+1]=(b[i+1][n+1]-b[i][n+1])/2;      
    }

    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
        {
            double kk=a[i][i]/a[j][i];
            for(int k=1;k<=n+1;++k)
                a[j][k]=a[j][k]*kk-a[i][k];
        }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1; ++j) {
            printf("%lf ", a[i][j]);
        }
        putchar('\n');
    }
    for(int i=n;i>=1;--i)
    {
        double tot=0;
        for(int j=n;j>i;--j)
            tot+=a[i][j]*ans[j];
        ans[i]=(a[i][n+1]-tot)/a[i][i];
    }


    for(int i=1;i<n;++i)
        printf("%.3f ",ans[i]);
    printf("%.3f\n",ans[n]);

    return 0;

}