#include <cstdio>
#include <algorithm>
#include <cstring>

int TC, i, j, cons_end, cons[105], p, pb, problems[105], problems_i[105][12], t, times[105], counts[105];
bool f[105];
char buf[100], c;

struct {
	bool operator()(int a, int b) const {
		if (counts[a] == counts[b]) {
			if (times[a] == times[b])
				return a < b;
			return times[a] < times[b];
		}
		return counts[a] > counts[b];
	}
} custom;

int main()
{
	gets(buf);
	sscanf(buf, "%d", &TC);
	gets(buf);
	
	while (TC--) {
		memset(cons, 0, sizeof(cons));
		memset(problems, 0, sizeof(problems));
		memset(problems_i, 0, sizeof(problems_i));
		memset(times, 0, sizeof(times));
		memset(counts, 0, sizeof(counts));
		memset(f, false, sizeof(f));
		
		cons_end = 0;
		while (gets(buf) == buf && sscanf(buf, "%d %d %d %c", &i, &p, &t, &c) == 4) {
			if (!f[i]) {
				f[i] = true;
				cons[cons_end] = i;
				cons_end++;
			}
			
			pb = 1 << p;
			if (!(problems[i] & pb)) {
				if (c == 'C') {
					counts[i] += 1;
					problems[i] |= pb;
					times[i] += t + problems_i[i][p] * 20;
				} else if (c == 'I') {
					problems_i[i][p]++;
				}
			}
		}
		
		std::sort(cons, cons + cons_end, custom);
		
		for (i = 0; i < cons_end; i++)
			printf("%d %d %d\n", cons[i], counts[cons[i]], times[cons[i]]);
		if (TC)
			printf("\n");
	}
}
