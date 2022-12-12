#include <cstdio>
#include <map>

using mii = std::map<int, int>;

void solve()
{
	int SC;
	scanf("%d", &SC);
	
	mii snowflakes;
	
	int max = 0, start = 0, v, temp;
	for (int i = 0; i < SC; i++) {
		scanf("%d", &v);
		
		if (snowflakes.find(v) != snowflakes.end()) {
			temp = i - start;
			
			if (start < snowflakes[v] + 1)
				start = snowflakes[v] + 1;
			
			snowflakes[v] = i;
			
			if (temp > max) max = temp;
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

