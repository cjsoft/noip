#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define N 100005
#define lson (pos << 1)
#define rson (pos << 1 | 1)

unsigned int v[N], mint[N * 4], sum[N * 4];
int n, q, d[N];
pair<int, int> p[N];

void build(int pos, int l, int r)
{
	if (l == r) { mint[pos] = sum[pos] = p[l].second; return; }
	int mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	mint[pos] = min(mint[lson], mint[rson]);
	sum[pos] = sum[lson] + sum[rson];
}

unsigned int querysum(int pos, int l, int r, int x, int y)
{
	if (x <= l && r <= y) { return sum[pos]; }
	int mid = (l + r) >> 1; unsigned int re = 0;
	if (x <= mid) re += querysum(lson, l, mid, x, y);
	if (y > mid) re += querysum(rson, mid + 1, r, x, y);
	return re;
}

unsigned int querymin(int pos, int l, int r, int x, int y)
{
	if (x <= l && r <= y) { return mint[pos]; }
	int mid = (l + r) >> 1; unsigned int re = 0xffffffff;
	if (x <= mid) re = min(re, querymin(lson, l, mid, x, y));
	if (y > mid) re = min(re, querymin(rson, mid + 1, r, x, y));
	return re;
}

int main()
{
	freopen("melancholy.in", "r", stdin);
	freopen("melancholy.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &d[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%u", &v[i]), p[i] = make_pair(d[i], v[i]);
	sort(p + 1, p + n + 1);
	build(1, 1, n);
	for (int l, r, k, i = 1; i <= q; ++i)
	{
		scanf("%d%d%d", &l, &r, &k);
		l = lower_bound(p + 1, p + n + 1, make_pair(l, 0)) - p;
		r = lower_bound(p + 1, p + n + 1, make_pair(r + 1, 0)) - 1 - p;
		if (r < l) continue;
		if (r - l + 1 <= k) { printf("0\n"); continue; }
		printf("%u\n", querysum(1, 1, n, l, r) - querymin(1, 1, n, l, r));
	}
	return 0;
}
