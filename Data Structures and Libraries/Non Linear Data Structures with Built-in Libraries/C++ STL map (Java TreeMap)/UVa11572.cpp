#include <cstdio>
#include <cstring>

int main()
{
	int SC, BC, l[100010], r[100010], tl[100010], tr[100010], li, ri;
	for (int i = 1; i < 100005; i++) {
		l[i] = i - 1;
		r[i] = i + 1;
	}
	l[1] = -1;
	
	while (scanf("%d %d", &SC, &BC), SC != 0 || BC != 0) {
		memcpy(tl, l, sizeof(int) * (SC + 3));
		memcpy(tr, r, sizeof(int) * (SC + 3));
		tr[SC] = -1;
		
		while (BC--) {
			scanf("%d %d", &li, &ri);
			
			
			if (tl[li] == -1)
				printf("* ");
			else
				printf("%d ", tl[li]);
			if (tr[ri] == -1)
				printf("*\n");
			else
				printf("%d\n", tr[ri]);
			
			tr[tl[li]] = tr[ri];
			tl[tr[ri]] = tl[li];
		}
		
		printf("-\n");
	}
}
