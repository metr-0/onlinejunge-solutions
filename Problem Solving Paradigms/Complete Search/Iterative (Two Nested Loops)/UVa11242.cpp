#include <cstdio>
#include <algorithm>

using namespace std;

int f[105];
double q[10005];

int main()
{
	int F, R;
	
	while (scanf("%d", &F), F) {
		scanf("%d", &R);
		
		for (int i = 0; i < F; i++)
			scanf("%d", &f[i]);
		
		int i = 0, temp;
		for (int a = 0; a < R; a++) {
			scanf("%d", &temp);
			for (int b = 0; b < F; b++)
				q[i++] = (double)temp / f[b];
		}
		
		sort(q, q + i);
		
		double max = -1, d_temp;
		for (int j = 1; j < i; j++) {
			d_temp = q[j] / q[j - 1];
			if (d_temp > max) max = d_temp;
		}
		
		printf("%.2lf\n", max);
	}
}
