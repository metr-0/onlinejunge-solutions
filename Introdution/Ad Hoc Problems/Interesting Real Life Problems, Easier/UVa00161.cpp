#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int curr[110], curr_end[110], step[110];
	
	while (scanf("%d %d %d", &curr[0], &curr[1], &curr[2]), curr[0] != 0) {
		int r = 2;
		while (curr[r] != 0)
			scanf("%d", &curr[++r]);
		
		for (int i = 0; i < r; i++) {
			step[i] = curr[i] * 2;
			curr_end[i] = curr[i] - 5;
			curr[i] = 0;
		}
		
		bool ff = true;
		int max, min_i = min_element(curr_end, curr_end + r) - curr_end;
		while (true) {
			curr[min_i] += step[min_i];
			curr_end[min_i] += step[min_i];
			
			max = *max_element(curr, curr + r);
			if (max > 18000) {
				ff = false;
				break;
			}
			min_i = min_element(curr_end, curr_end + r) - curr_end;
			
			if (max < curr_end[min_i])
				break;
		}
		
		if (ff)
			printf("%02d:%02d:%02d\n", max / 3600, max / 60 % 60, max % 60);
		else
			printf("Signals fail to synchronise in 5 hours\n");
	}
}
