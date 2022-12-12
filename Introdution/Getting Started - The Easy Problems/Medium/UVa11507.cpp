#include <cstdio>
#include <cstring>

int main()
{
	int l;
	char str[5], curr[5];
	
	while (scanf("%d", &l), l != 0) {
		memcpy(curr, "+x", 3);
		
		while (--l) {
			scanf("%s", str);
			
			if (!strcmp(str, "No"))
				continue;
			
			if (!strcmp(curr, "+x"))
				memcpy(curr, str, 3);
			else if (!strcmp(curr, "-x")) {
				curr[1] = str[1];
				
				if (str[0] == '+')
					curr[0] = '-';
				else
					curr[0] = '+';
			}
			else if (!strcmp(curr, str))
				memcpy(curr, "-x", 3);
			else if (curr[1] == str[1])
				memcpy(curr, "+x", 3);
		}
		
		printf("%s\n", curr);
	}
}
