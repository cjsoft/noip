#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int PTS = 10;
int curr = 0;
struct node {
  char current_char, c2;
  node *next[10];
  node() {
    current_char = c2 = 0;
  }
} buffer[300007], root;
node *nne = buffer;
bool insert(const char res[]) {
  int pos = 0;
  int len = strlen(res);
  node *cur = &root;
  while (res[pos]) {
    if (pos == len - 1 && cur->next[res[pos] - 48]) return false;
    if (!cur->next[res[pos] - 48]) {
      cur->next[res[pos] - 48] = nne++;
      cur->next[res[pos] - 48]->c2 = 0;
    }
    if (cur->next[res[pos] - 48]->c2 == 1) return false;
    cur = cur->next[res[pos] - 48];
    pos++;
  }
  cur->c2 = 1;
  return true;
}

char ttt[10007][17];
int main() {
  int t, a;
  char temp[17];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &a);
    memset(buffer, 0, sizeof(buffer));
    memset(root.next, 0, sizeof(root.next));
    nne = buffer;
    for (int i = 0; i < a; ++i) {
      scanf("%s", ttt[i]);
    }
    for (int i = 0; i < a; ++i) {
      if (!insert(ttt[i])) {
        puts("NO");
        goto NXT;
      }
    }
    puts("YES");
    NXT:;
  }
  return 0;
}
