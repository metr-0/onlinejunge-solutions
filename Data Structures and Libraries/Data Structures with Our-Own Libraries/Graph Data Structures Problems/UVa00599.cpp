#include <cstdio>
#include <cstring>
#include <bitset>

void solve()
{
	std::bitset<26> bitset;
	
	int edges = 0;
	char buf[60];
	while (scanf("%s", buf), buf[0] != '*') {
		edges++;
		bitset[buf[1] - 'A'] = true;
		bitset[buf[3] - 'A'] = true;
	}
	
	int acorns = 0;
	scanf("%s", buf);
	for (int i = 0, l = strlen(buf); i < l; i += 2)
		if (!bitset[buf[i] - 'A']) {
			acorns++;
			bitset[buf[i] - 'A'] = true;
		}
	
	printf("There are %d tree(s) and %d acorn(s).\n", bitset.count() - edges - acorns, acorns);
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) solve();
}
