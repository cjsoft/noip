#include <bits/stdc++.h>
using namespace std;

#define N 200005
#define mod 1000000007

long long fac[N], inv[N], f[N];
pair<int, int> p[N];
int n, c;

long long power(long long x, int y)
{
	long long re = 1;
	while (y)
	{
		if (y & 1) re = re * x % mod;
		y >>= 1; x = x * x % mod;
	}
	return re;
}

long long C(int m, int n)
{
	return fac[m] * inv[n] % mod * inv[m - n] % mod;
}

long long work(int x1, int y1, int x2, int y2)
{
	if (x2 < x1 || y2 < y1) return 0;
	return C(x2 + y2 - x1 - y1, x2 - x1);
}

long long calc(int x1, int y1, int x2, int y2)
{
	return (work(x1, y1, x2, y2) - work(x1, y1, y2 - 1, x2 + 1) + mod) % mod;
}

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	fac[0] = 1;
	for (int i = 1; i < N; ++i)
		fac[i] = fac[i - 1] * i % mod;
	inv[N - 1] = power(fac[N - 1], mod - 2);
	for (int j = N - 1; j > 0; --j)
		inv[j - 1] = inv[j] * j % mod;
	cin >> n >> c;
	for (int i = 1; i <= c; ++i)
		scanf("%d%d", &p[i].first, &p[i].second);
	p[++c].first = n; p[c].second = n;
	sort(p + 1, p + c + 1);
	for (int i = 1; i <= c; ++i)
	{
		f[i] = calc(0, 0, p[i].first, p[i].second);
		for (int j = 1; j < i; ++j)
			if (p[j].second <= p[i].second)
				f[i] = (f[i] - f[j] * calc(p[j].first, p[j].second, p[i].first, p[i].second) % mod + mod) % mod;
	}
	cout << f[c] << endl;
	return 0;
}
