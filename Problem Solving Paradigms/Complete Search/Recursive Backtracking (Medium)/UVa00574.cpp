#include <cstdio>
#include <bitset>

using namespace std;

int SUM, N, A[15], res[15];
bool f;

void backtrack(int j, int n, int sum) {
	if (sum > SUM) return;
	if (sum == SUM) {
		f = true;
		
		printf("%d", res[0]);
		for (int i = 1; i < n; i++)
			printf("+%d", res[i]);
		printf("\n");
		
		return;
	}
	
	bitset<1010> nums;
	for (int i = j; i < N; i++) if (!nums[A[i]]) {
		res[n] = A[i];
		backtrack(i + 1, n + 1, sum + A[i]);
		nums[A[i]] = true;
	}
}

int main()
{
	while (scanf("%d %d", &SUM, &N), N) {
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		f = false;
		
		printf("Sums of %d:\n", SUM);
		backtrack(0, 0, 0);
		if (!f) printf("NONE\n");
	}
}
