#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, arr[10], conditions[25][3];
	
	while (scanf("%d %d", &N, &M), N != 0) {
		for (int i = 0; i < N; i++)
			arr[i] = i;
		for (int i = 0; i < M; i++)
			scanf("%d %d %d", &conditions[i][0], &conditions[i][1], &conditions[i][2]);
		int count = 0;
		
		do {
			count++;
			for (int i = 0; i < M; i++) {
				int dist = abs(arr[conditions[i][0]] - arr[conditions[i][1]]);
				if (conditions[i][2] > 0 && conditions[i][2] < dist) {
					count--;
					break;
				} else if (conditions[i][2] < 0 && -conditions[i][2] > dist) {
					count--;
					break;
				}
			}
		} while (next_permutation(arr, arr + N));
		
		printf("%d\n", count);
	}
}
