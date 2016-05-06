#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>
 
 #define N 50000
 #define M 100000
 #define INF 1e9
 
 using namespace std;
 
 int head[N],to[M],next[M];
 int sz[N],top[N],bh[N],fa[N],son[N],dep[N];
 int sum[N<<2],mx[N<<2],val[N],dat[N];
 int q[N];
 int n,cnt,tot,qu;
 
 inline void add(int u,int v)
 {
     to[cnt]=v; next[cnt]=head[u]; head[u]=cnt++;
 }
 
 inline void prep()
 {
     int h=1,t=2,sta;
     q[1]=1; dep[1]=1;
     while(h<t)
     {
         sta=q[h++]; sz[sta]=1;
         for(int i=head[sta];~i;i=next[i])
             if(to[i]!=fa[sta])
             {
                 fa[to[i]]=sta;
                 dep[to[i]]=dep[sta]+1;
                 q[t++]=to[i];
             }
     }
     for(int j=t-1;j>=1;j--)
     {
         sta=q[j];
         for(int i=head[sta];~i;i=next[i])
             if(to[i]!=fa[sta])
             {
                 sz[sta]+=sz[to[i]];
                 if(sz[to[i]]>sz[son[sta]]) son[sta]=to[i]; 
             }
     }
     for(int i=1;i<t;i++)
     {
         sta=q[i];
         if(son[fa[sta]]==sta) top[sta]=top[fa[sta]];//不是重链顶部 
         else top[sta]=sta;
     }
 }
 
 inline void rewrite()
 {
     for(int i=1;i<=n;i++)
         if(top[i]==i)
             for(int j=i;j;j=son[j])//每条重链的编号是连续的 
             {
                 bh[j]=++tot;
                 dat[tot]=val[j];
             }
 }
 
 inline void pushup(int x)
 {
     sum[x]=sum[x<<1]+sum[x<<1|1];
     mx[x]=max(mx[x<<1],mx[x<<1|1]);
 }
 
 inline void build(int u,int L,int R)
 {
     if(L==R) {sum[u]=mx[u]=dat[L];return;}
     int MID=(L+R)>>1;
     build(u<<1,L,MID); build(u<<1|1,MID+1,R);
     pushup(u);
 }
 
 inline void read()
 {
     memset(head,-1,sizeof head); cnt=0;
     scanf("%d",&n);
     for(int i=1,a,b;i<n;i++)
     {
         scanf("%d%d",&a,&b);
         add(a,b); add(b,a);
     }
     for(int i=1;i<=n;i++) scanf("%d",&val[i]);
     prep();
     rewrite();
     build(1,1,tot);
     for (int i = 1; i <= n; ++i) {
        printf("%d: locator %d, head %d, size %d, hson %d \n", i, bh[i], top[i], sz[i], son[i] );
    }
 }
 
 inline int querysum(int u,int L,int R,int l,int r)
 {
     if(l<=L&&R<=r) return sum[u];
     int MID=(L+R)>>1,res=0;
     if(l<=MID) res+=querysum(u<<1,L,MID,l,r);
     if(MID<r) res+=querysum(u<<1|1,MID+1,R,l,r);
     return res;
 }
 
 inline int getsum(int x,int y)
 {
     int res=0;
     while(top[x]!=top[y])
     {
         if(dep[top[x]]<dep[top[y]]) swap(x,y);
         res+=querysum(1,1,tot,bh[top[x]],bh[x]);
         x=fa[top[x]];
     }
     if(bh[x]>bh[y]) swap(x,y);
     res+=querysum(1,1,tot,bh[x],bh[y]);
     return res;
 }
 
 inline int querymax(int u,int L,int R,int l,int r)
 {
     if(l<=L&&R<=r) return mx[u];
     int MID=(L+R)>>1,res=-INF;
     if(l<=MID) res=max(res,querymax(u<<1,L,MID,l,r));
     if(MID<r) res=max(res,querymax(u<<1|1,MID+1,R,l,r));
     return res;
 }
 
 inline int getmax(int x,int y)
 {
     int res=-INF;
     while(top[x]!=top[y])
     {
         if(dep[top[x]]<dep[top[y]]) swap(x,y);
         res=max(res,querymax(1,1,tot,bh[top[x]],bh[x]));
         x=fa[top[x]];
     }
     if(bh[x]>bh[y]) swap(x,y);
     
     res=max(res,querymax(1,1,tot,bh[x],bh[y]));
     return res; 
 }
 
 inline void updata(int u,int L,int R,int pos,int sp)
 {
     if(L==R) {mx[u]=sum[u]=sp;return;}
     int MID=(L+R)>>1;
     if(pos<=MID) updata(u<<1,L,MID,pos,sp);
     else updata(u<<1|1,MID+1,R,pos,sp);
     pushup(u);
 }
 
 inline void go()
 {
     scanf("%d",&qu);
     char str[10];int a,b;
     while(qu--)
     {
         scanf("%s%d%d",str,&a,&b);
         if(str[1]=='S') printf("%d\n",getsum(a,b));
         else if(str[1]=='M') printf("%d\n",getmax(a,b));
         else updata(1,1,tot,bh[a],b);
     }
 }
 
 int main()
 {
     read();
     go();
     return 0;
 } 