#include <cstdio>

int A[1005];

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) {
		int N, sum = 0, temp;
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++) {
			scanf("%d", &temp);
			A[i] = temp;
			
			for (int j = 0; j < i; j++)
				if (A[j] <= temp) sum++;
		}
		
		printf("%d\n", sum);
	}
}
