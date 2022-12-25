#include <cstdio>
#include <algorithm>

using namespace std;

int A[505][505], N, M;

int main() {
	while (scanf("%d %d", &N, &M), N || M) {
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				scanf("%d", &A[y][x]);
		
		int Q; scanf("%d", &Q);
		while (Q--) {
			int l, h; scanf("%d %d", &l, &h);
			
			int max_size = 0;
			for (int y = 0; y < N; y++) {
				int x = lower_bound(A[y], A[y] + M, l) - A[y];
				int dy = y + max_size, dx = x + max_size;
				while (dy < N && dx < M && A[dy][dx] <= h)
					dx++, dy++, max_size++;
			}
			
			printf("%d\n", max_size);
		}
		printf("-\n");
	}
}
