#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n, m, a[N];
vector<pair<int, int> > v;

bool check(int x, int y, int z)
{
	if (y < x) swap(x, y);
	if (z < x) swap(x, z);
	if (z < y) swap(y, z);
	if (x + y > z)
		{ printf("%d %d %d\n", x, y, z); return true; }
	return false;
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if (a[i] != 0 && v.size() <= 1050)
			v.push_back(make_pair(i, a[i]));
	}
	cin >> m;
	for (int x, y, opt, i = 1; i <= m; ++i)
	{
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d%d", &x, &y);
			if (x > (v.end() - 1)->first) continue;
			if (a[x] && y != 0)
				lower_bound(v.begin(), v.end(), make_pair(x, a[x]))->second = y;
			else if (a[x] && y == 0)
				v.erase(lower_bound(v.begin(), v.end(), make_pair(x, a[x])));
			else if (!a[x] && y != 0)
				v.insert(upper_bound(v.begin(), v.end(), make_pair(x, 0)), make_pair(x, y));
			a[x] = y;
		}
		else
		{
			for (int i = 2; i < min((int)v.size(), 50); ++i)
				for (int j = 1; j < i; ++j)
					for (int k = 0; k < j; ++k)
						if (check(a[i], a[j], a[k]))
							goto next;
			puts("-1 -1 -1");
			next:;
		}
	}
	return 0;
}
