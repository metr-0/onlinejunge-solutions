#include <cstdio>

int main() {
	int TC;
	scanf("%d", &TC);
	
	while (TC--) {
		int sum, dif, l;
		scanf("%d %d", &sum, &dif);
		
		if (sum % 2 != dif % 2) {
			printf("impossible\n");
			continue;
		}
		
		l = (sum + dif) / 2;
		if (l > sum) {
			printf("impossible\n");
			continue;
		}
		
		printf("%d %d\n", l, sum - l);
	}
}
