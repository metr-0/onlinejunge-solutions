#include <cstdio>
#include <cmath>

#define EPS 1e-9

double p, q, r, s, t, u;

double func(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
	while (scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) != EOF) {
		double lo = .0, hi = 1., mid, res;
		for (int i = 0; i < 50; i++) {
			mid = (lo + hi) / 2;
			res = func(mid);
			if (res > 0.) lo = mid;
			else hi = mid;
		}
		
		if (fabs(res) < EPS) printf("%.4f\n", mid);
		else printf("No solution\n");
	}
}
