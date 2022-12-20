#include <cstdio>
#include <algorithm>

using namespace std;

int A[8][8], p[8];

int main()
{
	int TC; scanf("%d", &TC);
	while (TC--) {
		int N; scanf("%d", &N);
		for (int y = 0; y < N; y++) {
			p[y] = y;
			for (int x = 0; x < N; x++)
				scanf("%d", &A[y][x]);
		}
		
		int min_sum = 1000000000;
		do {
			int sum = 0;
			for (int y = 0; y < N; y++)
				sum += A[y][p[y]];
			if (sum < min_sum)
				min_sum = sum;
		} while (next_permutation(p, p + N));
		
		printf("%d\n", min_sum);
	}
}
