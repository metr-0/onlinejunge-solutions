#include <cstdio>

int main() {
	int N;
	while (scanf("%d", &N), N) {
		bool zero = true, first = true; 
		
		int temp;
		while (N--) {
			scanf("%d", &temp);
			if (temp > 0) {
				if (first) first = false;
				else printf(" ");
				printf("%d", temp);
				
				if (zero) zero = false;
			}
		}
		
		if (zero) printf("0");
		printf("\n");
	}
}
