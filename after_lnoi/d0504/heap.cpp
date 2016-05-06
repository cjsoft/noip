#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#define MXN 100007
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
#define parent(x) (x >> 1)
using namespace std;
int harr[MXN];
int locator[MXN], revlocator[MXN];
int size;
inline void hswap(int a, int b) {
    std::swap(harr[a], harr[b]);
    std::swap(locator[revlocator[a]], locator[revlocator[b]]);
    std::swap(revlocator[a], revlocator[b]);
}
inline void sink(int root) {
    int smallest;
    REDO:;
    if (root > size) return;
    smallest = root;
    if (lson(root) <= size && harr[lson(root)] < harr[smallest]) smallest = lson(root);
    if (rson(root) <= size && harr[rson(root)] < harr[smallest]) smallest = rson(root);
    if (smallest != root) {
        hswap(root, smallest);
        root = smallest;
        goto REDO;
    }
}
inline void swim(int root) {
    while (root > 1) {
        if (harr[root] < harr[parent(root)]) {
            hswap(root, parent(root));
            root = parent(root);
        } else return;
    }
}
inline void edit(int pos, int newdata) {
    harr[locator[pos]] = newdata;
    sink(locator[pos]);
    swim(locator[pos]);
}
inline int extract() {
    int resu = harr[1];
    hswap(1, size--);
    sink(1);
    return resu;
}
inline void add(int data) {
    harr[++size] = data;
    swim(locator[size]);
}
void init() {
    size = 0;
    for (int i = 0; i < MXN; ++i) {
        locator[i] = i;
        revlocator[i] = i;
    }
}
void init_from_array(int *begin, int *end) {
    init();
    while (begin != end) {
        harr[++size] = *begin++;
    }
    for (int i = size; i > 0; --i) {
        sink(i);
    }
} 
int main() {
    srand(int(time(0)));
    int q[MXN];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", q + i);
    }
    init_from_array(q, q + n);
    while (size) {
        printf("%d ", extract());
    }
    return 0;
}