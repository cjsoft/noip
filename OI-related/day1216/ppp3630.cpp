#include <iostream>
#include <cstdio>
#include <cstring>
struct node {
    char status;
    node *next[10];
    node() {
        memset(next, 0, sizeof(next));
        status = 0;
    }
    void init() {
        memset(next, 0, sizeof(next));
        status = 0;
    }
};
const int SZ = 300007;
struct trie {
    node *buffer;
    node root;
    node *cursor;
    trie() {
        buffer = new node[300007];
        memset(buffer, 0, sizeof(buffer));
        cursor = buffer;
    }
    ~trie() {
        delete[] buffer;
    }
    bool insert(const char res[]) {
        node *c = &root;
        int i = 0;
        int len = strlen(res);
        while (res[i]) {
            if (i == len - 1 && c->next[res[i] - 48]) return false;
            if (!c->next[res[i] - 48]) {
                c->next[res[i] - 48] = cursor;
                (cursor++)->status = 0;
            }
            if (c->next[res[i] - 48]->status == 1) return false;
            c = c->next[res[i] - 48];
            ++i;
        }
        c->status = 1;
        return true;
    }
};
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, tag = 0;
        char temp[11];
        trie t;
        memset(temp, 0, sizeof(temp));
        scanf("%d", &n);
        while (n--) {
            scanf("%s", temp);
            if (!t.insert(temp)) tag = 1;
        }
        if (tag) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
}