#include <cstdio>

int A[1005], N, M;

bool check(int x) {
	int filled = 0, cap = x;
	for (int i = 0; i < N; i++) {
		if (A[i] > x) return false;
		if (A[i] > cap) {
			if (++filled == M) return false;
			cap = x;
		}
		cap -= A[i];
	}
	return true;
}

int main() {
	while (scanf("%d %d", &N, &M) != EOF) {
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		
		int lo = 0, hi = 1000000000, mid;
		while (lo != hi) {
			mid = (lo + hi) / 2;
			if (check(mid)) hi = mid;
			else lo = mid + 1;
		}
		
		printf("%d\n", hi);
	}
}
