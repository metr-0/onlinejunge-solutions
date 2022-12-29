#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;
using ii = pair<int, int>;

int A[15];
ii indexes[15], pairs[7];

int main() {
	int C, S, N, t = 0;
	while (scanf("%d %d", &C, &S) != EOF) {
		N = C * 2;
		
		double am = .0;
		for (int i = 0; i < S; i++) {
			scanf("%d", &A[i]);
			indexes[i] = { A[i], i };
			am += A[i];
		}
		for (int i = S; i < N; i++) {
			A[i] = 0;
			indexes[i] = { 0, i };
		}
		am /= C;
		sort(indexes, indexes + N);
		
		for (int i = 0; i < C; i++) {
			int j0 = indexes[i].second, j1 = indexes[N - i - 1].second;
			if (j0 > j1) pairs[i] = { j1, j0 };
			else pairs[i] = { j0, j1 };
		}
		sort(pairs, pairs + C);
		
		double imb = .0;
		printf("Set #%d\n", ++t);
		for (int i = 0; i < C; i++) {
			int first = A[pairs[i].first], second = A[pairs[i].second];
			
			printf("%2d:", i, first);
			if (first) printf(" %d", first);
			if (second) printf(" %d", second);
			printf("\n");
			
			imb += fabs((double)(first + second) - am);
		}
		printf("IMBALANCE = %.5f\n\n", imb);
	}
}
