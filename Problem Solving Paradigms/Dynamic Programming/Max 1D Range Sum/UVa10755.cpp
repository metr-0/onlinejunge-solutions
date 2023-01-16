#include <cstdio>
#define MIN -9999999999999999

using ll = long long;

ll dp[23][23][23];

void solve() {
	int A, B, C; scanf("%d %d %d", &A, &B, &C);
	for (int z = 1; z <= A; z++) for (int y = 1; y <= B; y++) for (int x = 1; x <= C; x++) {
		scanf("%lld", &dp[z][y][x]);
		dp[z][y][x] += dp[z][y - 1][x] + dp[z][y][x - 1] - dp[z][y - 1][x - 1];
	}
	
	ll max = MIN;
	for (int y = 1; y <= B; y++) for (int x = 1; x <= C; x++)
		for (int i = y; i <= B; i++) for (int j = x; j <= C; j++) {
			ll t_max = MIN, cur = 0;
			for (int z = 1; z <= A; z++) {
				cur += dp[z][i][j] + dp[z][y - 1][x - 1] - dp[z][i][x - 1] - dp[z][y - 1][j];
				if (cur > t_max) t_max = cur;
				if (cur < 0) cur = 0;
			}
			if (t_max > max) max = t_max;
		}
	
	printf("%lld\n", max);
}

int main() {
	int TC; scanf("%d", &TC);
	while (TC--) {
		solve();
		if (TC) printf("\n");
	}
}
