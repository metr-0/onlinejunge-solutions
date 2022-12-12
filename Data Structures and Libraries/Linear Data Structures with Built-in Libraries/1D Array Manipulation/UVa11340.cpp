#include <cstdio>
#include <cstring>

int main()
{
	int TC;
	scanf("%d\n", &TC);
	
	while (TC--) {
		int PC;
		scanf("%d\n", &PC);
		char c;
		
		double costs[130];
		memset(costs, 0, sizeof(costs));
		
		while (PC--) {
			c = getchar();
			double p;
			scanf("%lf\n", &p);
			costs[c] = p;
		}
		
		int SC;
		double sum = 0;
		scanf("%d\n", &SC);
		
		char buf[10010];
		while (SC--) {
			gets(buf);
			for (int i = 0; buf[i] != '\0'; i++)
				if (buf[i] >= 0 && buf[i] < 130)
					sum += costs[buf[i]];
		}
		
		printf("%.2lf$\n", sum / 100.);
	}
}
