#include <cstdio>
#include <cmath>

void solve()
{
	int i, d, k, c[25];
	
	scanf("%d", &i);
	for (int j = 0; j <= i; j++)
		scanf("%d", &c[j]);
	scanf("%d %d", &d, &k);
	
	double D = 1 + (8 * (double)k) / (double)d;
	long long n = ceil((-1 + sqrt(D)) / 2), res = 0;
	
	for (int j = 0; j <= i; j++)
		res += c[j] * pow(n, j);
	
	printf("%lld\n", res);
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) solve();
}
