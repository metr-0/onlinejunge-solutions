#include <cstdio>

int main() {
	unsigned int N, L, U;
	while (scanf("%u %u %u", &N, &L, &U) != EOF) {
		unsigned int M = ~N;
		for (unsigned int i = 1 << 31; i > 0; i >>= 1) {
			if (M > U) {
				if ((M & i) && !(U & i)) M &= ~i;
			} else if (M < L) {
				if (!(M & i) && (L & i)) M |= i;
			} else break;
		}
		printf("%u\n", M);
	}
}
