#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
#include <climits>
using namespace std;
map<int, int> mp;

struct testcase {
    void read_data() {
        
    }
    void start_the_test1() {
        int a, b;
        for (int i = 0; i < 1000000; ++i) {
            scanf("%d %d", &a, &b);
            mp.insert(make_pair(a, b));
        }
    }
    void start_the_test2() {
        int a;
        for (int i = 0; i < 1000000 / 3; ++i) {
            scanf("%d", &a);
            mp.find(a);
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
    FILE *f = fopen("result2.txt", "w");
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