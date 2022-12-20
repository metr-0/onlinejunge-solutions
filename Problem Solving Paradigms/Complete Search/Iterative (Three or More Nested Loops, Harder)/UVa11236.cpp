#include <cstdio>

int main()
{
	long long s, m;
	for (int a = 1; a <= 500; a++)
		for (int b = a; b <= 666; b++)
			for (int c = b; c <= 999; c++) {
				
				s = a + b + c, m = (long long)a * b * c - 1000000;
				
				if (m <= 0 || s * 1000000 % m) continue;
				
				int d = s * 1000000 / m;
				if (d < c || s + d > 2000) continue;
				
				printf("%d.%02d %d.%02d %d.%02d %d.%02d\n",
					a / 100, a % 100, b / 100, b % 100, c / 100, c % 100, d / 100, d % 100);
			}
}
