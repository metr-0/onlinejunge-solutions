#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

vi A[52];

char get_i(char c) {
	if (c < 'a') return c - 'A';
	return c - 'a' + 26;
}

int main() {
	char c; int i = 0;
	while (c = getchar(), c != '\n')
		A[get_i(c)].push_back(i++);
	
	int Q; scanf("%d\n", &Q);
	while (Q--) {
		int last = -1, first; bool f = true;
		
		while (c = getchar(), c != '\n') {
			if (!f) continue;
			
			char temp = get_i(c);
			auto bound = upper_bound(A[temp].begin(), A[temp].end(), last);
			
			if (bound == A[temp].end()) { f = false; continue; }
			if (last == -1) first = *bound;
			last = *bound;
		}
		
		if (f) printf("Matched %d %d\n", first, last);
		else printf("Not matched\n");
	}
}
