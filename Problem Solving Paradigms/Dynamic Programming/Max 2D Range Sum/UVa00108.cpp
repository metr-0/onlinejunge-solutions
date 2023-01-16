#include <cstdio>

int A[105][105];

int main() {
	int N; scanf("%d", &N);
	for (int y = 1; y <= N; y++) for (int x = 1; x <= N; x++) {
		scanf("%d", &A[y][x]);
		A[y][x] += A[y - 1][x] + A[y][x - 1] - A[y - 1][x - 1];
	}
	
	int max = -999999999;
	for (int y = 1; y <= N; y++) for (int x = 1; x <= N; x++)
		for (int i = y; i <= N; i++) for (int j = x; j <= N; j++) {
			int cur = A[i][j] + A[y - 1][x - 1] - A[y - 1][j] - A[i][x - 1];
			if (cur > max) max = cur;
		}
	
	printf("%d\n", max);
}
