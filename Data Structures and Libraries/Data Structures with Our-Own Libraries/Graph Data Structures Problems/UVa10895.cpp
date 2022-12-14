#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
using vii = vector<pii>;

void solve(int m, int n)
{
	vii g[10005];
	char buf[85];
	
	int count;
	for (int y = 1; y <= m; y++) {
		scanf("%d", &count);
		gets(buf);
		
		int v, x;
		char *buf1 = buf;
		for (int i = 0; i < count; i++, buf1 += 2) {
			scanf("%d", &v);
			sscanf(buf1, "%d", &x);
			
			g[x].push_back({ y, v });
		}
	}
	
	printf("%d %d\n", n, m);
	for (int x = 1; x <= n; x++) {
		sort(g[x].begin(), g[x].end());
		
		count = g[x].size();
		printf("%d", count);
		for (int i = 0; i < count; i++)
			printf(" %d", g[x][i].first);
		printf("\n");
		
		for (int i = 0; i < count; i++) {
			if (i != 0) printf(" ");
			printf("%d", g[x][i].second);
		}
		printf("\n");
	}
	
}

int main()
{
	int m, n;
	
	while (scanf("%d %d", &m, &n) != EOF)
		solve(m, n);
}
