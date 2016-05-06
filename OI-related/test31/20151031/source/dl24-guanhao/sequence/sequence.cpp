#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int A[100009],tmp[3];

int check(int a, int b, int c){
	if (a + b <= c) return 0;
	if (a + c <= b) return 0;
	if (b + c <= a) return 0;
	return 1;
}

void type(int a, int b, int c){
	tmp[0] = a; tmp[1] = b; tmp[2] = c;
	sort(tmp, tmp + 3);
	printf("%d %d %d\n", tmp[0], tmp[1], tmp[2]);
	return ;
}

int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &A[i]);
	scanf("%d", &m);
	for (int t = 1; t <= m; ++t){
		int op;
		scanf("%d", &op);
		if (op == 1){
			int x, y;
			scanf("%d%d", &x, &y);
			A[x] = y;
		}
		if (op == 2){
			int can = 0;
			for (int k = 3; k <= n; ++k){
				if (can) break;
				else for (int j = 2; j <= k - 1; ++j){
					if (can) break;
					else if (A[k] == A[j]) continue;
					else for (int i = 1; i <= j - 1; ++i){
						if (A[i] == A[j]) continue;
						else if (check(A[i], A[j], A[k])){
							type(A[i], A[j], A[k]);
							can = 1;
							break;
						}
					}
				}
			}		
			if (!can) printf("-1 -1 -1\n");
		}
	}
	return 0;
}