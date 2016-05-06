#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
const int SIZE=100006;
struct edge
{
    int to;
    ll weight;
    edge *next;
}egs[2*SIZE+17];
edge *head[SIZE+17];
int tot=0;
void add(int a,int b,int c){
    egs[tot].to=b;
    egs[tot].next=head[a];
    egs[tot].weight=c;
    head[a]=egs+tot++;
}
struct node
{
    int id;
    ll key;
    node(){
        key=-INT_MAX;
    }
    /*bool operator<(const node &b)const{
        return key<b.key;
    }
    bool operator>(const node &b)const{
        return key>b.key;
    }
    bool kequals(const node &b)const{
        return key==b.key;
    }*/
}priq[SIZE+17];
int n,m,size;
int locator[SIZE+17];
inline int lson(int x){
    return x<<1;
}
inline int rson(int x){
    return x<<1|1;
}
inline int parent(int x){
    return x>>1;
}

void nswap(int a,int b){
    locator[priq[b].id]=a;
    locator[priq[a].id]=b;
    swap(priq[a],priq[b]);
}

int sink(int x){
    int minn=x;
    ST:
    if(lson(x)<=size && priq[lson(x)].key>priq[minn].key){
        minn=lson(x);
    }
    if(rson(x)<=size && priq[rson(x)].key>priq[minn].key){
        minn=rson(x);
    }
    if(minn!=x){
        nswap(x,minn);
        x=minn;
        goto ST;
    }else{
        return x;
    }
}

int swim(int x){
    while(x>1 && priq[x].key>priq[parent(x)].key){
        nswap(x,parent(x));
        x=parent(x);
    }
    return x;
}

node extract(){
    nswap(1,size);
    --size;
    sink(1);
    return priq[size+1];
}

int edit(int x,ll newkey){
    if(newkey==priq[x].key)
        return x;
    if(newkey<priq[x].key){
        priq[x].key=newkey;
        return sink(x);
    }else{
        priq[x].key=newkey;
        return swim(x);
    }
}

ll frd[5007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    size=n;
    for (int i = 1; i <= n; ++i) {
        cin >> frd[i];
    }
    for(int i=1;i<=n;++i){
        locator[i]=i;
        priq[i].id=i;
    }
    priq[1].key=0;
    
    ll total=0;node tn;
    while(size){
        tn=extract();
        total+=tn.key;
        for (int i = 1; i <= n; ++i) {
            if (i == tn.id) continue;
            if (locator[i]<=size && (frd[tn.id] & frd[i])>priq[locator[i]].key) {
                edit(locator[i], frd[tn.id] & frd[i]);
            }
        }
    }
    cout<<total<<endl;
    return 0;
}