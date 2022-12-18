#include <cstdio>

char name[10005][23];
int min[10005], max[10005];

void solve()
{
	int DC, QC;
	
	scanf("%d", &DC);
	for (int i = 0; i < DC; i++)
		scanf("%s %d %d", name[i], &min[i], &max[i]);
	
	int q, res;
	scanf("%d", &QC);
	while (QC--) {
		scanf("%d", &q);
		bool f = false;
		
		for (int i = 0; i < DC; i++)
			if (min[i] <= q && max[i] >= q) {
				if (f) { f = false; break; }
				else { f = true; res = i; }
			}
		
		if (f) printf("%s\n", name[res]);
		else printf("UNDETERMINED\n");
	}
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) {
		solve();
		
		if (TC) printf("\n");
	}
}
