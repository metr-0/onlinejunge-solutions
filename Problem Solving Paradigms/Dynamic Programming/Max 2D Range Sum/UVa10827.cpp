#include <cstdio>

int N, A[155][155];

void solve() {
	scanf("%d", &N);
	for (int y = 1; y <= N; y++) for (int x = 1; x <= N; x++) {
		scanf("%d", &A[y][x]);
		A[y + N][x] = A[y][x + N] = A[y + N][x + N] = A[y][x];
	}
	
	for (int y = 1; y <= 2 * N; y++) for (int x = 1; x <= 2 * N; x++)
		A[y][x] += A[y - 1][x] + A[y][x - 1] - A[y - 1][x - 1];
	
	int max = -999999999;
	for (int y = 1; y <= N; y++) for (int x = 1; x <= N; x++)
		for (int i = y; i < y + N; i++) for (int j = x; j < x + N; j++) {
			int cur = A[i][j] + A[y - 1][x - 1] - A[y - 1][j] - A[i][x - 1];
			if (cur > max) max = cur;
		}
	printf("%d\n", max);
}

int main() {
	int TC; scanf("%d", &TC);
	while (TC--) solve();
}
