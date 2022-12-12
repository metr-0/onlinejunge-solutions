#include <cstdio>
#include <bitset>

int OC, RC, l, r, interval, i;
std::bitset<1000000> mins;

bool check()
{
	while (OC--) {
		scanf("%d %d", &l, &r);
		for (i = l; i < r; i++) {
			if (mins[i]) return false;
			else mins[i] = true;
		}
	}
	while (RC--) {
		scanf("%d %d %d", &l, &r, &interval);
		for (; l < 1000000; l += interval, r += interval)
			for (i = l; i < r && i < 1000000; i++) {
				if (mins[i]) return false;
				else mins[i] = true;
			}
	}
	return true;
}

int main()
{
	while (scanf("%d %d", &OC, &RC), OC != 0 || RC != 0) {
		mins.reset();
		
		if (check()) {
			printf("NO CONFLICT\n");
		} else {
			while (OC-- > 0)
				scanf("%d %d", &l, &r);
			while (RC-- > 0)
				scanf("%d %d %d", &l, &r, &interval);
			printf("CONFLICT\n");
		}
	}
}
