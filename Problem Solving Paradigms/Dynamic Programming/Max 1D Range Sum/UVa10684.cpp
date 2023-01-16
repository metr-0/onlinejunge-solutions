#include <cstdio>

int main() {
	int N;
	while (scanf("%d", &N), N) {
		int sum = 0, max = 0;
		for (int i = 0; i < N; i++) {
			int a; scanf("%d", &a); sum += a;
			if (sum < 0) sum = 0;
			else if (sum > max) max = sum;
		}
		if (max) printf("The maximum winning streak is %d.\n", max);
		else printf("Losing streak.\n");
	}
}
