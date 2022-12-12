#include <cstdio>

int main() {
	int i;
	float well, day, night, ff, f, curr;
	
	while (scanf("%e %e %e %e", &well, &day, &night, &ff), well != 0.f) {
		f = day * .01f * ff;
		i = 0;
		curr = 0;
		
		while (true) {
			i++;
			
			curr += day;
			if (curr > well) {
				printf("success on day %d\n", i);
				break;
			}
			
			curr -= night;
			if (curr < 0) {
				printf("failure on day %d\n", i);
				break;
			}
			
			day -= f;
			if (day < 0)
				day = 0;
		}
	}
}
