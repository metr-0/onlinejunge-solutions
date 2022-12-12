#include <cstdio>
#include <algorithm>

int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n), m != 0 || n != 0) {
		int count;
		if (n == 0 || m == 0) {
			count = 0;
		} else if (n == 1 || m == 1) {
			count = std::max(n, m);
		} else if (n == 2 || m == 2) {
			int t = std::max(n, m);
			if (t % 2 == 0)
				count = t + t % 4;
			else
				count = t + 1;
		} else {
			count = (n * m + 1) / 2;
		}
		
		printf("%d knights may be placed on a %d row %d column board.\n", count, m, n);
	}
}
