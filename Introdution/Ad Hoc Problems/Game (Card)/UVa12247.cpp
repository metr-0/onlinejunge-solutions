#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int p[3], x, y;
	while (scanf("%d %d %d %d %d", &p[0], &p[1], &p[2], &x, &y), x != 0) {
		int p_copy[3], score = 0;
		memcpy(p_copy, p, sizeof(p));
		
		if (x > y)
			swap(x, y);
		sort(p, p + 3);
		
		bool f = false;
		for (int i = 0; i < 3; i++) {
			if (p[i] > y) {
				p[i] = -1;
				
				f = true;
				break;
			}
		}
		if (!f) {
			p[0] = -1;
			score += 1;
		}
		
		f = false;
		for (int i = 0; i < 3; i++) {
			if (p[i] == -1)
				continue;
			
			if (p[i] > x) {
				p[i] = -1;
				
				f = true;
				break;
			}
		}
		if (!f) {
			if (p[0] == -1)
				p[1] = -1;
			else
				p[0] = -1;
			score += 1;
		}
		
		if (score == 0) {
			printf("-1\n");
			continue;
		}
		if (score == 2) {
			for (int i = 1; i <= 52; i++) {
				if (i != p_copy[0] && i != p_copy[1] && i != p_copy[2] && i != x && i != y) {
					printf("%d\n", i);
					break;
				}
			}
			continue;
		}
		
		for (int i = 0; i < 3; i++) {
			if (p[i] != -1) {
				f = false;
				
				for (int j = p[i] + 1; j <= 52; j++) {
					if (j != p_copy[0] && j != p_copy[1] && j != p_copy[2] && j != x && j != y) {
						printf("%d\n", j);
						
						f = true;
						break;
					}
				}
				
				if (!f)
					printf("-1\n");
				
				break;
			}
		}
	}
}
