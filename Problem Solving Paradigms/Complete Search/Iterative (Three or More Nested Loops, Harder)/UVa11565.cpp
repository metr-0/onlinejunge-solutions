#include <cstdio>

bool solve(int &x, int &y, int &z)
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	
	for (x = -22; x <= 22; x++) if (x * x <= C)
		for (y = -100; y <= 100; y++) if (x != y && x * x + y * y <= C)
			for (z = -100; z <= 100; z++) 
				if (x != z && y != z &&
					x + y + z == A && x * y * z == B && x * x + y * y + z * z == C)
					return true;
	
	return false;
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) {
		int x, y, z;
		if (solve(x, y, z)) printf("%d %d %d\n", x, y, z);
		else printf("No solution.\n");
	}
}
