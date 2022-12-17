#include <cstdio>

bool check(int abcde, int fghij)
{
	int temp, d, digits = (abcde < 10000);
	
	temp = abcde;
	while (temp) {
		d = 1 << (temp % 10);
		if (digits & d) return false;
		digits |= d;
		temp /= 10;
	}
	
	temp = fghij;
	while (temp) {
		d = 1 << (temp % 10);
		if (digits & d) return false;
		digits |= d;
		temp /= 10;
	}
	
	return digits == (1 << 10) - 1;
}

void solve(int N)
{
	bool f = false;
	
	for (int abcde = 1234, fghij; abcde <= 98765 / N; abcde++) {
		fghij = abcde * N;
		
		if (check(abcde, fghij)) {
			f = true;
			printf("%d / %05d = %d\n", fghij, abcde, N);
		}
	}
	
	if (!f) printf("There are no solutions for %d.\n", N);
}

int main()
{
	int N;
	bool f = false;
	
	while (scanf("%d", &N), N != 0) {
		if (f) printf("\n");
		else f = true;
		
		solve(N);
	}
}
