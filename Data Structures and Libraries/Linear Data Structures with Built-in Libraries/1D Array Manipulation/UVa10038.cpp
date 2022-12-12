#include <cstdio>
#include <cstring>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int a, t_a, dif, i;
		bool f = true, ff[3050];
		memset(ff, false, sizeof(ff));
		scanf("%d", &a);
		
		for (i = 1; i < n; i++) {
			t_a = a;
			scanf("%d", &a);
			dif = a > t_a ? a - t_a : t_a - a;
			
			if (dif == 0 || dif >= n || ff[dif]) {
				f = false;
				break;
			}
			ff[dif] = true;
		}
		for (i++; i < n; i++)
			scanf("%d", &a);
		
		if (f)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
}
