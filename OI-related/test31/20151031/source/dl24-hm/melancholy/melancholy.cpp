#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define f(i,j,k) for(i=j;i<=k;++i)
#define d(i,j,k) for(i=j;i>=k;--i)
#define ln printf("\n")
#define sign printf("Here\n")

int n, q;
typedef std::pair<int, int> Pair;
typedef unsigned int ui;
Pair a[100010];
ui sub[100010];

int l[400010], r[400010], lson[400010], rson[400010], sumnode;
ui min[400010], sqsum[400010], sum[400010], s3sum[400010];

void build(int ll, int rr)
{
	int x = sumnode;
	l[x] = ll; r[x] = rr;
	if (ll == rr)
	{
		min[x] = sum[x] = a[ll].second;
		sqsum[x] = sum[x] * sum[x];
		s3sum[x] = sum[x] * sqsum[x];
	}
	else
	{
		int mid = (ll + rr) >> 1;
		lson[x] = ++sumnode;
		build(ll, mid);
		rson[x] = ++sumnode;
		build(mid + 1, rr);
		min[x] = std::min(min[lson[x]], min[rson[x]]);
		sqsum[x] = sqsum[lson[x]] + sqsum[rson[x]];
		s3sum[x] = s3sum[lson[x]] + s3sum[rson[x]];
		sum[x] = sum[lson[x]] + sum[rson[x]];
	}
}

ui askmin(int x, int ll, int rr)
{
	if (ll <= l[x] && rr >= r[x]) return min[x];
	ui min = 1e9 + 7;
	int mid = (l[x] + r[x]) >> 1;
	if (ll <= mid) min = std::min(min, askmin(lson[x], ll, rr));
	if (rr > mid) min = std::min(min, askmin(rson[x], ll, rr));
	return min;
}

ui asksqsum(int x, int ll, int rr)
{
	if (ll <= l[x] && rr >= r[x]) return sqsum[x];
	ui sum = 0;
	int mid = (l[x] + r[x]) >> 1;
	if (ll <= mid) sum += asksqsum(lson[x], ll, rr);
	if (rr > mid) sum += asksqsum(rson[x], ll, rr);
	return sum;
}

ui asks3sum(int x, int ll, int rr)
{
	if (ll <= l[x] && rr >= r[x]) return s3sum[x];
	ui sum = 0;
	int mid = (l[x] + r[x]) >> 1;
	if (ll <= mid) sum += asks3sum(lson[x], ll, rr);
	if (rr > mid) sum += asks3sum(rson[x], ll, rr);
	return sum;
}

ui test1(int l, int r)
{
	Pair x = std::make_pair(l, 0), y = std::make_pair(r, 1000000010);
	int i, pl = std::lower_bound(a + 1, a + n + 1, x) - a, pr = std::upper_bound(a + 1, a + n + 1, y) - a - 1;
	if (l >= r) return 0;
	return sub[pr] - sub[pl - 1] - askmin(1, pl, pr);
}

ui test2(int l, int r)
{
	Pair x = std::make_pair(l, 0), y = std::make_pair(r, 1000000010);
	int i, pl = std::lower_bound(a + 1, a + n + 1, x) - a, pr = std::upper_bound(a + 1, a + n + 1, y) - a - 1;
	if (r - l < 2) return 0;
	ui sum = sub[pr] - sub[pl - 1], min = askmin(1, pl, pr);
	return sum * sum - asksqsum(1, pl, pr) - 2 * (sum - min) * min;
}

ui test3(int l, int r)
{
	Pair x = std::make_pair(l, 0), y = std::make_pair(r, 1000000010);
	int i, pl = std::lower_bound(a + 1, a + n + 1, x) - a, pr = std::upper_bound(a + 1, a + n + 1, y) - a - 1;
	if (r - l < 3) return 0;
	ui sum = sub[pr] - sub[pl - 1], min = askmin(1, pl, pr), last = test2(l, r);
	return sum * sum * sum + 2 * asks3sum(1, pl, pr) - 3 * asksqsum(1, pl, pr) * sum - 3 * last * min;
}

int main()
{
	freopen("melancholy.in", "r", stdin);
	freopen("melancholy.out", "w", stdout);
	
	scanf("%d %d", &n, &q);
	int i, l, r, k;
	f(i, 1, n) scanf("%d", &a[i].first);
	f(i, 1, n) scanf("%d", &a[i].second);
	++sumnode;
	std::sort(a + 1, a + n + 1);
	f(i, 1, n) sub[i] = sub[i - 1] + a[i].second;
	build(1, n);
	f(i, 1, q)
	{
		scanf("%d %d %d", &l, &r, &k);
		if (k == 1) printf("%u\n", test1(l, r));
		else if (k == 2) printf("%u\n", test2(l, r));
		else if (k == 3) printf("%u\n", test3(l, r));
		else printf("233333\n");
	}
	
	return 0;
}
