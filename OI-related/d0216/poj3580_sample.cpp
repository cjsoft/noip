#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MAXM = 100005;
const int INF = 0x7fffffff;

class SplayTree
{
public:
    SplayTree()
    {
        nil.size = 0;
        nil.value = INF;
        nil.min = INF;
        nil.lchild = &nil;
        nil.rchild = &nil;
        nil.parent = &nil;
    }

    inline void make(int array[], int n)
    {
        nodeNumber = 0;
        int mid = (n - 1) >> 1;
        root = newNode(&nil, array[mid]);
        root->lchild = make(0, mid - 1, root, array);
        root->rchild = make(mid + 1, n - 1, root, array);
        update(root);
    }

    inline void ADD(int x, int y, int D)
    {
        find(x, &nil);
        find(y + 2, root);
        root->rchild->lchild->lazy += D;
    }

    inline void REVERSE(int x, int y)
    {
        find(x, &nil);
        find(y + 2, root);
        root->rchild->lchild->isReverse ^= true;
    }

    inline void REVOLVE(int x, int y, int T)
    {
        int len = y - x + 1;
        T = ((T % len) + len) % len;
        if(T)
        {
            find(y - T + 1, &nil);
            find(y + 2, root);
            SplayNode *d = root->rchild->lchild;
            root->rchild->lchild = &nil;
            find(x, &nil);
            find(x + 1, root);
            root->rchild->lchild = d;
            d->parent = root->rchild;
        }
    }

    inline void INSERT(int x, int P)
    {
        find(x + 1, &nil);
        find(x + 2, root);
        root->rchild->lchild = newNode(root->rchild, P);
    }

    inline void DELETE(int x)
    {
        find(x, &nil);
        find(x + 2, root);
        root->rchild->lchild = &nil;
    }

    inline void MIN(int x, int y)
    {
        find(x, &nil);
        find(y + 2, root);
        pushdown(root->rchild->lchild);
        printf("%d\n", root->rchild->lchild->min);
    }

    inline void print()
    {
        printf("Splay Linear: \n");
        print(root);
        printf("\n");
    }

    inline void prints()
    {
        printf("Splay Structure: \n");
        prints(root);
        printf("\n");
    }

private:
    struct SplayNode
    {
        int value, size, lazy;
        SplayNode *parent, *lchild, *rchild;
        int min;
        bool isReverse;
    } nil, node[MAXN + MAXM];
    int nodeNumber;
    SplayNode *root;

    inline SplayNode *newNode(SplayNode *parent, const int value)
    {
        node[nodeNumber].value = value;
        node[nodeNumber].size = 1;
        node[nodeNumber].lazy = 0;
        node[nodeNumber].parent = parent;
        node[nodeNumber].lchild = &nil;
        node[nodeNumber].rchild = &nil;
        node[nodeNumber].min = value;
        node[nodeNumber].isReverse = false;
        return &node[nodeNumber++];
    }

    SplayNode *make(int l, int r, SplayNode *parent, int array[])
    {
        if(l > r)
        {
            return &nil;
        }
        int mid = (l + r) >> 1;
        SplayNode *x = newNode(parent, array[mid]);
        x->lchild = make(l, mid - 1, x, array);
        x->rchild = make(mid + 1, r, x, array);
        update(x);
        return x;
    }

    inline void update(SplayNode *x)
    {
        if(x == &nil)
        {
            return;
        }
        x->size = x->lchild->size + x->rchild->size + 1;
        x->min = min(x->value, min(x->lchild->min, x->rchild->min));
    }

    inline void pushdown(SplayNode *x)
    {
        if(x == &nil)
        {
            return;
        }
        if(x->isReverse)
        {
            swap(x->lchild, x->rchild);
            x->lchild->isReverse ^= true;
            x->rchild->isReverse ^= true;
            x->isReverse = false;
        }
        if(x->lazy)
        {
            x->value += x->lazy;
            x->min += x->lazy;
            x->lchild->lazy += x->lazy;
            x->rchild->lazy += x->lazy;
            x->lazy = 0;
        }
    }

    inline void rotateLeft(SplayNode *x)
    {
        SplayNode *p = x->parent;
        pushdown(x->lchild);
        pushdown(x->rchild);
        pushdown(p->lchild);
        p->rchild = x->lchild;
        p->rchild->parent = p;
        x->lchild = p;
        x->parent = p->parent;
        if(p->parent->lchild == p)
        {
            p->parent->lchild = x;
        }
        else
        {
            p->parent->rchild = x;
        }
        p->parent = x;
        update(p);
        update(x);
        if(root == p)
        {
            root = x;
        }
    }

    inline void rotateRight(SplayNode *x)
    {
        SplayNode *p = x->parent;
        pushdown(x->lchild);
        pushdown(x->rchild);
        pushdown(p->rchild);
        p->lchild = x->rchild;
        p->lchild->parent = p;
        x->rchild = p;
        x->parent = p->parent;
        if(p->parent->lchild == p)
        {
            p->parent->lchild = x;
        }
        else
        {
            p->parent->rchild = x;
        }
        p->parent = x;
        update(p);
        update(x);
        if(root == p)
        {
            root = x;
        }
    }

    inline void splay(SplayNode *x, SplayNode *y)
    {
        pushdown(x);
        while(x->parent != y)
        {
            if(x->parent->parent == y)
            {
                if(x->parent->lchild == x)
                {
                    rotateRight(x);
                }
                else
                {
                    rotateLeft(x);
                }
            }
            else if(x->parent->parent->lchild == x->parent)
            {
                if(x->parent->lchild == x)
                {
                    rotateRight(x->parent);
                    rotateRight(x);
                }
                else
                {
                    rotateLeft(x);
                    rotateRight(x);
                }
            }
            else
            {
                if(x->parent->rchild == x)
                {
                    rotateLeft(x->parent);
                    rotateLeft(x);
                }
                else
                {
                    rotateRight(x);
                    rotateLeft(x);
                }
            }
        }
        update(x);
    }

    inline void find(int k, SplayNode *y)
    {
        SplayNode *x = root;
        pushdown(x);
        while(k != x->lchild->size + 1)
        {
            if(k <= x->lchild->size)
            {
                x = x->lchild;
            }
            else
            {
                k -= x->lchild->size + 1;
                x = x->rchild;
            }
            pushdown(x);
        }
        splay(x, y);
    }

    inline void print(SplayNode *x)
    {
        if(x == &nil)
        {
            return;
        }
        pushdown(x);
        print(x->lchild);
        printf("%d: %d %d %d %d\n", x->value, x->min, x->parent->value, x->lchild->value, x->rchild->value);
        print(x->rchild);
    }

    inline void prints(SplayNode *x)
    {
        if(x == &nil)
        {
            return;
        }
        pushdown(x);
        if(x->value == INF)
        {
            printf("INF : ");
        }
        else
        {
            printf("%d : ", x->value);
        }
        if(x->lchild == &nil)
        {
            printf("nil ");
        }
        else
        {
            if(x->lchild->value == INF)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", x->lchild->value);
            }
        }
        if(x->rchild == &nil)
        {
            printf("nil\n");
        }
        else
        {
            if(x->rchild->value == INF)
            {
                printf("INF\n");
            }
            else
            {
                printf("%d\n", x->rchild->value);
            }
        }
        prints(x->lchild);
        prints(x->rchild);
    }
} splayTree;

char buffer[128];int array[MAXN];int n, m;

int main()
{
    int x, y, D, T, P;
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d", &array[i]);
    }
    array[0] = INF;
    array[n+1] = INF;
    splayTree.make(array, n + 2);
    scanf("%d", &m);
    while(m--)
    {
        scanf("%s", buffer);
        switch(buffer[0])
        {
        case 'A':
            scanf("%d%d%d", &x, &y, &D);
            splayTree.ADD(x, y, D);
            break;
        case 'R':
            if('E' == buffer[3])
            {
                scanf("%d%d", &x, &y);
                splayTree.REVERSE(x, y);
            }
            else
            {
                scanf("%d%d%d", &x, &y, &T);
                splayTree.REVOLVE(x, y, T);
            }
            break;
        case 'I':
            scanf("%d%d", &x, &P);
            splayTree.INSERT(x, P);
            break;
        case 'D':
            scanf("%d", &x);
            splayTree.DELETE(x);
            break;
        case 'M':
            scanf("%d%d", &x, &y);
            splayTree.MIN(x, y);
            break;
        }
    }
    return 0;
}  