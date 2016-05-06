#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 6;
const int K = 7;

typedef pair<int, int> PI;

struct rc
{
	unsigned s[K];
	
	void set(int x)
	{
		s[1] = x;
		for(int i=2; i<K; i++) s[i]=s[i-1]*s[1];
	}
	
	int cal(int k)
	{
		if(k==1) return s[1];
		if(k==2) return s[1]*s[1] - s[2];
		if(k==3) return s[1]*s[1]*s[1] - 3*s[1]*s[2] + 2*s[3];
		if(k==4) return s[1]*s[1]*s[1]*s[1] - 6*s[1]*s[1]*s[2] + 8*s[1]*s[3] + 3*s[2]*s[2] - 6*s[4];
		if(k==5) return s[1]*s[1]*s[1]*s[1]*s[1] - 10*s[1]*s[1]*s[1]*s[2] + 20*s[1]*s[1]*s[3] + 15*s[1]*s[2]*s[2]
		-30*s[1]*s[4] - 20*s[2]*s[3] + 24*s[5];
		return s[1]*s[1]*s[1]*s[1]*s[1]*s[1] - 15*s[1]*s[1]*s[1]*s[1]*s[2] + 40*s[1]*s[1]*s[1]*s[3]
		+ 45*s[1]*s[1]*s[2]*s[2] - 90*s[1]*s[1]*s[4] - 120*s[1]*s[2]*s[3] - 15*s[2]*s[2]*s[2] + 144*s[1]*s[5]
		+ 90*s[2]*s[4] + 40*s[3]*s[3] - 120*s[6];
	}
};

rc operator+(rc a, rc b)
{
	rc p;
	for(int i=1; i<K; i++) p.s[i] = a.s[i] + b.s[i];
	return p;
}

rc operator-(rc a, rc b)
{
	rc p;
	for(int i=1; i<K; i++) p.s[i] = a.s[i] - b.s[i];
	return p;
}

rc f[N<<2];
int g[N<<2];

int n, q;
PI a[N];
int d[N], v[N];

rc opf;
int opl, opr, opg;

void build(int x, int l, int r)
{
	if(l==r) { f[x].set(v[l]), g[x]=v[l]; return; }
	int mid = (l+r) >> 1;
	build(x+x, l, mid), build(x+x+1, mid+1, r);
	f[x] = f[x+x] + f[x+x+1], g[x] = min(g[x+x], g[x+x+1]);
}

void query(int x, int l, int r)
{
	if(opl <= l && r <= opr){ opf = opf + f[x], opg = min(opg, g[x]); return; }
	int mid = (l+r) >> 1;
	if(opl <= mid) query(x+x, l, mid);
	if(opr > mid) query(x+x+1, mid+1, r);
}

int main()
{
	freopen("melancholy.in", "r", stdin);
	freopen("melancholy.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; i++) scanf("%d", &a[i].first);
	for(int i=1; i<=n; i++) scanf("%d", &a[i].second);
	
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) d[i] = a[i].first, v[i] = a[i].second;
	build(1, 1, n);
	
	for(int i=1, l, r, k; i<=q; i++)
	{
		scanf("%d%d%d", &l, &r, &k);
		opl = lower_bound(d+1, d+n+1, l) - d;
		opr = upper_bound(d+1, d+n+1, r) - d - 1;
		opf.set(0), opg = 1e9 + 7;
		if(opl <= opr)
		{
			query(1, 1, n);
			f[0].set(opg), opf = opf - f[0];
			printf("%u\n", opf.cal(k));
		}
		else puts("0");
	}
	
	return 0;
}
