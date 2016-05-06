#include<cstdio>
#include<cstring>
#include<algorithm>
#define f(i,j,k) for(i=j;i<=k;++i)
#define d(i,j,k) for(i=j;i>=k;--i)
#define ln printf("\n")
#define sign printf("Here")

int n, m;
int a[100010], s[4];

struct pos
{
	int i, j, k;
	pos(int x = 100010, int y = 100010, int z = 100010)
	{
		i = x; j = y; k = z;
	}
	public: bool operator < (pos y)
	{
		if (k != y.k) return k < y.k;
		if (j != y.j) return k < y.j;
		return i < y.i;
	}
};

bool ok(int x, int y, int z)
{
	if (x + y <= z || x + z <= y || y + z <= x) return 0;
	return 1;
}

void ask()
{
	int i, j, k;
	pos min, now;
	f(i, 1, n - 2) f(j, i + 1, n - 1) f(k, j + 1, n) if (ok(a[i], a[j], a[k]))
	{
		now = pos(i, j, k);
		if (now < min) min = now;
	}
	s[0] = a[min.i]; s[1] = a[min.j]; s[2] = a[min.k];
	std::sort(s, s + 3);
	f(i, 0, 2) printf("%d ", s[i]); ln;
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	scanf("%d", &n);
	int i, j, x, y;
	f(i, 1, n) scanf("%d", a + i);
	scanf("%d", &m);
	f(i, 1, m)
	{
		scanf("%d", &j);
		if (j == 1)
		{
			scanf("%d %d", &x, &y);
			a[x] = y;
		}
		else ask();
	}
	
	return 0;
}
