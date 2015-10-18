#include <iostream>
#include <cstdio>
const long long mOD=1000000009;
using namespace std;
typedef long long ll;

ll jiecheng[4007];
void init_jiecheng(){
    jiecheng[0]=1;
    for (int i = 1; i < 4007; ++i)
    {
        jiecheng[i]=(jiecheng[i-1]*i)%mOD;
    }
    jiecheng[0]=0;
}
ll n,w,b;

ll dfs_split(int t_left,int day_left){
    if(t_left==day_left)
        return jiecheng[t_left];
    if(day_left==1)return jiecheng[t_left];
    ll temp=0;
    for (int i = 1; i <= t_left-day_left; i++) {
        temp+=(dfs_split(t_left-i,day_left-1))*jiecheng[i];
        // cout<<temp<<' ';
        temp%=mOD;
    }
    // cout<<temp<<endl;
    return temp;
}

int main(){
    init_jiecheng();
    cin>>n>>w>>b;
    ll result_=0;
    ll cur=1;
    for (int i = 2; i < n; ++i)
    {
        cur=1;
        cur*=dfs_split(w,i);
        cur%=mOD;
        cur*=dfs_split(b,n-i);
        cur%=mOD;
        result_+=cur;
    }
    // for (int i = 1; i <=n-2; ++i)
    // {
    //     for (int j = 1; j <=n-1-i; ++j)
    //     {
    //         for (int l = i; l <=w-(n-i-j); ++l)
    //         {
    //             cur=dfs_split(l,i);
    //             cur*=dfs_split(w-l,n-i-j);
    //             cur%=mOD;
    //             cur*=dfs_split(b,j);
    //             cur%=mOD;
    //             result_+=cur;
    //             result_%=mOD;
    //         }
    //     }
    // }
    cout<<result_<<endl;
    return 0;
}