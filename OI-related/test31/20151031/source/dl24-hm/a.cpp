#include<cstdio>
#include<algorithm>

int a[10];

int main()
{
	int i, x;
	for (i = 1; i < 6; ++i) scanf("%d", a + i);
	scanf("%d", &x);
	printf("\n%d %d\n", std::lower_bound(a + 1, a + 6, x) - a, std::upper_bound(a + 1, a + 6, x) - a);
	return 0;
}