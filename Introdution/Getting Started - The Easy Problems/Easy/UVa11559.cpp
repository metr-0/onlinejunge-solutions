#include <cstdio>

int main()
{
	int n, budget, HC, WC, p, a, min, cost;
	bool f;
	
	while (scanf("%d %d %d %d", &n, &budget, &HC, &WC) != EOF) {
		min =  500010;
		
		while (HC--) {
			scanf("%d", &p);
			
			f = false;
			for (int i = 0; i < WC; i++) {
				scanf("%d", &a);
				if (a >= n)
					f = true;
			}
			
			if (f && p < min)
				min = p;
		}
		
		cost = min * n;
		if (cost > budget)
			printf("stay home\n");
		else
			printf("%d\n", cost);
	}
}
