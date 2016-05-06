#include<cstdio>
#include<cstring>
#define f(i,j,k) for(i=j;i<=k;++i)
#define d(i,j,k) for(i=j;i>=k;--i)
#define ln printf("\n")
#define sign printf("Here")

int n, c;
const int big = 1e9 + 7;
bool block[5010][5010];
int ans[5010][5010];


int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	
	scanf("%d %d", &n, &c);
	//if (!c) test1();
	//else
	if (n <= 10000)
	{
		int i, j, x, y;
		f(i, 1, c)
		{
			scanf("%d %d", &x, &y);
			block[x][y] = 1;
		}
		f(i, 0, n) if (!block[i][0]) ans[0][i] = 1;
		f(i, 1, n) f(j, i, n) if (!block[j][i])
			if (j == i) ans[i][j] = ans[i - 1][j]; else ans[i][j] = (ans[i - 1][j] + ans[i][j - 1]) % big;
		printf("%d\n", ans[n][n]);
		// f(i, 0, n){f(j, 0, n) printf("%5d ", ans[i][j]); ln;}
	}
	else printf("0\n");
	
	return 0;
}
