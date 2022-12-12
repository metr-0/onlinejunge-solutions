#include <cstdio>
#include <cstring>

int main()
{
	bool g[3][3], tmp[3][3], null[3][3];
	int TC, x, y, min, sum;
	memset(null, false, sizeof(null));
	scanf("%d", &TC);
	
	while (TC--) {
		for (y = 0; y < 3; y++)
			for (x = 0; x < 3; x++)
				scanf("%1d", &g[y][x]);
		
		min = -1;
		while (memcmp(g, null, sizeof(g))) {
			memcpy(tmp, g, sizeof(g));
			
			for (y = 0; y < 3; y++)
				for (x = 0; x < 3; x++) {
					sum = 0;
					if (y != 0) sum += tmp[y - 1][x];
					if (y != 2) sum += tmp[y + 1][x];
					if (x != 0) sum += tmp[y][x - 1];
					if (x != 2) sum += tmp[y][x + 1];
					g[y][x] = (bool)(sum % 2);
				}
			
			min++;
		}
		
		printf("%d\n", min);
	}
}
