#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int x[25], y[25], v[25];
int best[5];

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) {
		int min = 1000000000, AC;
		scanf("%d", &AC);
		
		for (int i = 0; i < AC; i++)
			scanf("%d %d %d", &y[i], &x[i], &v[i]);
		
		for (int a = 0; a < 21; a++)
			for (int b = a + 1; b < 22; b++)
				for (int c = b + 1; c < 23; c++)
					for (int d = c + 1; d < 24; d++)
						for (int e = d + 1; e < 25; e++) {
							int sum = 0, solve[] = { a, b, c, d, e };
							
							for (int i = 0; i < AC; i++) {
								int closest = 100;
								
								for (int z : solve) {
									int temp = abs(x[i] - z % 5) + abs(y[i] - z / 5);
									if (temp < closest) closest = temp;
								}
								sum += closest * v[i];
							}
							
							if (sum < min) {
								min = sum;
								memcpy(best, solve, sizeof(best));
							}
						}
		
		printf("%d %d %d %d %d\n", best[0], best[1], best[2], best[3], best[4]);
	}
}
