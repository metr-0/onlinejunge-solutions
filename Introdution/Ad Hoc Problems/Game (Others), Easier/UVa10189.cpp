#include <cstdio>
#include <cstring>

int main()
{
	int i = 0, n, m;
	
	while (scanf("%d %d", &n, &m), m != 0 || m != 0) {
		i++;
		
		int field[110][110];
		memset(field, 0, sizeof(field));
		char buf[110];
		
		for (int y = 0; y < n; y++) {
			scanf("%s", buf);
			for (int x = 0; x < m; x++) {
				if (buf[x] != '*')
					continue;
				
				field[y][x] = -1;
				for (int y1 = y - 1; y1 <= y + 1; y1++)
					for (int x1 = x - 1; x1 <= x + 1; x1++)
						if (y1 >= 0 && y1 < n && x1 >= 0 && x1 < m && field[y1][x1] != -1)
							field[y1][x1]++;
			}
		}
		
		if (i != 1)
			printf("\n");
		printf("Field #%d:\n", i);
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (field[y][x] == -1)
					printf("*");
				else
					printf("%d", field[y][x]);
			}
			printf("\n");
		}
	}
}
