#include <cstdio>
#include <vector>
#include <map>
#include <string>

using namespace std;
using vi = vector<int>;

class UnionFind {
private: vi p, rank, size;
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		size.assign(N, 1);
		
		p.resize(N);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	void add_set() {
		rank.push_back(0);
		size.push_back(1);
		p.push_back(p.size());
	}
	int find_set(int a) {
		return p[a] == a ? a : (p[a] = find_set(p[a]));
	}
	bool is_same_set(int a, int b) {
		return find_set(a) == find_set(b);
	}
	void union_set(int a, int b) {
		if (is_same_set(a, b)) return;
		
		int x = find_set(a), y = find_set(b);
		if (rank[x] > rank[y]) {
			p[y] = x;
			size[x] += size[y];
		} else {
			p[x] = y;
			size[y] += size[x];
		}
		
		if (rank[x] == rank[y]) rank[y]++;
	}
	int size_of_set(int a) {
		return size[find_set(a)];
	}
};

void solve()
{
	int RC;
	scanf("%d", &RC);
	
	UnionFind uf(0);
	map<string, int> dict;
	
	int curr_i = 0, a, b;
	char buf[25];
	string name1, name2;
	
	while (RC--) {
		scanf("%s", buf);
		name1 = string(buf);
		
		scanf("%s", buf);
		name2 = string(buf);
		
		if (dict.find(name1) == dict.end()) {
			dict[name1] = curr_i++;
			uf.add_set();
		}
		if (dict.find(name2) == dict.end()) {
			dict[name2] = curr_i++;
			uf.add_set();
		}
		
		a = dict[name1], b = dict[name2];
		uf.union_set(a, b);
		
		printf("%d\n", uf.size_of_set(a));
	}
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) solve();
}
