#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;
struct tinydeque {
    int data[200007];
    int head, tail;
    tinydeque() {
        head = tail = 0;
        memset(data,0,sizeof(data));
    }
    inline int size() {
        return tail - head;
    }
    inline int push(int x) {
        data[tail++] = x;
        if (tail == 200007) tail = 0;
    }
    inline int front() {
        return data[head];
    }
    inline int back() {
        return data[tail - 1];
    }
    inline int pop_front() {
        return data[head++];
        if (head == 200007) head = 0;
    }
    inline int pop_back() {
        return data[--tail];
    }
};
template <int SZ, typename T, T SMA>
class heap {
public:
  int size;
  int locator[SZ + 7], revlocator[SZ + 7];
  T data[SZ + 7];
  heap(int n) {
    size = n;
    for (int i = 1; i <= SZ; ++i) {
      locator[i] = revlocator[i] = i;
    }
  }
  inline int lson(int root) {
    return root << 1;
  }
  inline int rson(int root) {
    return root << 1 | 1;
  }
  inline int parent(int root) {
    return root >> 1;
  }
  void sw(int a, int b) {
    if (a == b) return;
    std::swap(locator[revlocator[a]], locator[revlocator[b]]);
    std::swap(revlocator[a], revlocator[b]);
    std::swap(data[a], data[b]);
  }
  void sink(int root) {
    int smallest = root;
    while (root) {
      if (lson(root) <= size)
      if (data[smallest] > data[lson(root)]) {
        smallest = lson(root);
      }
      if (rson(root) <= size)
      if (data[smallest] > data[rson(root)]) {
        smallest = rson(root);
      }
      if (smallest != root) {
        sw(root, smallest);
        root = smallest;
      } else {
        root = 0;
      }
    }
  }
  void swim(int root) {
    while (root) {
      if (data[root] < data[parent(root)] && root > 1) {
        sw(root, parent(root));
        root = parent(root);
      } else {
        root = 0;
      }
    }
  }
  void heapify() {
    for (int i = size; i > 0; --i) {
      sink(i);
    }
  }
  void edit(int pos, T newd) {
    data[locator[pos]] = newd;
    sink(locator[pos]);
    swim(locator[pos]);
  }
  T extract() {
    T temp = data[1];
    data[1] = SMA;
    sw(1, size--);
    sink(1);
    return temp;
  }
};


int pwr[100007];
int n;
int T;
int main() {
    scanf("%d", &T);
    while (T--) {
        memset(pwr,0,sizeof(pwr));
        scanf("%d", &n);
        heap<100007, int, INT_MAX> hp(n);
        tinydeque dq;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", pwr + i);
            hp.data[i] = pwr[i];
        }
        // puts("------------------------------------------");
        hp.heapify();
        int x, last = 1;
        char tag;
        while (hp.data[1] != INT_MAX) {
            x = hp.revlocator[1];
            // if (pwr[x] == 273947978)
            //     puts("safa");
             // printf("   %d %d\n",dq.size(), x);
            if (dq.size() == 0) {
                for (int i = last; i <= x; ++i) {
                    dq.push(pwr[i]);
                    hp.edit(i, INT_MAX);
                }
                last = x + 1;
            } else {
                if (pwr[x] < dq.front() && pwr[x] < dq.back()) {
                    for (int i = last; i <= x; ++i) {
                        dq.push(pwr[i]);
                        hp.edit(i, INT_MAX);
                    }
                    last = x + 1;
                } else if (pwr[x] > dq.front() && pwr[x] < dq.back()) {
                    printf("%d ", dq.pop_front());
                } else if (pwr[x] < dq.front() && pwr[x] > dq.back()) {
                    printf("%d ", dq.pop_back());
                } else if (pwr[x] > dq.front() && pwr[x] > dq.back()) {
                    if (dq.size() == 1) {
                        printf("%d ", dq.pop_back());
                    } else {
                        if (dq.back() < dq.front()) {
                            printf("%d ", dq.pop_back());
                        } else {
                            printf("%d ", dq.pop_front());
                        }
                        // printf("%d %d ", std::min(dq.front(), dq.back()), std::max(dq.front(), dq.back()));
                        // dq.pop_front();dq.pop_back();
                    }
                } //else if ()
            }
        }
        while (dq.size()) {
            if (dq.front() > dq.back()) {
                printf("%d ", dq.pop_back());
            } else {
                printf("%d ", dq.pop_front());
            }
        }
        putchar('\n');
    }
    return 0;
}
