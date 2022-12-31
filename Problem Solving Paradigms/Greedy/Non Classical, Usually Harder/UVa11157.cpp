#include <cstdio>

int res;

void jump(int &start, int finish) {
	int temp = finish - start;
	if (temp > res) res = temp;
	start = finish;
}

int main() {
	int T; scanf("%d", &T);
	
	for (int t = 1; t <= T; t++) {
		int N, D; scanf("%d %d\n", &N, &D);
		res = 0;
		
		int pos1 = 0, pos2 = 0, temp, m; char s, buf[5];
		while (N--) {
			scanf("%s", buf); sscanf(buf, "%c-%d", &s, &m);
			
			if (s == 'B')
				jump(pos1, m), jump(pos2, m);
			else if (pos1 > pos2)
				jump(pos2, m);
			else jump(pos1, m);
		}
		jump(pos1, D), jump(pos2, D);
		
		printf("Case %d: %d\n", t, res);
	}
}
