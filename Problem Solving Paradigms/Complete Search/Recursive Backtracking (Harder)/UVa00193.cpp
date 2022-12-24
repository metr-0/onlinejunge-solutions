#include <cstdio>
#include <bitset>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
vvi A;
bitset<105> black, used, res;

void backtrack() {
	if (used.count() == n) {
		if (black.count() > res.count())
			res = black;
		return;
	}
	
	for (int i = 1; i <= n; i++) if (!used[i]) {
		bitset<105> temp = used;
		
		used[i] = black[i] = true;
		for (int j : A[i]) used[j] = true;
		backtrack();
		
		black[i] = false;
		used = temp;
	}
}

int main() {
	int TC; scanf("%d", &TC);
	while (TC--) {
		int m, a, b;
		scanf("%d %d", &n, &m);
		A.assign(n + 1, vi());
		while (m--) {
			scanf("%d %d", &a, &b);
			A[a].push_back(b); A[b].push_back(a);
		}
		used.reset(); black.reset(); res.reset();
		
		backtrack();
		
		printf("%d\n", res.count());
		int i = 1; while (!res[i]) i++;
		printf("%d", i);
		for (int j = i + 1; j <= n; j++) if (res[j])
			printf(" %d", j);
		printf("\n");
	}
}
