#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

struct edge {
    edge *prev;
    int to, w;
} egs[], *head[];