#include <cstdio>
#include <cstring>

int main()
{
	int i, j, temp, count, n, sum, max_sum, potencies[1 << 14];
	
	while (scanf("%d", &n) != EOF) {
		memset(potencies, 0, sizeof(potencies));
		count = 1 << n;
		
		for (i = 0; i < count; i++) {
			scanf("%d", &temp);
			for (j = 1; j < count; j <<= 1)
				potencies[i ^ j] += temp;
		}

		max_sum = 0;
		for (i = 0; i < count; i++)
			for (j = 1; j < count; j <<= 1) {
				temp = i ^ j, sum = potencies[i] + potencies[temp];
				if (temp < i && sum > max_sum)
					max_sum = sum;
			}

		printf("%d\n", max_sum);
	}
}
