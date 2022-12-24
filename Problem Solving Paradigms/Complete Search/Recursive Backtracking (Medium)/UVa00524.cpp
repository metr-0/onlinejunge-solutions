#include <cstdio>
#include <bitset>

using namespace std;

bitset<35> is_prime, is_used;
int N, answer[20];

void slieve() {
	is_prime.set();
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < 35; i++) if (is_prime[i])
		for (int j = i * i; j < 35; j += i)
			is_prime[j] = false;
}

void backtrack(int i) {
	if (i == N) {
		if (!is_prime[answer[N - 1] + answer[0]]) return;
		
		printf("%d", answer[0]);
		for (int j = 1; j < N; j++)
			printf(" %d", answer[j]);
		printf("\n");
		return;
	}
	
	for (int j = 1; j <= N; j++) if (!is_used[j] && is_prime[answer[i - 1] + j]) {
		is_used[j] = true;
		answer[i] = j;
		backtrack(i + 1);
		is_used[j] = false;
	}
}

int main() {
	slieve();
	
	int c = 0;
	while (scanf("%d", &N) != EOF) {
		if (c) printf("\n");
		printf("Case %d:\n", ++c);
		
		is_used.reset(); is_used[1] = true;
		answer[0] = 1;
		backtrack(1);
	}
}
