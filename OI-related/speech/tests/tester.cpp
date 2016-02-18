#include <ctime>
#include <cstdlib>

struct testcase {
    void read_data() {

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
    freopen("test.out", "w", stdout);
    tc.read_data();
    clock_t p = clock();
    printf("%d\n", int(tc.run() - p));
}