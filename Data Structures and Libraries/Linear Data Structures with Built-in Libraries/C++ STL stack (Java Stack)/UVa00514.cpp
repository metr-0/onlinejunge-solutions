#include <cstdio>
#include <stack>

int main()
{
	int n, i, a, curr;
	std::stack<int> station;
	bool f;
	
	while (scanf("%d", &n), n != 0) {
		while (scanf("%d", &a), a != 0) {
			station = std::stack<int>();
			
			curr = 1, f = true;
			for (i = 0; i < n; i++) {
				if (f) {
					while ((station.empty() || station.top() != a) && curr <= n)
						station.push(curr++);
					
					if (!station.empty() && station.top() == a)
						station.pop();
					else
						f = false;
				}
				
				if (i != n - 1) scanf("%d", &a);
			}
			
			if (f) printf("Yes\n");
			else printf("No\n");
		}
		
		printf("\n");
	}
}
