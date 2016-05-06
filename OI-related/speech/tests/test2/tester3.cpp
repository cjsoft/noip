#include <ctime>
#include <cstdlib>
#include <cstdio>
int arr[10000001];
struct asd {
    asd *next;
    asd() {
        next = NULL;
    }
} *buffer[10000001];
int tot = 0;
struct testcase {
    void read_data() {
        for (int i = 1; i < 10000001; ++i) {
            scanf("%d", arr + i);
            buffer[i] = new asd();
        }

        for (int i = 1; i < 10000001; ++i) {
            buffer[i]->next = buffer[arr[i]];
        }
    }
    void start_the_test() {
        asd *a = buffer[1];
        for (int i = 1; i < 10000001; ++i) {
            a = a->next;
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