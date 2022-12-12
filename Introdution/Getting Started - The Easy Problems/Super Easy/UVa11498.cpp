#include <cstdio>
#include <string>

using namespace std;

int main() {
	int TC, n, m, x, y;
	string ans;
	
	while (scanf("%d", &TC), TC) {
		scanf("%d %d", &n, &m);
		
		while (TC--) {
			scanf("%d %d", &x, &y);
			
			if (x > n && y > m)
				ans = "NE";
			else if (x > n && y < m)
				ans = "SE";
			else if (x < n && y < m)
				ans = "SO";
			else if (x < n && y > m)
				ans = "NO";
			else
				ans = "divisa";
			
			printf("%s\n", ans.c_str());
		}
	}
}
