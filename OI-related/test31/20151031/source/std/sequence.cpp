#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
int n , m;
int a[N];
long long b[4];

int main()
{
	freopen("sequence.in","r",stdin); freopen("sequence.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	
	scanf("%d",&m);
	for(int i=1,type,x,y; i<=m; i++)
	{
		scanf("%d",&type);
		if (type == 1)
		{
			scanf("%d%d",&x,&y);
			a[x] = y;
		}
		else
		{
			bool ok = 0;
			for(int k3=3; k3<=n && !ok; k3++)
				for(int k2=2; k2<k3 && !ok; k2++)
					for(int k1=1; k1<k2 && !ok; k1++)
					{
						b[3] = a[k3];
						b[2] = a[k2];
						b[1] = a[k1];
						sort(b+1 , b+4);
						if (b[1] + b[2] > b[3])
						{
							printf("%I64d %I64d %I64d\n",b[1],b[2],b[3]);
							ok = 1;
						}
					}
			if(!ok) puts("-1 -1 -1");
		}
	}
	
	return 0;
}