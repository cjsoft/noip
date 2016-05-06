#include <ctime>
#include <cstdlib>
#include <cstdio>
int arr[10000001];
int buffer[10000001];
int *pool[10000001];
int tot = 0;
struct testcase {
    void read_data() {
        for (int i = 1; i < 10000001; ++i) {
            scanf("%d", arr + i);
        }
        
    }
    void start_the_test() {
        for (int i = 1; i < 10000001; ++i) {
            buffer[tot++] = arr[i];
        }
    }
    clock_t run() {
        start_the_test();
        return clock();
    }
} tc;

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    FILE *f = fopen("result3.txt", "w");
    tc.read_data();
    puts("data read");
    clock_t p = clock();
    fprintf(f, "%d\n", int(tc.run() - p));
    fclose(f);
    puts("done");
}