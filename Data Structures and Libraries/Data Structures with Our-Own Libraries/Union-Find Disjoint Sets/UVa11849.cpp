#include <cstdio>
#include <bitset>

std::bitset<1000000005> f;

int main()
{
	int NC, MC;
	
	while (scanf("%d %d", &NC, &MC), NC != 0 || MC != 0) {
		f.reset();
		
		int temp;
		while (NC--) {
			scanf("%d", &temp);
			f[temp] = true;
		}
		
		int count = 0;
		while (MC--) {
			scanf("%d", &temp);
			if (f[temp]) count++;
		}
		
		printf("%d\n", count);
	}
}
