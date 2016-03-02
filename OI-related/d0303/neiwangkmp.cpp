#include <cstdio>
#include <cstring>
#include <vector>
typedef std::vector<bool> string;
typedef unsigned long long ull;
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define g(x, y, z) for(int x = (y); x < (z); ++x)

ull fib[100];
//fib[0] = 1, fib[1] = 0

inline ull work(const string &x, int n){
    if(n < 0) return 0;
    string y;
    int size = x.size();
    if(size == 1){
        if(x[0]) return fib[n + 1]; else return fib[n];
    }else{
        int i;
        for(i = 0; i < size - 1; ++i) if(x[i]){
            if(x[i + 1]) y.push_back(0);
            else y.push_back(1), ++i;
        }else if(i == 0) y.push_back(1);
        else return 0;
        if(x[size - 1]){
            y.push_back(0);
            ull ans = work(y, n - 1);
            y[y.size() - 1] = 1;
            return ans + work(y, n - 1);
        }else if(i == size) return work(y, n - 1);
        else return 0;
    }
}

char buf[100086];
int main(){
    fib[0] = 1; fib[1] = 0;
    f(i, 2, 99) fib[i] = fib[i - 1] + fib[i - 2];
    int n; scanf("%d", &n);
    gets(buf); gets(buf);
    int size = strlen(buf);
    string x; x.resize(size);
    g(i, 0, size) x[i] = buf[i] - '0';
    printf("%llu\n", work(x, n));
    return 0;
}
