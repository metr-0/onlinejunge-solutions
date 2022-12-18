#include <cstdio>
#include <cmath>

#define EPS 0.0000000001

using namespace std;

int main()
{
	int N;
	while (scanf("%d", &N) != EOF) {
		int count = 0, b; double a;
		for (b = N + 1, a = N * (N + 1); b <= (int)a;
			b++, a = (double)N * b / (b - N)) {
			if (abs(a - (int)a) < EPS) count++;
		}
		printf("%d\n", count);
		
		for (b = N + 1, a = N * (N + 1); b <= (int)a;
			b++, a = (double)N * b / (b - N)) {
			if (abs(a - (int)a) < EPS)
				printf("1/%d = 1/%d + 1/%d\n", N, int(a), b);
		}
	}
}
