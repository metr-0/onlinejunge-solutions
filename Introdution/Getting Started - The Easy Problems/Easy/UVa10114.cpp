#include <cstdio>

int func(int d, float a, float debt, int RC)
{
	int m, curr_m;
	float x, cost, curr_x, c;
	
	cost = debt + a;
	c = debt / d;
	debt += c;
	
	scanf("%d %e", &curr_m, &curr_x);
	RC--;
	
	while (RC--) {
		scanf("%d %e", &m, &x);
		
		for (; curr_m < m; curr_m++) {
			cost *= 1.f - curr_x;
			debt -= c;
			
			if (debt < cost)
				return curr_m;
		}
		
		curr_x = x;
	}
	
	for (; curr_m < d; curr_m++) {
		cost *= 1.f - curr_x;
		debt -= c;
		
		if (debt < cost)
			return curr_m;
	}
	
	return d;
}

int main()
{
	int d, RC, res;
	float a, debt;
	
	while (scanf("%d %e %e %d", &d, &a, &debt, &RC), d > 0) {
		res = func(d, a, debt, RC);
		
		if (res == 1)
			printf("1 month\n");
		else
			printf("%d months\n", res);
	}
}
