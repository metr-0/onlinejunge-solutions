#include <cstdio>

int main()
{
	int TC, a, b, c;
	scanf("%d", &TC);
	
	for (int i = 1; i <= TC; i++) {
		scanf("%d %d %d", &a, &b, &c);
		
		if ((b < a && a < c) || (c < a && a < b))
			b = a;
		else if ((b < c && c < a) || (a < c && c < b))
			b = c;
		
		printf("Case %d: %d\n", i, b);
	}
}
