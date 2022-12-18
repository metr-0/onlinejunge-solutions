#include <cstdio>
#include <algorithm>

using namespace std;

int A[1005], *sum = new int[1000005];

int get_closest(int v, int n)
{
	auto next = lower_bound(sum, sum + n, v);
	if (next == sum) return *next;
	if (next == sum + n) return sum[n - 1];
	
	auto prev = next - 1;
	if (*next - v < v - *prev) return *next;
	return *prev;
}

int main()
{
	int N, M, c = 1;
	
	while (scanf("%d", &N), N) {
		printf("Case %d:\n", c++);
		
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		
		int i = 0;
		for (int a = 0; a < N - 1; a++)
			for (int b = a + 1; b < N; b++)
				sum[i++] = A[a] + A[b];
		
		sort(sum, sum + i);
		
		scanf("%d", &M); int temp, prev, next;
		for (int a = 0; a < M; a++) {
			scanf("%d", &temp);
			
			printf("Closest sum to %d is %d.\n", temp, get_closest(temp, i));
		}
	}
}
