#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bitset>

using namespace std;

int A[8], X, Y, line;
bitset<15> row, left_d, right_d;

bool check(int x, int y) {
	return !row[x] && !left_d[x - y + 7] && !right_d[x + y];
}

void backtrack(int y)
{
	if (y == 8 && A[Y] == X) {
		printf("%2d     ", ++line);
		for (int i = 0; i < 8; i++)
			printf(" %d", A[i] + 1);
		printf("\n");
		return;
	}
	
	for (int x = 0; x < 8; x++)
		if (check(x, y)) {
			if (y == Y && x != X) continue;
			
			A[y] = x;
			row[x] = left_d[x - y + 7] = right_d[x + y] = true;
			backtrack(y + 1);
			row[x] = left_d[x - y + 7] = right_d[x + y] = false;
		}
}

int main()
{
	int TC;
	scanf("%d", &TC);
	
	while (TC--) {
		scanf("%d %d", &X, &Y); X--, Y--;
		memset(A, 0, sizeof(A)); line = 0;
		row.reset(), left_d.reset(), right_d.reset();
		
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		
		if (TC) printf("\n");
	}
}
