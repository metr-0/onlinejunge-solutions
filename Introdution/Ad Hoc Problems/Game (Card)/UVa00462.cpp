#include <cstdio>

int main() {
	char str[5];
	
	while (scanf("%s", str) == 1) {
		int score = 0, a_score = 0, max = -1, max_i, count[] = {0, 0, 0, 0};
		bool all_stopped = true;
		bool a[] = {false, false, false, false};
		bool k[] = {false, false, false, false};
		bool q[] = {false, false, false, false};
		bool j[] = {false, false, false, false};
		
		for (int i = 0; i < 13; i++) {
			if (i != 0)
				scanf("%s", str);
			
			int suit;
			if (str[1] == 'S')
				suit = 0;
			else if (str[1] == 'H')
				suit = 1;
			else if (str[1] == 'D')
				suit = 2;
			else if (str[1] == 'C')
				suit = 3;
			
			count[suit]++;
			
			if (str[0] == 'A') {
				score += 4;
				a[suit] = true;
			}
			else if (str[0] == 'K') {
				score += 3;
				k[suit] = true;
			}
			else if (str[0] == 'Q') {
				score += 2;
				q[suit] = true;
			}
			else if (str[0] == 'J') {
				score += 1;
				j[suit] = true;
			}
		}
		
		for (int suit = 0; suit < 4; suit++) {
			bool stopped = a[suit];
			
			if (k[suit]) {
				if (count[suit] < 2)
					score--;
				else if (!stopped)
					stopped = true;
			}
			if (q[suit]) {
				if (count[suit] < 3)
					score--;
				else if (!stopped)
					stopped = true;
			}
			if (j[suit] && count[suit] < 4)
				score--;
			
			if (count[suit] == 2)
				a_score += 1;
			else if (count[suit] < 2)
				a_score += 2;
			
			if (count[suit] > max) {
				max = count[suit];
				max_i = suit;
			}
			
			if (!stopped)
				all_stopped = false;
		}
		
		if (score >= 16 && all_stopped)
			printf("BID NO-TRUMP\n", score);
		else if (score + a_score < 14)
			printf("PASS\n");
		else {
			if (max_i == 0)
				printf("BID S\n");
			else if (max_i == 1)
				printf("BID H\n");
			else if (max_i == 2)
				printf("BID D\n");
			else if (max_i == 3)
				printf("BID C\n");
		}
	}
}
