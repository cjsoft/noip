#include<cstdio>
#include<cstring>
#include<algorithm>
#define fe first
#define se second

using namespace std;

typedef pair<int,int> P;

const int MAXM = 1005,MAXN = 200015,Mo = int(1e9) + 7;

P Block[MAXM];
int Fc[MAXN],Rv[MAXN],F[MAXN],N,C;

int Quick(int a,int b)
{
	if (!b) return 1;
	int mid = Quick(a,b >> 1);
	if (b & 1) return mid * 1ll * mid % Mo * a % Mo;
	return mid * 1ll * mid % Mo;
}

int Getc(int n,int m)
{
	if (m > n) return 0;
	return Fc[n] * 1ll * Rv[m] % Mo * Rv[n - m] % Mo;
}

int Normal(int s,int t,int x,int y)
{
	if (x < s || y < t) return 0;
	return Getc(x + y - s - t,x - s);
}

int Walk(int s,int t,int x,int y)
{
	return (Normal(s,t,x,y) - Normal(s,t,y - 1,x + 1) + Mo) % Mo;
}

int main()
{
	freopen("walk.in","r",stdin),freopen("walk.out","w",stdout);
	scanf("%d%d", &N, &C);
	Fc[0] = 1;
	for(int i = 1;i <= N * 2 + 5;i ++) Fc[i] = Fc[i - 1] * 1ll * i % Mo;
	Rv[N * 2 + 5] = Quick(Fc[N * 2 + 5], Mo - 2);
	for(int i = N * 2 + 5;i;i --) Rv[i - 1] = Rv[i] * 1ll * i % Mo;
	for(int i = 1;i <= C;i ++) scanf("%d%d", &Block[i].fe, &Block[i].se);
	Block[++ C] = P(N,N);
	sort(Block + 1,Block + C + 1);
	for(int i = 1;i <= C;i ++)
	{
		F[i] = Walk(0,0,Block[i].fe,Block[i].se);
		for(int j = 1;j < i;j ++)
		if (Block[j].se <= Block[i].se)
			F[i] = (F[i] - F[j] * 1ll * Walk(Block[j].fe,Block[j].se,Block[i].fe,Block[i].se) % Mo + Mo) % Mo;
	}
	printf("%d\n", F[C]);
	return 0;
}

