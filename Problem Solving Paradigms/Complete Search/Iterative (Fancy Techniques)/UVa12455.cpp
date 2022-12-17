#include <cstdio>

bool solve()
{
	int N, P, arr[25];
	scanf("%d %d", &N, &P);
	
	for (int i = 0; i < P; i++)
		scanf("%d", &arr[i]);
	
	int sum;
	for (int i = 0; i < (1 << P); i++) {
		sum = 0;
		
		for (int j = 0; j < P; j++)
			if (i & (1 << j)) sum += arr[j];
		
		if (sum == N) return true;
	}
	
	return false;
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) {
		if (solve()) printf("YES\n");
		else printf("NO\n");
	}
}
