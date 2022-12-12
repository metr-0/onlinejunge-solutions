#include <cstdio>

int main()
{
	int TC, a, b;
	char rel;
	
	scanf("%d", &TC);
	
	while (TC--) {
		scanf("%d %d", &a, &b);
		
		if (a > b)
			rel = '>';
		else if (b > a)
			rel = '<';
		else
			rel = '=';
		
		printf("%c\n", rel);
	}
}
