#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <cstring>
#include <climits>
std::stack <int> st;
struct testcase {
    void read_data() {

    }
    void start_the_test() {
        char sss[5];
        for (int i = 1; i < 10000001; ++i) {
            memset(sss, 0, sizeof(sss));
            scanf("%s", sss);
            if (sss[1] == 'u') {
                st.push(INT_MAX);
            } else {
                st.pop();
            }
        }
    }
    clock_t run() {
        start_the_test();
        return clock();
    }
} tc;

using namespace std;

int main() {
    freopen("../test.in", "r", stdin);
    FILE *f = fopen("result2.txt", "w");
    tc.read_data();
    puts("data read");
    clock_t p = clock();
    fprintf(f, "%d\n", int(tc.run() - p));
    fclose(f);
    puts("done");
    while (1);
}