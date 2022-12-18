#include <cstdio>

bool check(int i)
{
	return i <= 20 || i == 50 || (i <= 40 && i % 2 == 0) || (i % 3 == 0);
}

int main()
{
	int N;
	
	while (scanf("%d", &N), N > 0) {
		int c = 0, p = 0;
		
		if (N <= 180)
			for (int i = 0; i <= 60; i++) if (check(i) && i <= N)
				for (int j = i; j <= 60; j++) if (check(j) && (i + j) <= N)
					for (int k = j; k <= 60; k++) if (check(k) && (i + j + k) == N) {
						if (i == j && j == k) p++;
						else if (i == j || j == k || i == k) p += 3;
						else p += 6;
						
						c++;
					}
					
		
		if (c) {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", N, c);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", N, p);
		} else {
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", N);
		}
		
		printf("**********************************************************************\n");
	}
	
	printf("END OF OUTPUT\n");
}
