#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=11000;
const int maxm=21111;
int z = 0;
struct EdgeNode{
    int to;
    int w;
    int next;
}edges[maxm];
int head[maxn],edge;
bool vis[maxn];

void init(){
    edge=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}
void addedge(int u,int v,int w){
    edges[edge].w=w,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
}
int n,K;
struct CenterTree{
    int n;
    int ans;
    int siz;
    int son[maxn];
    void dfs(int u,int pa){
        son[u]=1;
        int res=0;
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (v==pa) continue;
            if (vis[v]) continue;
            dfs(v,u);
            son[u]+=son[v];
            res=max(res,son[v]-1);
        }
        res=max(res,n-son[u]);
        if (res<siz){
            ans=u;
            siz=res;
        }
    }
    int getCenter(int x){
        ans=0;
        siz=INF;
        dfs(x,-1);
        return ans;
    }
}Cent;
int data[maxn];
int dis[maxn];
int Len;
int ans;
void getArray(int u,int pa){
    ++z;
    data[++Len]=dis[u];
    for (int i=head[u];i!=-1;i=edges[i].next){
        int v=edges[i].to;
        int w=edges[i].w;
        if (v==pa) continue;
        if (vis[v]) continue;
        dis[v]=dis[u]+w;
        getArray(v,u);
    }
}
int calc(int u,int now){
    dis[u]=now;
    Len=0;
    getArray(u,-1);
    sort(data+1,data+Len+1);
    int res=0;
    int l=1,r=Len;
    while (l<r){
        // z++;
        if (data[r]+data[l]<=K){
            res+=(r-l);
            l++;
        }
        else r--;
    }
    return res;
}
void solve(int u){
    ans+=calc(u,0);
    vis[u]=true;
    for (int i=head[u];i!=-1;i=edges[i].next){
        int v=edges[i].to;
        int w=edges[i].w;
        if (vis[v]) continue;
        ans-=calc(v,w);
        Cent.n=Cent.son[v];
        int rt=Cent.getCenter(v);
        printf("-- %d\n", rt);
        solve(rt);
    }
}
int main()
{
    while (~scanf("%d%d",&n,&K)){
        if (n==0&&K==0) break;
        init();
        z = 0;
        for (int i=1;i<n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z);
            addedge(y,x,z);
        }
        ans=0;
        Cent.n=n;
        int root=Cent.getCenter(1);
        printf("-- %d\n", root);
        solve(root);
        printf("%d %d\n",ans, z);
    }
    return 0;
}
/**
20 10
1 2 3
2 3 4
3 4 5
4 5 6
5 6 7
6 7 8
7 8 9
8 9 10
9 10 11
10 11 12
11 12 13
12 13 14
13 14 15
14 15 16
15 16 17
16 17 18
17 18 19
18 19 20
19 20 21
**/

