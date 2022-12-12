#include <cstdio>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
	char buf[35];
	string species[10005];
	unordered_map<string, int> trees;
	
	int si = 0, total = 0;
	while (gets(buf) != NULL && buf[0] != '\0') {
		string temp(buf);
		total++;
		
		if (trees.find(temp) == trees.end()) {
			species[si++] = temp;
			trees[temp] = 1;
		} else {
			trees[temp]++;
		}
	}
	
	sort(species, species + si);
	
	for (int i = 0; i < si; i++)
		printf("%s %.4f\n", species[i].c_str(), (float)trees[species[i]] / (float)total * 100.f);
}

int main()
{
	int TC;
	scanf("%d\n\n", &TC);
	
	while (TC--) {
		solve();
		
		if (TC) printf("\n");
	}
}
