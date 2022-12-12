#include <cstdio>
#include <cctype>
#include <cstring>

char board[8][8];
bool memo[8][8];
int count;

bool on_board(int y, int x)
{
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int get_int(char c)
{
	if (isdigit(c))
		return (int)c - (int)'0';
	return 0;
}

bool check(int y, int x) {
	if (on_board(y, x) && board[y][x] == '.') {
		if (!memo[y][x]) {
			memo[y][x] = true;
			count--;
		}
		
		return true;
	}
	return false;
}

int main()
{
	char str[80];
	
	while (scanf("%s", str) == 1) {
		int y = 0, x = 0;
		count = 64;
		for (char c : str) {
			if (c == '\0')
				break;
			
			if (c == '/') {
				y++;
				x = 0;
				continue;
			}
			
			int t = get_int(c);
			if (t) {
				for (int i = 0; i < t; i++) {
					board[y][x] = '.';
					memo[y][x] = false;
					x++;
				}
				continue;
			}
			
			if (c != 'P' && isupper(c))
				board[y][x] = (char)tolower(c);
			else
				board[y][x] = c;
			
			memo[y][x] = true;
			count--;
			x++;
		}
		
		for (y = 0; y < 8; y++) {
			for (x = 0; x < 8; x++) {
				char c = board[y][x];
				if (c == '.')
					continue;
				
				if (c == 'q' || c == 'r') {
					for (int x1 = x - 1; x1 >= 0; x1--)
						if (!check(y, x1))
							break;
					for (int x1 = x + 1; x1 < 8; x1++)
						if (!check(y, x1))
							break;
					for (int y1 = y - 1; y1 >= 0; y1--)
						if (!check(y1, x))
							break;
					for (int y1 = y + 1; y1 < 8; y1++)
						if (!check(y1, x))
							break;
				}
				if (c == 'q' || c == 'b') {
					for (int y1 = y - 1, x1 = x - 1; y1 >= 0; y1--, x1--)
						if (!check(y1, x1))
							break;
					for (int y1 = y - 1, x1 = x + 1; y1 >= 0; y1--, x1++)
						if (!check(y1, x1))
							break;
					for (int y1 = y + 1, x1 = x - 1; y1 < 8; y1++, x1--)
						if (!check(y1, x1))
							break;
					for (int y1 = y + 1, x1 = x + 1; y1 < 8; y1++, x1++)
						if (!check(y1, x1))
							break;
				}
				
				if (c == 'p') {
					check(y + 1, x - 1);
					check(y + 1, x + 1);
				} else if (c == 'P') {
					check(y - 1, x - 1);
					check(y - 1, x + 1);
				} else if (c == 'k') {
					for (int y1 = y - 1; y1 <= y + 1; y1++)
						for (int x1 = x - 1; x1 <= x + 1; x1++)
							if (y1 != y || x1 != x)
								check(y1, x1);
				} else if (c == 'n') {
					check(y - 2, x - 1);
					check(y - 2, x + 1);
					check(y + 2, x - 1);
					check(y + 2, x + 1);
					check(y - 1, x - 2);
					check(y - 1, x + 2);
					check(y + 1, x - 2);
					check(y + 1, x + 2);
				}
			}
		}
		
		printf("%d\n", count);
	}
}
