#include <cstdio>

int main()
{
	int TC;
	scanf("%d\n", &TC);
	
	while (TC--) {
		char sp;
		int m, n, count = 0;
		scanf("%c %d %d\n", &sp, &m, &n);
		
		if (sp == 'r' || sp == 'Q') {
			count = (m < n) ? m : n;
		} else if (sp == 'k') {
			count = m * n + 1;
			count /= 2;
		} else if (sp == 'K') {
			count = ((m + 1) / 2) * ((n + 1) / 2);
		}
		
		printf("%d\n", count);
	}
}
