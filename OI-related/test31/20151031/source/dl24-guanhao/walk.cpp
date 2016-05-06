#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int p = 1e9 + 7;

int map[5009][5009];
int sum;

int dfs(int x, int y){
	return 0;
}

int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	memset(map, 0, sizeof(map));
	int N, C;
	scanf("%d%d", &N, &C);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j){
			if (i == j) map[i][j] = 1;
			if (i > j) map[i][j] = 2;
		}
	for (int i = 1; i <= N; ++i)
		map[N][i] = 1;
	sum = 0;
	int x = dfs(1, 1);
	return 0;
}