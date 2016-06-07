#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define CSZ 26
#define MXN 100007
struct node {
    node *c[CSZ], *fail, *suffix_link;
    int count, dep;
    node() {
        memset(c, 0, sizeof(c));
        fail = suffix_link = NULL;
        dep = count = 0;
    }
} buf[MXN], *root, _root, *cur;
inline void init() {
    root = &_root;
    cur = buf;
}
inline node *newnode(node *parent) {
    cur->dep = parent->dep + 1;
    return cur++;
}
void insert(char *s) {
    node *p = root;
    while (*s) {
        if (p->c[*s - 'a'] == NULL) p->c[*s - 'a'] = newnode(p);
        p = p ->c[*s - 'a'];
        ++s;
    }
    p->count++;
}
void construct_ACautomaton() {
    std::queue<node*> q;
    root->fail = root;
    root->suffix_link = root;
    q.push(root);
    while (!q.empty()) {
        for (int i = 0; i < CSZ; ++i) {
            if (q.front()->c[i] != NULL) {
                if (q.front() == root) q.front()->c[i]->fail = root;
                else {
                    node *p = q.front()->fail;
                    for (; p->c[i] == NULL && p != root; p = p->fail);
                    q.front()->c[i]->fail = p->c[i] ? p->c[i] : root;
                }
                q.front()->c[i]->suffix_link = q.front()->c[i]->fail->count ? q.front()->c[i]->fail : q.front()->c[i]->fail->suffix_link;
                q.push(q.front()->c[i]);
            } else {
                if (q.front() == root) q.front()->c[i] = root;    // 直接把fail指针接到c上，一视同仁
                else q.front()->c[i] = q.front()->fail->c[i];     //
            }
        }
        q.pop();
    }
}
void print(int a, node *p) {
    printf("%d\n", a - p->dep + 1);
    if (p->suffix_link != root)
        print(a, p->suffix_link);
}
void find(char raw[]) {
    int l = strlen(raw);
    node *p = root;
    for (int i = 0; i < l; ++i) {
        int s = raw[i] - 'a';
        p = p->c[s];
        if (p->count)
            print(i, p);
        else if (p->suffix_link != root)
            print(i, p->suffix_link);
    }
}
char pattern[5][87];
int main() {
    init();
    scanf("%s\n%s", pattern[0], pattern[1]);
    insert(pattern[0]);
    insert(pattern[1]);
    construct_ACautomaton();
    scanf("%s", pattern[2]);
    find(pattern[2]);
    return 0;
}