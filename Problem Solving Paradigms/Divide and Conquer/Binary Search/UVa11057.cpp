#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, A[10005];
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		sort(A, A + N);
		
		int sum, ans, *last = A + N; scanf("%d", &sum);
		for (int i = 0; i < N - 1; i++) {
			int temp = sum - A[i];
			auto bound = lower_bound(A + i + 1, last, temp);
			if (bound != last && *bound == temp)
				ans = A[i], last = bound;
		}
		
		printf("Peter should buy books whose prices are %d and %d.\n\n", ans, *last);
	}
}
