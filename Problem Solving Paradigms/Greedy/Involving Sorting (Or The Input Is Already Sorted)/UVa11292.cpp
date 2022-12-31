#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, M, heads[20005], knights[20005];
	while (scanf("%d %d", &N, &M), N || M) {
		for (int i = 0; i < N; i++)
			scanf("%d", &heads[i]);
		for (int i = 0; i < M; i++)
			scanf("%d", &knights[i]);
		sort(heads, heads + N); sort(knights, knights + M);
		
		int sum = 0, h = 0, k = 0;
		while (h < N) {
			while (k < M && heads[h] > knights[k]) k++;
			if (k == M) break;
			
			sum += knights[k++], h++;
		}
		
		if (h == N) printf("%d\n", sum);
		else printf("Loowater is doomed!\n");
	}
}
