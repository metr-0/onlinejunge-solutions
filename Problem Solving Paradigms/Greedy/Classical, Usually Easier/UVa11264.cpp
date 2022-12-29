#include <cstdio>

int A[1005];

int main() {
	int TC, N; scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		
		int sum = 0, count = 1;
		for (int i = 0; i < N - 1; i++)
			if (A[i] + sum < A[i + 1])
				sum += A[i], count++;
		
		printf("%d\n", count);
	}
}
