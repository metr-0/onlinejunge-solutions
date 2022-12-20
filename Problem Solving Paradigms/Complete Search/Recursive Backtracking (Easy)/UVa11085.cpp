#include <cstdio>
#include <bitset>
#include <cstring>

using namespace std;

int p[92][8], p_cols[8], p_i = 0;
bitset<15> p_row, p_left_d, p_right_d;

int orig[8];

bool p_check(int x, int y) {
	return p_row[x] || p_left_d[x - y + 7] || p_right_d[x + y];
}

void precalc(int y) {
	if (y == 8)
		memcpy(p[p_i++], p_cols, sizeof(p_cols));
	
	for (int x = 0; x < 8; x++) {
		if (p_check(x, y)) continue;
		
		p_cols[y] = x;
		p_row[x] = p_left_d[x - y + 7] = p_right_d[x + y] = true;
		precalc(y + 1);
		p_row[x] = p_left_d[x - y + 7] = p_right_d[x + y] = false;
	}
}

int solve() {
	int min = 9;
	
	for (int i = 0; i < 92; i++) {
		int sum = 0;
		for (int y = 0; y < 8; y++) if (p[i][y] != orig[y])
			sum++;
		
		if (sum < min) min = sum;
	}
	
	return min;
}

int main() {
	precalc(0);
	int c = 1;
	
	while (scanf("%d", &orig[0]) != EOF) {
		orig[0]--;
		for (int i = 1; i < 8; i++)
			scanf("%d", &orig[i]), orig[i]--;
		
		printf("Case %d: %d\n", c++, solve());
	}
}
