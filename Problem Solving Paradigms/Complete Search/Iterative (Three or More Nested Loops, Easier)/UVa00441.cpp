#include <cstdio>

void solve(int N)
{
	int A[15];
	
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
	for (int a = 0; a < N - 5; a++)
		for (int b = a + 1; b < N - 4; b++)
			for (int c = b + 1; c < N - 3; c++)
				for (int d = c + 1; d < N - 2; d++)
					for (int e = d + 1; e < N - 1; e++)
						for (int f = e + 1; f < N; f++)
							printf("%d %d %d %d %d %d\n", A[a], A[b], A[c], A[d], A[e], A[f]);
}

int main()
{
	int N;
	bool f = false;
	
	while (scanf("%d", &N), N != 0) {
		if (f) printf("\n");
		else f = true;
		
		solve(N);
	}
}
