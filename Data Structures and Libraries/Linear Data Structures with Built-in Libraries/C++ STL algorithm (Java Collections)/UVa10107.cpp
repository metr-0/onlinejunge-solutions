#include <cstdio>
#include <algorithm>

int main()
{
	int i = 0, arr[10005], tmp;
	
	while (scanf("%d", &arr[i++]) != EOF) {
		std::nth_element(arr, arr + i / 2, arr + i);
		tmp = arr[i / 2];
		if (i % 2 == 1)
			printf("%d\n", tmp);
		else {
			std::nth_element(arr, arr + (i / 2 - 1), arr + i);
			printf("%d\n", ((tmp + arr[i / 2 - 1]) / 2));
		}
	}
}
