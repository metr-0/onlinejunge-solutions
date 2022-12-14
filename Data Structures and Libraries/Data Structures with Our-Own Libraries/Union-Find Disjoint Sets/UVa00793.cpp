#include <cstdio>
#include <vector>

using namespace std;
using vi = vector<int>;

class UnionFind {
private: vi p, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.resize(N + 1);
		for (int i = 1; i <= N; i++)
			p[i] = i;
	}
	int find_set(int i) {
		return p[i] == i ? i : (p[i] = find_set(p[i]));
	}
	bool is_same_set(int a, int b) {
		return find_set(a) == find_set(b);
	}
	void union_set(int a, int b) {
		if (is_same_set(a, b)) return;
		
		int x = find_set(a), y = find_set(b);
		if (rank[x] > rank[y]) p[y] = x;
		else p[x] = y;
		
		if (rank[x] == rank[y]) rank[y]++;
	}
};

void solve()
{
	int N;
	scanf("%d\n", &N);
	UnionFind uf(N);
	
	char buf[100], c;
	int a, b, right = 0, wrong = 0;
	while (gets(buf) != NULL && buf[0] != '\0') {
		sscanf(buf, "%c %d %d", &c, &a, &b);
		
		if (c == 'c') uf.union_set(a, b);
		else if (uf.is_same_set(a, b)) right++;
		else wrong++;
	}
	
	printf("%d,%d\n", right, wrong);
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
