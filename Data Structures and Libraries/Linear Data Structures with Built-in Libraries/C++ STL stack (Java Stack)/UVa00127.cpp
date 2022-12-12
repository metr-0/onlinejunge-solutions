#include <cstdio>
#include <stack>
#include <utility>

using namespace std;
using cc = pair<char, char>;
using ccstack = stack<cc>;

bool eql(ccstack& a, ccstack& b)
{
	if (a.empty() || b.empty()) return false;
	return a.top().first == b.top().first || a.top().second == b.top().second;
}

void move(ccstack stacks[52], int cur, int max)
{
	for (int i = cur; i < max - 1; i++)
		stacks[i].swap(stacks[i + 1]);
	stacks[max - 1] = ccstack();
}

int main()
{
	ccstack stacks[52];
	char buf[5];
	int i, j, stack_i;
	bool f;
	
	while (scanf("%s", buf), buf[0] != '#') {
		for (i = 0; i < 52; i++)
			stacks[i] = ccstack();
		
		stacks[0].push(cc(buf[0], buf[1]));
		stack_i = 1;
		for (i = 1; i < 52; i++) {
			scanf("%s", buf);
			stacks[stack_i++].push(cc(buf[0], buf[1]));
			
			while (true) {
				f = true;
				for (j = 1; j < stack_i; j++) {
					if (j > 2 && eql(stacks[j], stacks[j - 3])) {
						stacks[j - 3].push(stacks[j].top());
						stacks[j].pop();
						if (stacks[j].empty())
							move(stacks, j, stack_i--);
						f = false;
						break;
					} if (j > 0 && eql(stacks[j], stacks[j - 1])) {
						stacks[j - 1].push(stacks[j].top());
						stacks[j].pop();
						if (stacks[j].empty())
							move(stacks, j, stack_i--);
						f = false;
						break;
					}
				}
				if (f) break;
			}
		}
		
		if (stack_i == 1)
			printf("1 pile remaining:");
		else
			printf("%d piles remaining:", stack_i);
		for (i = 0; i < stack_i; i++)
			printf(" %d", stacks[i].size());
		printf("\n");
	}
}
