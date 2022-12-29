#include <cstdio>

int main() {
	int TC; scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		int N; scanf("%d\n", &N);
		
		int count = 0, status = 2; char c;
		for (int i = 0; i < N; i++) {
			if (status != 2) status++;
			
			scanf("%c", &c);
			if (c == '.' && status == 2)
				status = -1, count++;
		}
		
		printf("Case %d: %d\n", t, count);
	}
}
