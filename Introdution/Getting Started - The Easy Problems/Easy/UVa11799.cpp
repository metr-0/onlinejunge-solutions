#include <cstdio>

int main() {
	int TC, CC, a, max;
	scanf("%d", &TC);
	
	for (int i = 1; i <= TC; i++) {
		max = 0;
		scanf("%d", &CC);
		
		while (CC--) {
			scanf("%d", &a);
			
			if (a > max)
				max = a;
		}
		
		printf("Case %d: %d\n", i, max);
	}
}
