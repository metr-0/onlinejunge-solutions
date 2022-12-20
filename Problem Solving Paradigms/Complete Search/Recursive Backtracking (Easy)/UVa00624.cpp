#include <cstdio>
#include <bitset>

using namespace std;

int A[25], N, tc, max_sum;
bitset<25> cur, res;

void backtrack(int k, int sum) {
	if (sum > N) return;
	if (k == tc) {
		if (sum > max_sum)
			max_sum = sum, res = cur;
		return;
	}
	
	cur[k] = true; backtrack(k + 1, sum + A[k]);
	cur[k] = false; backtrack(k + 1, sum);
}

int main() {
	while (scanf("%d %d", &N, &tc) != EOF) {
		for (int i = 0; i < tc; i++)
			scanf("%d", &A[i]);
		
		max_sum = -1;
		backtrack(0, 0);
		
		for (int i = 0; i < tc; i++) if (res[i])
			printf("%d ", A[i]);
		printf("sum:%d\n", max_sum);
	}
}
