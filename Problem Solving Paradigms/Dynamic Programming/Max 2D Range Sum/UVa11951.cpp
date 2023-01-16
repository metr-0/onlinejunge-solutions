#include <cstdio>

using ll = long long;

ll A[105][105];

void solve(int t) {
	int N, M, K; scanf("%d %d %d", &N, &M, &K);
	for (int y = 1; y <= N; y++) for (int x = 1; x <= M; x++) {
		scanf("%lld", &A[y][x]);
		A[y][x] += A[y - 1][x] + A[y][x - 1] - A[y - 1][x - 1];
	}
	
	ll min_sum = 0; int max_square = 0;
	for (int y = 1; y <= N; y++) for (int x = 1; x <= M; x++)
		for (int i = y; i <= N; i++) for (int j = x; j <= M; j++) {
			ll sum = A[i][j] + A[y - 1][x - 1] - A[y - 1][j] - A[i][x - 1];
			int square = (i - y + 1) * (j - x + 1);
			if (sum <= K && (square > max_square || (square == max_square && sum < min_sum)))
				max_square = square, min_sum = sum;
		}
	
	printf("Case #%d: %d %d\n", t, max_square, min_sum);
}

int main() {
	int TC; scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) solve(t);
}
