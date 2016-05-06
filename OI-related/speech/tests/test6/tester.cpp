#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;
int arr[100000000];
struct testcase {
    void read_data() {
        // int a;
        // for (int i = 1; i <= 1000000; ++i) {
        //     scanf("%d", &a);
        //     hp.data[i] = a;
        //     pq.push(a);
        // }
        // hp.heapify();
    }
    void start_the_test1() {
        fill_n(arr, 100000000, -1);

    }
    void start_the_test2() {
        memset(arr, 0, sizeof arr);
    }
    void start_the_test3() {
        for (int i = 0; i < 100000000; ++i) {
          arr[i] = -1;
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
    clock_t run3() {
        start_the_test3();
        return clock();
    }
} tc;

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    FILE *f = fopen("result.txt", "w");
    tc.read_data();
    puts("data read");
    clock_t p = clock();
    fprintf(f, "%d\n", int(tc.run1() - p));
    p = clock();
    fprintf(f, "%d\n", int(tc.run2() - p));
    p = clock();
    fprintf(f, "%d\n", int(tc.run3() - p));
    fclose(f);
    puts("done");
    while (1);
}