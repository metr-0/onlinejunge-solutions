#include <cstdio>
#include <algorithm>
#include <stack>
#include <cmath>
#include <functional>

using namespace std;

int bachelors[10005], spinsters[10005];

int main() {
	int B, S, c = 0;
	while (scanf("%d %d", &B, &S), B || S) {
		for (int i = 0; i < B; i++)
			scanf("%d", &bachelors[i]);
		for (int i = 0; i < S; i++)
			scanf("%d", &spinsters[i]);
		sort(bachelors, bachelors + B, greater<int>());
		sort(spinsters, spinsters + S, greater<int>());
		
		stack<int> missed_s;
		
		int s = 0, b = 0;
		while (b < B) {
			while (s < S - 1 && abs(bachelors[b] - spinsters[s]) > abs(bachelors[b] - spinsters[s + 1]))
				missed_s.push(spinsters[s++]);
			
			if (s < S) s++;
			else if (!missed_s.empty()) missed_s.pop();
			else break;
			
			b++;
		}
		
		printf("Case %d: %d", ++c, B - b);
		if (b < B) printf(" %d", bachelors[B - 1]);
		printf("\n");
	}
}
