#include <cstdio>

int main() {
	int n;
	
	while (scanf("%d", &n), n != 0) {
		printf("Printing order for %d pages:\n", n);
		
		bool front = true;
		int sheet = 1, max = n % 4 == 0 ? n : n + (4 - n % 4);
		for (int min = 1; min < max; min++, max--) {
			if (front) {
				printf("Sheet %d, front: ", sheet);
				if (max > n)
					printf("Blank, ");
				else
					printf("%d, ", max);
				if (min > n)
					printf("Blank\n");
				else
					printf("%d\n", min);
				
				if (n == 1)
					break;
			} else {
				printf("Sheet %d, back : ", sheet++);
				if (min > n)
					printf("Blank, ");
				else
					printf("%d, ", min);
				if (max > n)
					printf("Blank\n");
				else
					printf("%d\n", max);
			}
			
			front = !front;
		}
	}
}
