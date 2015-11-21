# 图论  
## 树链剖分  
***

> 一句话，通过一种略微有些贪心思想的hash方法，把树上节点散列到一段连续区间上。  
> 通过某个节点的SCC（为该节点后代节点个数 + 1）值来确定他父亲的大胖儿子，连续的大胖儿子在散列区间上是连续的，在处理连续大胖儿子的维护上，我们可以用其他数据结构例如BIT或者ST或者SegTree这种工具来加速我们对树上信息的维护过程。

### 一些名词  
**SCC**:该节点后代节点个数 + 1  
**大胖儿子**:某节点SCC最大的儿子就是他的大胖儿子  
**小瘦儿子**:某节点SCC不是最大的儿子就是他的小瘦儿子。换言之，这个节点的儿子除了大胖儿子之外，其他所有儿子都是小瘦儿子  
**深度**:不解释  
**爸爸**:不解释  
**重链**：相互之间深度连续的且具有亲缘关系的大胖儿子  
**轻链**：不是重链的链，这里探讨它的意义不大，因为轻链的长度最多不会超过两个节点  
**散列值**:某个节点在被散列到的连续区间上的位置  
**反向散列值**:某个散列值所对应的原节点（的节点号）*不是必须的*  
**重链头**：某条重链中深度最小的大胖儿子  

### 一些重要性质  
1. 由定义得一个节点的大胖儿子只有一个  
2. 一条重链只会有一个重链头  
<br/><br/>

***
### 正文  
***
![](http://7xlxce.com1.z0.glb.clouddn.com/15-11-21/88346935.jpg)  
#### 1. 精髓的前二分之一   
1. 首先，我们要知道所有节点的**SCC**、**大胖儿子**、**深度**、**爸爸**都是啥，这个通过一次dfs可以搞出来。为了同我写过的代码风格一致，建议使老祖宗也就是根节点的爸爸为0而不是他自己。  
*代码见下文[附录](#fulu)的dfs_1*  
2. 通过第二次dfs算出每个节点的散列值和反向散列值，以及重链头。
    1. 为当前节点分配散列值，并保存反向散列值。顺序增加就好（就是1、2、3、4…）  
    2. 对儿子们进行dfs，**注意，一定要优先对大胖儿子进行dfs**，大胖儿子的重链头就是他爸爸的重链头。剩下的小瘦儿子dfs顺序随意，他们的重链头是他们自己  

**树剖的精髓的二分之一已经学会了！、**  


然后利用散列值或者反向散列值乱搞（例如对线段钩进行初始化建钩操作 *雾*）  
***
#### 2. 精髓的后二分之一


树剖的另一半精髓是树上操作和查询的快速乱搞，大概的核心思想是利用重链在散列区间上的连续特性进行加速优化  


**例如**，给定一棵树，求任意两点间节点（包括这两个点）的权值和  
我们就可以在处理这两个节点时利用求和线段钩直接求出重链上节点的权值和，将结果合并即可。  

如果需要单节点修改权值的话直接利用散列值在线段钩上修改即可。  
如果需要双节点间（包括这两个节点）的权值加减或者全部修改成某个指定值，方法与查询类似，对每一条重链进行修改即可。  

##### 如何合并重链？
例如给定两个节点，我们要对其间的所有重链进行某一操作或查询。
设节点分别为l, r  

有函数
```c++
depth(x);   //返回节点深度
head(x);    //返回节点重链头
fa(x);      //返回节点爸爸
locator(x); //返回节点的散列值
```

1. 当head(l) != head(r)即两节点不处在同一重链上时，进行下列操作  
    1. 我们找depth(head(x))值较大，即重链头深度较大的那个点，使它为l，另一个为r（相当于swap）。
    2. 利用locator(x)找到重链在散列区间上的位置，使用线段钩或其他结构对这段区间进行操作或查询。如果是查询的话注意合并查询结果。
    3. 使l = fa(head(l))
2. 此时l和r在同一条重链上，再次对这条**重链上的l和r节点（包括l和r）所构成的区间**进行相同的操作或查询（如果你的结构不支持自动将操作查询的区间l，r normalize的话，注意使locator(x)较小的节点的locator值作为区间左界，另一个作为右界，不然容易RE）  

***  

<span id='fulu' />

### 附录
[ZJOI 2008 树的统计](http://codevs.cn/problem/2460/)  

```c++
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define CLEAR(x) memset(x,0,sizeof(x))
const int MXN=30007;
using namespace std;
typedef long long ll;
int n;
struct edge
{
    int to;
    edge(int a) {
        to = a;
    }
};
std::vector <int> v[MXN];
int nodeweight[MXN];
int c_sub_nodes[MXN];
int fa[MXN];
int h_son[MXN];
int head[MXN];
int dep[MXN];
int locator[MXN];
int revlocator[MXN];
int tot = 1;
void dfs_1(int root, int from, int depth) {
    if (!from) {
        fa[root] = 0;
    } else {
        fa[root] = from;
    }
    dep[root] = depth;
    c_sub_nodes[root] = 1;
    h_son[root] = 0;
    for (int i = 0; i < v[root].size(); ++i) {
        if (v[root][i] == from) continue;
        dfs_1(v[root][i], root, depth + 1);
        c_sub_nodes[root] += c_sub_nodes[v[root][i]];
        if (c_sub_nodes[v[root][i]] >= c_sub_nodes[h_son[root]]) {
            h_son[root]=v[root][i];
        }
    }
}
void dfs_2(int root, int hd) {
    locator[root] = tot;
    revlocator[tot++] = root;
    head[root] = hd;
    if (h_son[root]) {
        dfs_2(h_son[root], hd);
    }
    for (int i = 0; i < v[root].size(); ++i) {
        if (v[root][i] == h_son[root] || v[root][i] == fa[root]) continue;
        dfs_2(v[root][i], v[root][i]);
    }
}
struct RMQ_QJH_XDS
{
    ll stree_rmq[MXN * 4 + 7];
    ll stree_qjh[MXN * 4 + 7];
    RMQ_QJH_XDS() {
        fill(stree_rmq, stree_rmq + MXN * 4 + 7, - 1e9);
        fill(stree_qjh, stree_qjh + MXN * 4 + 7, 0);
    }
    inline int lson(int root) {
        return root << 1 ;
    }
    inline int rson(int root) {
        return root << 1 | 1 ;
    }
    void build(int root, int l, int r) {
        if (l == r) {
            stree_rmq[root] = nodeweight[revlocator[l]];
            stree_qjh[root] = nodeweight[revlocator[l]];
            return ;
        }
        int m = (l + r) >> 1;
        build(lson(root), l, m);
        build(rson(root), m + 1, r);
        stree_rmq[root] = std::max(stree_rmq[lson(root)], stree_rmq[rson(root)]);
        stree_qjh[root] = stree_qjh[lson(root)] + stree_qjh[rson(root)];
    }
    ll rmq_query(int root, int l, int r, int queryl, int queryr) {
        if (queryl > queryr) std::swap(queryl, queryr);
        if (queryl > r || queryr < l) return - 1e9;
        if (queryl <= l && queryr >= r) return stree_rmq[root];
        int m = (l + r) >> 1;
        return std::max(rmq_query(lson(root), l, m, queryl, queryr), rmq_query(rson(root), m + 1, r, queryl, queryr));
    }
    ll qjh_query(int root, int l, int r, int queryl, int queryr) {
        if (queryl > queryr) std::swap(queryl, queryr);
        if (queryl > r || queryr < l) return 0;
        if (queryl <= l && queryr >= r) return stree_qjh[root];
        int m = (l + r) >> 1;
        return qjh_query(lson(root), l, m, queryl, queryr) + qjh_query(rson(root), m + 1, r, queryl, queryr);
    }
    void edit(int root, int l, int r, int pos, ll new_data) {
        if (l == r) {
            stree_qjh[root] = new_data;
            stree_rmq[root] = new_data;
            return ;
        }
        if (pos > ((l + r) >> 1)) {
            edit(rson(root), ((l + r) >> 1) + 1, r, pos, new_data);
        } else {
            edit(lson(root), l, (l + r) >> 1, pos, new_data);
        }
        stree_rmq[root] = std::max(stree_rmq[lson(root)],stree_rmq[rson(root)]);
        stree_qjh[root] = stree_qjh[lson(root)] + stree_qjh[rson(root)];
    }
} slpf;
ll tree_rmq_query(int l, int r) {
    ll resu = - 1e9;
    while (head[l] != head[r]) {
        if (dep[head[l]] < dep[head[r]]) std::swap(l, r);
        resu = max(resu, slpf.rmq_query(1, 1, tot - 1, locator[head[l]], locator[l]));
        l = fa[head[l]];
    }
    if (locator[l] > locator[r]) std::swap(l, r);
    resu = max(resu, slpf.rmq_query(1, 1, tot - 1, locator[l], locator[r]));
    return resu;
}
ll tree_qjh_query(int l, int r) {
    ll resu = 0;
    while (head[l] != head[r]) {
        if (dep[head[l]] < dep[head[r]]) std::swap(l, r);
        resu += slpf.qjh_query(1, 1, tot - 1, locator[head[l]], locator[l]);
        l = fa[head[l]];
    }
    if (locator[l] > locator[r]) std::swap(l, r);
    resu += slpf.qjh_query(1, 1, tot - 1, locator[l], locator[r]);
    return resu;
}
int main() {
    CLEAR(nodeweight);
    CLEAR(c_sub_nodes);
    CLEAR(fa);
    CLEAR(h_son);
    CLEAR(head);
    CLEAR(dep);
    CLEAR(locator);
    CLEAR(revlocator);
    scanf("%d", &n);
    int tempa, tempb;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &tempa, &tempb);
        v[tempa].push_back(tempb);
        v[tempb].push_back(tempa);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nodeweight[i]);
    }
    head[1] = 1;
    dfs_1(1, 0, 1);
    dfs_2(1, 1);
    slpf.build(1, 1, tot - 1);
    int q;
    char tc[11];
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        CLEAR(tc);
        scanf("%s %d %d", tc, &tempa, &tempb);
        if (tc[1] == 'M') {
            ll asd = tree_rmq_query(tempa, tempb);
            printf("%lld\n", asd);
        } else if (tc[1] == 'S') {
            printf("%lld\n", tree_qjh_query(tempa, tempb));
        } else {
            slpf.edit(1, 1, tot - 1, locator[tempa], tempb);
            nodeweight[tempa] = tempb;
        }
    }
}
```