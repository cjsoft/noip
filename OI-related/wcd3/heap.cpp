#include <iostream>
#include <cstdio>

template <int SZ, typename T, T SMA>
class heap {
public:
  int size;
  int locator[SZ + 7], revlocator[SZ + 7];
  T data[SZ + 7];
  heap() {
    size = SZ;
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
    // printf("ab%d %d\n", a, b);
    // printf("bfsw %d %d %d %d\n", revlocator[a], revlocator[b], locator[revlocator[a]], locator[revlocator[b]]);
    std::swap(locator[revlocator[a]], locator[revlocator[b]]);
    std::swap(revlocator[a], revlocator[b]);
    std::swap(data[a], data[b]);
    // printf("afsw %d %d %d %d\n", revlocator[a], revlocator[b], locator[revlocator[a]], locator[revlocator[b]]);
  }
  void sink(int root) {
    int largest = root;
    while (root) {
      if (lson(root) <= SZ)
      if (data[largest] < data[lson(root)]) {
        largest = lson(root);
      }
      if (rson(root) <= SZ)
      if (data[largest] < data[rson(root)]) {
        largest = rson(root);
      }
      if (largest != root) {
        sw(root, largest);
        root = largest;
      } else {
        root = 0;
      }
    }
  }
  void swim(int root) {
    while (root) {
    // printf("aaaaaaaaaa %d\n", locator[revlocator[root]]);
      if (data[root] > data[parent(root)] && root > 1) {
        sw(root, parent(root));
        root = parent(root);
      } else {
        root = 0;
      }
    }
  }
  void heapify() {
    for (int i = SZ; i > 0; --i) {
      sink(i);
    }
  }
  void edit(int pos, T newd) {
    data[locator[pos]] = newd;
    printf("  %d\n", revlocator[locator[pos]]);
    sink(locator[pos]);
    printf("  %d\n", revlocator[locator[pos]]);
    swim(locator[pos]);
    printf("  %d\n", revlocator[locator[pos]]);
  }
  T extract() {
    T temp = data[1];
    data[1] = SMA;
    sw(1, size--);
    sink(1);
    return temp;
  }
};

int main() {
  heap<10, int, -99999> hp;
  for (int i = 1; i <= 10; ++i) {
    hp.data[i] = i;
  }
  // hp.data[10] = 999;
  hp.heapify();
  // for (int i = 1; i <= 10; ++i) {
  //   printf("%d\n", hp.locator[i]);
  // }
  hp.edit(7, 100);
  for (int i = 0; i < 10; ++i)
  {
    printf("%d\n", hp.extract());
  }
  return 0;
}
