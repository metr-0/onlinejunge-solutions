#include <cstdio>

int s, d, ss[8], max_sum;

void backtrack(int sum, int i) {
	if (i >= 5 && ss[i - 5] >= 0) return;
	
	if (i == 12) {
		if (sum > max_sum) max_sum = sum;
		return;
	}
	
	int start = i < 5 ? 0 : i - 4, end = i > 6 ? 7 : i;
	
	for (int j = start; j <= end; j++) ss[j] += s;
	backtrack(sum + s, i + 1);
	for (int j = start; j <= end; j++) ss[j] -= s + d;
	backtrack(sum - d, i + 1);
	for (int j = start; j <= end; j++) ss[j] += d;
}

int main() {
	while (scanf("%d %d", &s, &d) != EOF) {
		max_sum = -1;
		for (int i = 0; i < 8; i++)
			ss[i] = 0;
		backtrack(0, 0);
		
		if (max_sum < 0) printf("Deficit\n");
		else printf("%d\n", max_sum);
	}
}
