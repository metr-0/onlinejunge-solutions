#include <cstdio>
#include <cstring>

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) {
		int PC, LC, RC;
		scanf("%d %d %d", &PC, &LC, &RC);
		
		int *p = new int[1000010], l[110];
		for (int i = 0; i < PC; i++)
			p[i] = 1;
		memset(l, 0, sizeof(l));
		
		while (LC--) {
			int start, end;
			scanf("%d %d", &start, &end);
			l[start] = end;
		}
		
		int pi = 0;
		while (RC--) {
			int num;
			scanf("%d", &num);
			p[pi] += num;
			
			if (p[pi] > 100)
				p[pi] = p[pi] % 100;
			if (l[p[pi]] != 0)
				p[pi] = l[p[pi]];
			
			if (p[pi] == 100)
				break;
			
			pi++;
			if (pi == PC)
				pi = 0;
		}
		
		if (RC > 0) {
			while (RC--) {
				int num;
				scanf("%d", &num);
			}
		}
		
		for (int i = 0; i < PC; i++)
			printf("Position of player %d is %d.\n", i + 1, p[i]);
	}
}
