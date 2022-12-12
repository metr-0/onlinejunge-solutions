#include <cstdio>
#include <algorithm>
#include <cstring>

int main()
{
	char str[55];
	
	while (gets(str), str[0] != '#' || str[1] != '\0') {
		if (std::next_permutation(str, str + strlen(str)))
			puts(str);
		else
			puts("No Successor");
	}
}
