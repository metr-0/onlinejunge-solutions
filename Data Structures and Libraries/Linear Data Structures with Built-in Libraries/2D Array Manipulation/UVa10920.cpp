#include <cstdio>
#include <cmath>

int sz, ssz, x, y, tmp;
long long p, tmp1, tmp2;

void set_coords()
{
	tmp1 = ssz * ssz;
	tmp2 = tmp1 + 1 - ssz;
	if (p >= tmp2) {
		x = ssz, y = (int)(-tmp1 + ssz + p);
		return;
	} 
	tmp1 = tmp2, tmp2 = tmp2 + 1 - ssz;
	if (p >= tmp2) {
		x = (int)(-tmp1 + ssz + p), y = 1;
		return;
	}
	tmp1 = tmp2, tmp2 = tmp2 + 1 - ssz;
	if (p >= tmp2) {
		x = 1, y = (int)(tmp1 + 1 - p);
		return;
	}
	x = tmp2 + 1 - p, y = ssz;
}

int main()
{
	while (scanf("%d %lld", &sz, &p), sz != 0) {
		ssz = (int)std::floor(std::ceil(std::sqrt((double)p)) / 2) * 2 + 1;
		set_coords();
		tmp = (sz - ssz) / 2;
		printf("Line = %d, column = %d.\n", y + tmp, x + tmp);
	}
}
