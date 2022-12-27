#include <cstdio>

char events[55]; int dists[55], EC = 0;

bool check(double vol) {
	int leaks = 0;
	double cons, curr_vol = vol;
	
	for (int i = 0; i < EC - 1; i++) {
		if (events[i] == 'L') leaks++;
		else if (events[i] == 'M') leaks = 0;
		else if (events[i] == 'G') curr_vol = vol;
		else cons = (double)events[i] / 100;
		
		curr_vol -= (cons + leaks) * (dists[i + 1] - dists[i]);
		if (curr_vol < .0) return false;
	}
	return true;
}

void solve() {
	double lo = .0, hi = 10000., mid;
	for (int i = 0; i < 50; i++) {
		mid = (lo + hi) / 2;
		if (check(mid)) hi = mid;
		else lo = mid;
	}
	printf("%.3f\n", hi);
}

int main() {
	char buf[20], tbuf[20]; int dist, v;
	while (scanf("%d %s", &dist, buf)) {
		if (*buf == 'F' || (*buf == 'G' && buf[1] == 'a'))
			scanf("%s", tbuf);
		
		if (*buf == 'F') {
			scanf("%d", &v);
			if (!v) break;
			else events[EC] = v;
		} else events[EC] = *buf;
		
		dists[EC++] = dist;
		
		if (*buf == 'G' && buf[1] == 'o') {
			solve();
			EC = 0;
		}
	}
}
