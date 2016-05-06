#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
int tot = 1;
priority_queue<int, vector<int>, greater<int> >pq; 
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
heap <1000001, int, -1> hp(1000000);
struct testcase {
    void read_data() {
        int a;
        for (int i = 1; i <= 1000000; ++i) {
            scanf("%d", &a);
            hp.data[i] = a;
            pq.push(a);
        }
        hp.heapify();
    }
    void start_the_test1() {
        for (int i = 0; i < 1000001; ++i) {
            hp.extract();
        }
    }
    void start_the_test2() {
        for (int i = 0; i < 1000001; ++i) {
            pq.pop();
        }
    }
    clock_t run1() {
        start_the_test1();
        return clock();
    }
    clock_t run2() {
        start_the_test2();
        return clock();
    }
} tc;

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    FILE *f = fopen("result.txt", "w");
    tc.read_data();
    puts("data read");
    clock_t p = clock();
    fprintf(f, "%d\n", int(tc.run1() - p));
    p = clock();
    fprintf(f, "%d\n", int(tc.run2() - p));
    fclose(f);
    puts("done");
    while (1);
}