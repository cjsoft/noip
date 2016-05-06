#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int D[100009], V[100009];
vector<int> vt;
vector<int> vt1;

long long p1 = 1 << 30;
long long p = p1 + p1 + p1 + p1;

int sz;

long long sum3;

int js(int n){
	int ans = 1;
	for (int i = 1; i <= n; ++i)
		ans *= i;
	return ans;
}

void cal(int i, int j, int k){
	long long t;
	t = vt1[i] * vt1[j] * vt1[k];
	//cout << t << endl;
	sum3 += t;
	sum3 %= p;
	//cout << i << " " << j << " " << k << endl;
	//cout << sum3 << endl;
	if (k == sz && j == (sz - 1) && i == (sz - 2))
		return ;
	else if (k == sz && j == (sz - 1)){
		i ++;
		j = i + 1;
		k = j + 1;
	}
	else if (k == sz){
		j ++;
		k = j + 1;
	}
	else k ++;
	cal(i, j, k);
}

int main(){
	freopen("melancholy.in", "r", stdin);
	freopen("melancholy.out", "w", stdout);
	int N, Q;
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &D[i]);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &V[i]);
	for (int t = 1; t <= Q; ++t){
		int L, R, K;
		scanf("%d%d%d", &L, &R, &K);
		vt.clear();
		int min = 1e9+7;
		for (int i = 1; i <= N; ++i)
			if (D[i] >= L && D[i] <= R){
				vt.push_back(V[i]);
				if (V[i] < min) min = V[i];
			}
		vt1.clear();
		for (int i = 0; i < vt.size(); ++i)
			if (vt[i] > min) vt1.push_back(vt[i]);
		if (vt1.size() < K){
			printf("0\n");
		}
		else if (K == 1){
			long long sum = 0;
			for (int i = 0; i < vt1.size(); ++i){
				sum += vt1[i];
				sum %= p;
			}
			printf("%lld\n", sum);
		}
		else if (K == 2){
			long long ans = js(vt1.size() - 1);
			long long sum = 0;
			for (int i = 0; i < vt1.size() - 1; ++i)
				for (int j = i + 1; j < vt1.size(); ++j){
					sum += vt1[i] % p * vt1[j] % p;
					sum %= p;
				}
			ans *= sum % p;
			printf("%lld\n", ans);
		}
		else if (K == 3){
			long long ans = js(vt1.size() - 1);
			long long sum = 0;
			sz = vt1.size() - 1;
			//cout << "sz = " << sz << endl;
			sum3 = 0;
			cal(0, 1, 2);
			ans *= sum3 % p;
			printf("%lld\n", ans);
		}
	}
	return 0;
}