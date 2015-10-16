#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define open(a,b) freopen(a,"r",stdin);freopen(b,"w",stdout);
using namespace std;
int hhd[2007];
int mp[2007][2007];
bool tag[2007];
int n,m,k,q;
bool dfs(int root,int from,int tgt,int hxd){
    tag[root]=true;
    if(root==tgt){
        return true;
    }
    for (int i = 1; i <=n; ++i)
    {
        if(i==from || mp[root][i]<hxd || (!mp[root][i]) || tag[i]){
            continue;
        }
        if(dfs(i,root,tgt,hxd)){
            return true;
        }
    }
    return false;
}
int main(){
    open("car.in","car.out");
    scanf("%d %d %d %d",&n,&m,&k,&q);
    memset(mp,0,sizeof(mp));
    int result_total=0,t_op;
    int tx,ty,tval;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d",&tx,&ty,&tval);
        mp[tx][ty]=tval;
    }
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d",hhd+i);
    }
    for (int i = 0; i < q; ++i)
    {
        scanf("%d",&t_op);
        if(t_op==1){
            scanf("%d %d",&tx,&ty);
            hhd[tx]=ty;
        }else{
            result_total=0;
            scanf("%d %d",&tx,&ty);
            for (int j = 1; j <= k; ++j)
            {
                memset(tag,false,sizeof(tag));
                    // printf("%d %d\n",j, hhd[j]);
                if(dfs(tx,0,ty,hhd[j])){
                    result_total+=hhd[j];
                }
            }
            printf("%d\n",result_total );
        }
    }
    // for (int i = 0; i <=n; ++i)
    // {
    //     for (int j = 0; j <=n; ++j)
    //     {
    //         printf("%d ",mp[i][j] );
    //     }
    //     putchar('\n');
    // }
    return 0;
}