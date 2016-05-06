#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <string>
typedef long long ll;

using namespace std;

int r,c;
char mp[100][100];
int directions[1001];
int cnt;
int sr,sc;
int fr[100],fc[100];
int itmp;
bool tag[100][100][1001];
struct cc
{
    short r,c,d;
    cc(short rr,short cc,short dd){
        r=rr;c=cc;d=dd;
    }
    cc(){
        r=c=d=0;
    }
};
template <class _T>
class cqueue
{
private:
    unsigned int maxsize;
    unsigned int size_;
    bool empty_;
public:
    unsigned int pfront,pback;
    _T* data;
    cqueue(unsigned int stdsize){
        maxsize=stdsize;
        data=new _T[stdsize];
        memset(data,0,sizeof(data));
        pfront=pback=0;
        empty_=true;
        size_=0;
    }
    unsigned int inc(unsigned int &a){
        if(++a>=maxsize){
            a=0;
            return 0;
        }else{
            return a;
        }
    }
    bool push(_T resdata){
        if(size_==maxsize)
            return false;
        if(empty_){
            data[pback]=resdata;
            empty_=false;
            ++size_;
            return true;
        }else{
            data[inc(pback)]=resdata;
            ++size_;
            return true;
        }
    }
    _T pop(){
        _T aaa;
        if(empty_){
            printf("ERR,this cqueue is empty.\n");
            return aaa;
        }
        --size_;
        if(pfront==pback){
            empty_=true;
            return data[pfront];
        }
        unsigned int tempp=pfront;
        inc(pfront);
        return data[tempp];
    }
    _T back() const{
        if(empty_){
            printf("ERR,this cqueue is empty.\n");
            return (_T)0;
        }
        return data[pback];
    }
    _T front() const{
        if(empty_){
            _T aaa;
            printf("ERR,this cqueue is empty.\n");
            return aaa;
        }
        return data[pfront];
    }
    unsigned int size(){
        return size_;
    }
    bool empty(){
        return empty_;
    }
    ~cqueue(){
        delete[] data;
    }
};
cqueue<cc> q(20000);
void wfs();
int main(int argc, char const *argv[])
{
    memset(mp,0,sizeof(mp));
    memset(tag,false,sizeof(tag));
    cin>>r>>c;
    bool tag=false;
    for (int i = 0; i < r; ++i)
    {
        cin>>mp[i];
        if(!tag)
            for (int j = 0; j < c; ++j)
            {
                if(mp[i][j]=='*'){
                    sr=i;sc=j;
                    mp[i][j]='.';
                    tag=true;
                }
            }
    }
    cin>>cnt;
    string temp;
    for (int i = 0; i < cnt; ++i)
    {
        cin>>temp;
        if(temp=="NORTH")
            directions[i]=1;
        else if(temp=="SOUTH")
            directions[i]=2;
        else if(temp=="WEST")
            directions[i]=3;
        else
            directions[i]=4;
    }
    q.push(cc(sr,sc,0));
    wfs();
    return 0;
}

void wfs(){
    short td=0,tr,tc;
    while(!q.empty()){
        td=q.front().d;
        tr=q.front().r;tc=q.front().c;
        q.pop();
        tag[tr][tc][td]=false;
        if(td==cnt){
            mp[tr][tc]='*';
            continue;
        }
        if(directions[td]==1){
            if(mp[tr-1][tc]!='X' && tr-1>=0){
                //qr.push(tr-1);qc.push(tc);
                //qd.push(td);
                //cout<<"asfaew"<<tag[tr-1][tc][td]<<' ';
                if(!tag[tr-1][tc][td]){
                    q.push(cc(tr-1,tc,td));
                    tag[tr-1][tc][td]=true;
                }
                //qr.push(tr-1);qc.push(tc);
                //qd.push(td+1);
                if(!tag[tr-1][tc][td+1]){
                    q.push(cc(tr-1,tc,td+1));
                    tag[tr-1][tc][td+1]=true;
                }
            }
        }else if(directions[td]==2){
            if(mp[tr+1][tc]!='X' && tr+1<r){
                //qr.push(tr+1);qc.push(tc);
                //qd.push(td);
                if(!tag[tr+1][tc][td]){
                    q.push(cc(tr+1,tc,td));
                    tag[tr+1][tc][td]=true;
                }
                //qr.push(tr+1);qc.push(tc);
                //qd.push(td+1);
                if(!tag[tr+1][tc][td+1]){
                    q.push(cc(tr+1,tc,td+1));
                    tag[tr+1][tc][td+1]=true;
                }
            }
        }else if(directions[td]==3){
            if(mp[tr][tc-1]!='X' && tc-1>=0){
                //qr.push(tr);qc.push(tc-1);
                //qd.push(td);
                if(!tag[tr][tc-1][td]){
                    q.push(cc(tr,tc-1,td));
                    tag[tr][tc-1][td]=true;
                }
                //qr.push(tr);qc.push(tc-1);
                //qd.push(td+1);
                if(!tag[tr][tc-1][td+1]){
                    q.push(cc(tr,tc-1,td+1));
                    tag[tr][tc-1][td+1]=true;
                }
            }
        }else if(directions[td]==4){
            if(mp[tr][tc+1]!='X' && tc+1<c){
                //qr.push(tr);qc.push(tc+1);
                //qd.push(td);
                if(!tag[tr][tc+1][td]){
                    q.push(cc(tr,tc+1,td));
                    tag[tr][tc+1][td]=true;
                }
                //qr.push(tr);qc.push(tc+1);
                //qd.push(td+1);
                if(!tag[tr][tc+1][td+1]){
                    q.push(cc(tr,tc+1,td+1));
                    tag[tr][tc+1][td+1]=true;
                }
            }
        }else{
            cout<<"Critical Error."<<endl;
        }
    }
    for (int i = 0; i < r; ++i)
    {
        cout<<mp[i]<<endl;
    }
}