#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, A[10005]; bool is_first = true;
	
	while (scanf("%d", &N), N) {
		if (is_first) is_first = false;
		else printf("\n");
		
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		
		sort(A, A + N);
		
		int count = 1, max_count = 0;
		for (int i = 1; i < N; i++)
			if (A[i] == A[i - 1]) count++;
			else {
				if (count > max_count) max_count = count;
				count = 1;
			}
		if (count > max_count) max_count = count;
		
		printf("%d\n", max_count);
		for (int i = 0; i < max_count; i++) {
			printf("%d", A[i]);
			for (int j = i + max_count; j < N; j += max_count)
				printf(" %d", A[j]);
			printf("\n");
		}
	}
}
