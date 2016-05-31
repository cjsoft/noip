#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500010
using namespace std;
struct use{int st,en;}e[N<<1];
int n,m,x,y,cnt,f[N][25],g[N][25],c[N][25],d,nxt[N<<1],point[N],w[N];
int read(){
  int x(0),f(1);
  char ch=getchar();
  while (ch<'0'||ch>'9') ch=getchar();
  while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
  return x;
}
void add(int x,int y){
  nxt[++cnt]=point[x];point[x]=cnt;
  e[cnt].st=x;e[cnt].en=y;
}
void dfs(int x,int fa){
  int fg(0); // fg，为0的话是叶子节点，否则为非叶节点
  for (int i=point[x];i;i=nxt[i])
    if (e[i].en!=fa){
      dfs(e[i].en,x);fg=1; // 向下dfs并更新fg
      for (int j=1;j<=d;j++)
        c[x][j]|=c[e[i].en][j-1]; // c[x][j]为1表示在此放守卫能够覆盖子树中距他距离为j的节点
                                  // 为0表示向下j步范围无需要覆盖的节点
    }
  if (!fg){ //判断是否是叶子节点，初始化叶子节点的dp数组
    g[x][0]=f[x][0]=w[x]*c[x][0];
    for (int i=1;i<=d;i++)
      g[x][i]=w[x],f[x][i]=0;
    return;
  }
  for (int i=1;i<=d;i++)
    for (int j=point[x];j;j=nxt[j])
      if(e[j].en!=fa)
        f[x][i]+=f[e[j].en][i-1]; // f[x][i]的其中一个数据源是$\sum_{v\,is\,a\,son\,of\,x}f[v][i-1]$
  for (int i=point[x];i;i=nxt[i])
    if (e[i].en!=fa)
      g[x][d]+=f[e[i].en][d]; // 显然$\sum_{v\,is\,a\,son\,of\,x}(f[v][d])+w[x]$不会比$\sum_{v\,is\,a\,son\,of\,x,d' < d}(f[v][d'])+w[x]$更大，所以先直接选他
  g[x][d]+=w[x];
  for (int i=d-1;i>=0;i--){
    int s(0);
    for (int j=point[x];j;j=nxt[j])
      if (e[j].en!=fa)
        s+=f[e[j].en][i]; // s为$\sum_{v\,is\,a\,son\,of\,x}f[v][i]$
    g[x][i]=g[x][i+1]; // $g[v][i+1]~~v\,is\,a\,son\,of\,x$
    for (int j=point[x];j;j=nxt[j])
      if (e[j].en!=fa)
        g[x][i]=min(g[x][i],g[e[j].en][i+1]+s-f[e[j].en][i]); //s中的数据保证是在从g[u][i+1]引用数据时最小的合法数据，加一起，最后扣除g[u][i+1]的那棵子树多算的f值
  }
  f[x][0]=g[x][0]; //由于f[x][0]无从f值的数据源，所以从g值取
  for (int i=1;i<=d;i++)
    f[x][i]=min(f[x][i],f[x][i-1]); //i更小的数据对于i大的数据是合法的，所以正着更新一遍
  for (int i=d-1;i>=0;i--)
    if (!c[x][i]) f[x][i]=min(f[x][i],f[x][i+1]); //倒着更新，从x向下i步无需要覆盖的节点的话，那么用x向下i+1步内所有需要覆盖的点都被覆盖的最优结果来更新当前f[x][i]
  g[x][0]=f[x][0]; //用倒着更新出的不差的值更新g[x][0]
}
int main(){
  scanf("%d%d",&n,&d);
  for (int i=1;i<=n;i++) scanf("%d",&w[i]);
  scanf("%d",&m);
  for (int i=1;i<=m;i++){
    scanf("%d",&x);
    c[x][0]=1;
  }
  for (int i=1;i<n;i++){
    scanf("%d%d",&x,&y);
    add(x,y);add(y,x);
  }
  dfs(1,0);
  printf("%d\n",f[1][0]);
} 