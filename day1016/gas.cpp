#include <iostream>
#include <cstdio>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout);

using namespace std;
typedef long long ll;
const int CNT=1000007;
int n;
ll a[CNT],b[CNT];
ll total=0;
int main(){
    open("gas.in","gas.out");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%lld",a+i);
        total+=a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld",b+i);
    }
    double avg=double(total)/n;
    for (int i = 0; i < n; ++i) {
        if(avg>b[i]){
            printf("TvT\n");
            return 0;
        }
    }
    printf("%.12lf\n",avg );
    return 0;
}