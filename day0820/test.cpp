#include<cstdlib>
#include<cstring>
#include <iostream>
#include<cstdio>
using namespace std;
const int N = 60000;
struct node
{
     int v,rest,cap;
     node *next;
};

node *adj[N],*rec[N];
node list[500000];
int   d[N],que[N];
int cnt ,inf = (1<<31)-1 ;

inline node *reverse(node *p)
{   
    return   list + ((p-list)^1);
}
inline void insert(int u,int v,int cap)
{
        node *p = &list[cnt++];
        p ->v = v;p ->cap = cap;
        p ->next = adj[u];adj[u] = p;
        
        p = &list[cnt++];
        p ->v = u; p->cap = 0;
        p ->next = adj[v];adj[v] = p;
}

bool   bfs(int s,int t,int n) 
{
       int i,j;
       int head = 0,tail =1;
       fill(d,d+n+1,-1);
       d[t] = n;
       que[0] = t;
       while(head < tail)
       {
                  int u = que[head++];
                  for(node *p=adj[u]; p ; p=p->next)
                  {
                           int v = p->v;
                           if( reverse( p )->rest >0 && d[v] == -1)
                           {
                               d[p->v] = d[u] - 1;
                               if(p->v == s) return 1;
                               que[tail++] = v;
                           }
                  }
       }
       return 0;
}
int   dfs(node *p ,int flow ,int t)
{
      if(p->rest < flow) flow = p->rest;
      int inc = 0;
      if(p->v == t)   inc = flow;
      else
      {
          for(node *ptr =adj[p->v] ; ptr && inc < flow; ptr=ptr->next)
          {
                   if(ptr->rest >0 && d[ptr->v] > d[p->v])
                      inc += dfs(ptr,flow-inc,t);
          }
      }
      p ->rest -= inc;
      reverse(p) ->rest +=inc;
      return inc;
}
int   dinic(int s, int t ,int n)
{
      int   i;
      for(i=0;i<cnt;i++)
          list[i].rest = list[i].cap;
      int   maxflow = 0;
      while( bfs(s,t,n) )
      {
             int flow = 0;
             for(node *p = adj[s];p;p=p->next)
             {
                      if(p->rest > 0 && d[p->v] > d[s])
                           flow += dfs(p,inf,t);
             }
             maxflow += flow;
      }
      return maxflow;
}
int main()
{
  freopen("test.in","r",stdin);
  freopen("test.out","w",stdout);
      int n,m,i,j,c;
      int u,v,w;
      while(scanf("%d%d",&n,&m)!=EOF)
      {
           cnt = 0;
           int sum = 0;
           memset(adj,0,sizeof(adj));
           
           for(i=0;i<n;i++)
           {
               scanf("%d",&c);
               insert(0,i+1,c);
           }
           for(i=0;i<m;i++)
           {
              scanf("%d%d%d",&u,&v,&w);
              sum += w;
              insert(n+i+1,m+n+1,w);
              insert(u,n+i+1,inf);
              insert(v,n+i+1,inf);
           }
           printf("%d\n",sum - dinic(0,m+n+1,m+n+2));
      }
      return 0;
}