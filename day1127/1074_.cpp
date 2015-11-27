#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,m,fa[50010],va[50010]={0};
int find(int x){
    if(fa[x]!=x){
        int tmp=fa[x];//记录原始的父结点号，如果不记录，则到计算va时父结点已经变了
        fa[x]=find(fa[x]);
        va[x]=(va[x]+va[tmp])%3;//根据自己到原始父结点的路径值和原始父结点到祖宗的路径值调整
    }
    return fa[x];
}
void myunion(int &a,int &b,int x){
    va[fa[a]]=3+x-va[a];//这句要先做
    fa[fa[a]]=b;//这句要晚做，否则a的祖宗已经换人了
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){
        fa[i]=i; 
    }
    int ans=0,t,x,y;
    for(int i=1;i<=m;i++){  
        scanf("%d%d%d",&t,&x,&y);
        if(x>n||y>n){ans++;continue;}
        if(t==1){
            if(x!=y){
                if(find(x)==find(y)){
                    if(va[x]!=va[y])ans++;
                }else myunion(x,y,0);
            }
        }else{
            if(x==y){ans++;continue;}
            if(find(x)==find(y)){
                if(va[x]!=(va[y]+1)%3)ans++;
            }else myunion(x,y,1);
        }   
    }
    cout<<ans<<endl;    
    return 0;
}