#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;
using dd = pair<double, double>;

dd circles[10005];

int main() {
	int N, L, W;
	while (scanf("%d %d %d", &N, &L, &W) != EOF) {
		double sqr = pow((double)W / 2, 2);
		
		int pos, radius;
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &pos, &radius);
			
			double d = sqrt(pow((double)radius, 2) - sqr);
			
			if (isnan(d)) circles[i] = { (double)pos, (double)pos };
			else circles[i] = { (double)pos - d, (double)pos + d };
		}
		sort(circles, circles + N);
		
		int count = 0, i = 0; double left = .0;
		while (left < L && i < N && circles[i].first <= left) {
			double max_r = -1.; int max_j;
			for (int j = i; j < N; j++)
				if (circles[j].first <= left) {
					if (circles[j].second >= max_r) max_r = circles[j].second, max_j = j;
				} else break;
			
			count++; left = circles[(i = max_j)++].second;
		}
		if (left < L) count = -1;
		
		printf("%d\n", count);
	}
}
