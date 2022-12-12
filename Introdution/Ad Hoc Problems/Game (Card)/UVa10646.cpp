#include <cstdio>

int main()
{
	int TC;
	scanf("%d", &TC);
	
	char str[5];
	
	for (int t = 1; t <= TC; t++) {
		for (int i = 0; i < 52; i++) {
			scanf("%s", str);
			
			if (i == 32)
				printf("Case %d: %s\n", t, str);
		}
	}
}
