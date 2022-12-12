#include <cstdio>
#include <stack>

int main()
{
	std::stack<char> stacks[26];
	int i, j, last_i, s, temp, c = 0;
	char buf[1010];
	
	while (gets(buf), buf[0] != 'e') {
		c++;
		for (i = 0; i < 26; i++)
			stacks[i] = std::stack<char>();
		
		last_i = 0;
		for (i = 0; buf[i] != '\0'; i++) {
			s = -1;
			for (j = 0; j < last_i; j++) {
				if (stacks[j].top() >= buf[i] && (s == -1 || stacks[j].top() < stacks[s].top()))
					s = j;
			}
			if (s == -1)
				stacks[last_i++].push(buf[i]);
			else
				stacks[s].push(buf[i]);
		}
		
		printf("Case %d: %d\n", c, last_i);
	}
}
