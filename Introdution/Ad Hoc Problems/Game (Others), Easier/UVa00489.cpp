#include <cstdio>
#include <set>

int main()
{
	int round;
	while (scanf("%d", &round), round != -1) {
		char buf[1000];
		
		scanf("%s", buf);
		std::set<char> orig;
		for (char c : buf) {
			if (c == '\0')
				break;
			orig.insert(c);
		}
		
		scanf("%s", buf);
		std::set<char> ans;		
		int i = 0;
		for (char c : buf) {
			if (ans.count(c) != 0)
				continue;
			
			if (c == '\0' || i == 7 || orig.empty())
				break;
			
			if (orig.count(c) != 0) {
				orig.erase(c);
			} else {
				i++;
			}
			ans.insert(c);
		}
		
		printf("Round %d\n", round);
		if (i == 7)
			printf("You lose.\n");
		else if (orig.empty())
			printf("You win.\n");
		else
			printf("You chickened out.\n");
	}
}
