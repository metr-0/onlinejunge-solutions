#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;
using vi = vector<int>;

int main()
{
	int N, M;
	char buf[5];
	bitset<26> awaked, new_awaked;
	
	while (scanf("%d %d %s", &N, &M, buf) != EOF) {
		vi edges[26];
		awaked.reset();
		
		awaked[buf[0] - 'A'] = true;
		awaked[buf[1] - 'A'] = true;
		awaked[buf[2] - 'A'] = true;
		
		int a, b;
		while (M--) {
			scanf("%s", buf);
			a = buf[0] - 'A', b = buf[1] - 'A';
			
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		
		int years = 0;
		bool never_awake = false;
		while (!never_awake && awaked.count() != N) {
			new_awaked.reset();
			
			never_awake = true;
			int count;
			for (int i = 0; i < 26; i++) {
				if (awaked[i]) continue;
				
				count = 0;
				for (int j : edges[i])
					if (awaked[j]) count++;
				
				if (count >= 3) {
					new_awaked[i] = true;
					never_awake = false;
				}
			}
			
			awaked |= new_awaked;
			years++;
		}
		
		if (never_awake)
			printf("THIS BRAIN NEVER WAKES UP\n");
		else
			printf("WAKE UP IN, %d, YEARS\n", years);
	}
}
