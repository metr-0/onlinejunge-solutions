#include <cstdio>
#include <cstring>

int main()
{
	int TC, i, ti = 0;
	unsigned char arr[100];
	char str[100010];
	
	scanf("%d", &TC);
	
	while (TC--) {
		i = 0;
		memset(arr, 0, 100);
		
		scanf("%s", str);
		for (char c : str) {
			if (c == '\0')
				break;
			
			if (c == '>')
				if (i == 99)
					i = 0;
				else
					i++;
			else if (c == '<')
				if (i == 0)
					i = 99;
				else
					i--;
			else if (c == '+')
				arr[i]++;
			else if (c == '-')
				arr[i]--;
		}
		
		printf("Case %d:", ++ti);
		for (unsigned char b : arr) {
			printf(" %02X", b);
		}
		printf("\n");
	}
}
