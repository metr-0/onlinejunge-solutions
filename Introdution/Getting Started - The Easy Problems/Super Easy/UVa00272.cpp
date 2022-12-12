#include <cstdio>

int main()
{
	char c;
	bool f = false;
	
	while (scanf("%c", &c) != EOF) {
		if (c != '"') {
			printf("%c", c);
			continue;
		}
		
		if (f)
			printf("%s", "''");
		else
			printf("%s", "``");
		f = !f;
	}
}
