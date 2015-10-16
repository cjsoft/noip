#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;
const int CNT=1000007;
int n;
int a[CNT],b[CNT];
ll total=0;
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",a+i);
        total+=a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d",b+i);
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