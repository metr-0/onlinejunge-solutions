#include <cstdio>

using namespace std;

int A[25], t[15], towers[15][25], v[15];

int count(int n) {
	int res = 0;
	for (; n; res++)
		n &= (n - 1);
	return res;
}

void solve(int P, int B) {
	for (int i = 0; i < P; i++)
		scanf("%d", &A[i]);
	
	int M; scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &t[i]);
		for (int j = 0; j < t[i]; j++)
			scanf("%d", &towers[i][j]), towers[i][j]--;
		scanf("%d", &v[i]);
		for (int j = 0; j < t[i]; j++)
			A[towers[i][j]] -= v[i];
	}
	
	int max_sum = -1, max_n;
	for (int n = 0; n < (1 << P); n++) {
		if (count(n) != B) continue;
		
		int sum = 0;
		for (int i = 0; i < P; i++)
			if (n & (1 << i)) sum += A[i];
		
		for (int i = 0; i < M; i++)
			for (int j = 0; j < t[i]; j++)
				if (n & (1 << towers[i][j])) {
					sum += v[i]; break;
				}
		
		if (sum > max_sum)
			max_sum = sum, max_n = n;
		else if (sum == max_sum)
			for (int i = 0; i < P; i++) {
				bool a = n & (1 << i), b = max_n & (1 << i);
				if (a && !b) {
					max_sum = sum, max_n = n;
					break;
				} else if (!a && b) break;
			}
	}
	
	printf("Number of Customers: %d\n", max_sum);
	printf("Locations recommended:");
	for (int i = 0; i < P; i++)
		if (max_n & (1 << i))
			printf(" %d", i + 1);
	printf("\n\n");
}

int main() {
	int c = 1, P, B;
	
	while (scanf("%d %d", &P, &B), P || B) {
		printf("Case Number  %d\n", c++);
		solve(P, B);
	}
}
