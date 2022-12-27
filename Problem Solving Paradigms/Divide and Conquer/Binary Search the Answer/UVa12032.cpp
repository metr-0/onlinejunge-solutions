#include <cstdio>

int A[100000], N;

bool check(int k) {
	for (int i = 0; i < N; i++) {
		if (A[i] > k) return false;
		else if (A[i] == k) k--;
	}
	return true;
}

int main() {
	int TC; scanf("%d", &TC);
	
	for (int t = 1; t <= TC; t++) {
		scanf("%d", &N);
		
		int hi = -1, old = 0, temp;
		for (int i = 0; i < N; i++) {
			scanf("%d", &temp); A[i] = temp - old;
			if (A[i] > hi) hi = A[i];
			old = temp;
		}
		
		if (!check(hi)) hi++;
		
		printf("Case %d: %d\n", t, hi);
	}
}
