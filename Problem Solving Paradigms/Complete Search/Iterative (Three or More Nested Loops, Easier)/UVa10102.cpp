#include <cstdio>
#include <cmath>

using namespace std;

int A[105][105];

int main()
{
	int M;
	
	while (scanf("%d\n", &M) != EOF) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++)
				A[i][j] = getchar();
			getchar();
		}
		
		int max = -1;
		
		for (int y1 = 0; y1 < M; y1++)
			for (int x1 = 0; x1 < M; x1++) if (A[y1][x1] == '1') {
				int min = 100000;
				for (int y3 = 0; y3 < M; y3++)
					for (int x3 = 0; x3 < M; x3++) if (A[y3][x3] == '3') {
						int temp = abs(y1 - y3) + abs(x1 - x3);
						if (temp < min) min = temp;
					}
				if (min > max) max = min;
			}
		
		printf("%d\n", max);
	}
}
