#include <iostream>
#include <cstdio>
using namespace std;

class List{
public:
    struct Node
    {
        Node *next,*prev;
        int data;
    }HEAD;

    List(){
        HEAD.data=0;
        HEAD.next=&HEAD;
        HEAD.prev=&HEAD;
    }

    void initListForYSFQ(int n){
        Node *temp=&HEAD;
        HEAD.data=1;
        for (int i = 2; i <=n; ++i){
            temp->next=new Node;
            temp->next->prev=temp;
            temp->next->next=&HEAD;
            temp->next->data=i;
            HEAD.prev=temp->next;
            temp=temp->next;
        }
    }

    void test(){
        Node *temp=(&HEAD);
        for (int i = 0; i < 20; ++i)
        {

            // cout<<(temp->data)<<endl;
            temp=temp->next;
        }
    }

    void Kill(int m){
        Node *temp=(&HEAD);
        while(temp->next!=temp){
            for (int i = 0; i < m-2; ++i){
                temp=temp->next;
            }
            // cout<<(temp->next->data)<<endl;
            temp->next->next->prev=temp;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        cout<<(temp->data)<<endl;
    }
    void Clear(Node *tgt){
        if(!tgt)
            return;
        if(tgt->next!=&HEAD && tgt->next->next!=tgt){
            Clear(tgt->next);
        }
        if(tgt!=&HEAD)
            delete tgt;
    }
}a[307];
int tot=0;
int main(){
    int n,m;
    while(1){
        cin>>n>>m;
        if(n==0 && m==0)break;
        a[tot].initListForYSFQ(n);
        // a.test();
        a[tot++].Kill(m);
    }
    return 0;
}