#include <cstdio>
#include <bitset>
#include <utility>

using namespace std;
using ii = pair<int, int>;

bitset<15> is_used;
ii A[15];
int N, M, first, last;

bool backtrack(int v, int count) {
	if (count == N) return v == last;
	
	for (int i = 0; i < M; i++) if (!is_used[i]) {
		if (A[i].first == v) {
			is_used[i] = true;
			if (backtrack(A[i].second, count + 1)) return true;
			is_used[i] = false;
		} else if (A[i].second == v) {
			is_used[i] = true;
			if (backtrack(A[i].first, count + 1)) return true;
			is_used[i] = false;
		}
	}
	return false;
}

int main() {
	while (scanf("%d", &N), N) {
		scanf("%d", &M);
		
		int temp;
		scanf("%d %d", &temp, &first);
		scanf("%d %d", &last, &temp);
		
		int a, b;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &a, &b);
			A[i] = { a, b };
		}
		is_used.reset();
		
		if (backtrack(first, 0))
			printf("YES\n");
		else printf("NO\n");
	}
}
