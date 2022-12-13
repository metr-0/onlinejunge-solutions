#include <cstdio>
#include <bitset>

std::bitset<1000000005> f;
int *snowflakes = new int[1000000005];

void solve()
{
	int SC;
	scanf("%d", &SC);
	
	f.reset();
	
	int max = 0, start = 0, v, temp;
	for (int i = 0; i < SC; i++) {
		scanf("%d", &v);
		
		if (f[v]) {
			temp = i - start;
			
			if (start < snowflakes[v] + 1)
				start = snowflakes[v] + 1;
			
			if (temp > max) max = temp;
		} else {
			f[v] = true;
		}
		
		snowflakes[v] = i;
	}
	
	temp = SC - start;
	if (temp > max) max = temp;
	
	printf("%d\n", max);
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) solve();
}

