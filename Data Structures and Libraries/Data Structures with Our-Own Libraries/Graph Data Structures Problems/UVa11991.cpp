#include <cstdio>
#include <vector>

using namespace std;
using vi = vector<int>;

int main()
{
	int n, m;
	
	while (scanf("%d %d", &n, &m) != EOF) {
		vi *nums = new vi[1000005];
		
		int v, i;
		for (i = 1; i <= n; i++) {
			scanf("%d", &v);
			nums[v].push_back(i);
		}
		
		while (m--) {
			scanf("%d %d", &i, &v);

			if (nums[v].size() < i) printf("0\n");
			else printf("%d\n", nums[v][i - 1]);
		}
	}
}
