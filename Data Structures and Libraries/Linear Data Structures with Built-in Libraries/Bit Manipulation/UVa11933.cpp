#include <cstdio>

int main()
{
	int n, a, b;
	long long i;
	bool f;
	
	while (scanf("%d", &n), n != 0) {
		a = 0, b = 0, f = true;
		
		for (i = 1; i <= n; i <<= 1)
			if (i & n) {
				if (f) a |= i;
				else b |= i;
				
				f = !f;
			}
		
		printf("%d %d\n", a, b);
	}
}
