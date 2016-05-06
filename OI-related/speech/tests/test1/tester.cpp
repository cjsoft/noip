#include <ctime>
#include <cstdlib>
int arr[10000001];
int buffer[10000001];
int tot = 0;
struct testcase {
    void read_data() {
        for (int i = 1; i < 10000001; ++i) {
            scanf("%d", arr + i);
        }
    }
    void start_the_test() {

    }
    clock_t run() {
        start_the_test();
        return clock();
    }
} tc;

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    f = fopen("result.txt", "w");
    tc.read_data();
    puts("data read");
    clock_t p = clock();
    fprintf(f, "%d\n", int(tc.run() - p));
    fclose();
    puts("done");
}