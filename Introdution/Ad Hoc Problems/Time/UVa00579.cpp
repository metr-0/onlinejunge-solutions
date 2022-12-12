#include <cstdio>

int main()
{
	int h, m;
	while (scanf("%d:%d", &h, &m), h != 0 || m != 0) {
		float angle = (float)h * 30.f - (float)m * 5.5f;
		if (angle < 0.f)
			angle = -angle;
		if (angle > 180.f)
			angle = 360.f - angle;
		printf("%.3f\n", angle);
	}
}
