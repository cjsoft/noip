#include <iostream>
#include <cstdio>
#include <vector>
const int MAN = 100007;
int n, m;
std::vector<int> rawv[MAN];
std::vector<int> Stack;
char instack[MAN];
int low[MAN], dfn[MAN], locator[MAN], cnts[MAN], anotherCounter[MAN], yetAnotherTag[MAN];
int global_cnt = 0, global_cur = 0, cur = 0;
void tarjan(int root) {
    instack[root] = 1;
    dfn[root] = low[root] = ++cur;
    Stack.push_back(root);
    for (int i = 0; i < rawv[root].size(); ++i) {
        if (instack[rawv[root][i]] == 0) {
            tarjan(rawv[root][i]);
            low[root] = std::min(low[root], low[rawv[root][i]]);
        } else if(instack[rawv[root][i]] == 1) {
            low[root] = std::min(low[root], dfn[rawv[root][i]]);
        }
    }
    if (low[root] == dfn[root]) {
        global_cur++;
        int cnt  = 0;
        while (Stack.back() != root) {
            instack[Stack.back()] = 2;
            locator[Stack.back()] = global_cur;
            cnts[global_cur]++;
            Stack.pop_back();
            cnt++;
        }
        locator[Stack.back()] = global_cur;
        ++cnt;
        cnts[global_cur]++;
        Stack.pop_back();
        instack[root] = 2;
        if (cnt > 1) global_cnt++;
    }
}
void analyse() {
    int localcnt =  1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < rawv[i].size(); ++j) {
            if (locator[i] != locator[rawv[i][j]]) {
                anotherCounter[locator[i]] = 1;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int tempa, tempb;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &tempa, &tempb);
        rawv[tempa].push_back(tempb);
    }
    for (int i = 1; i <= n; ++i) {
        if (!instack[i]) {
            tarjan(i);
        }
    }
    printf("%d\n", global_cnt);
    analyse();
    bool print_tag = false;
    int anotherFXX = 0;
    for (int i = 1; i <= n; ++i) {
        if (!anotherCounter[locator[i]] && yetAnotherTag[locator[i]] == 0) ++anotherFXX;
        yetAnotherTag[locator[i]] = 1;
    }
    if (anotherFXX > 1) {
        puts("-1");
        return 0;
    } else {
        for (int i = 1; i <= n; ++i) {
            // printf(" %d %d\n", i, locator[i]);
            if (!anotherCounter[locator[i]]) {
                if (cnts[locator[i]] > 1) {
                    if (print_tag) putchar(' ');
                    print_tag = true;
                    printf("%d", i);
                }
            }
        }
        print_tag ? putchar('\n') : puts("-1"); 
    }
    return 0;
}