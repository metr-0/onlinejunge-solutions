#include <cstdio>
#include <cstring>

#define LEN(ptr) (ptr == NULL ? 0 : strlen(ptr))

bool matrix[205][205]; int R, C;
char *buf = new char('\0');

char getc() {
	if (*buf == '\0') {
		buf = new char[80000]; gets(buf);
	}
	return *buf++;
}

void read_B() {
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			matrix[y][x] = getc() - '0';
}
void write_B() {
	int i = 0;
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++) {
			printf("%d", matrix[y][x]);
			if (++i % 50 == 0) printf("\n");
		}
	if (i % 50 != 0) printf("\n");
}

void read_D(int x0, int y0, int x1, int y1) {
	char c = getc();
	
	if (c != 'D') {
		c -= '0';
		for (int y = y0; y < y1; y++)
			for (int x = x0; x < x1; x++)
				matrix[y][x] = c;
		return;
	}
	
	int x = (x0 + x1) / 2 + (x0 + x1) % 2,
		y = (y0 + y1) / 2 + (y0 + y1) % 2;
	
	read_D(x0, y0, x, y);
	if (x != x1) read_D(x, y0, x1, y);
	if (y != y1) {
		read_D(x0, y, x, y1);
		if (x != x1) read_D(x, y, x1, y1);
	}
}
char *gen_D(int x0, int y0, int x1, int y1) {
	int x = (x0 + x1) / 2 + (x0 + x1) % 2,
		y = (y0 + y1) / 2 + (y0 + y1) % 2;
	
	if (x == x1 && y == y1) {
		char *res = new char[2]; res[0] = (char)matrix[y0][x0] + '0', res[1] = '\0';
		return res;
	}
	
	char *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL;
	
	c1 = gen_D(x0, y0, x, y);
	if (x != x1) c2 = gen_D(x, y0, x1, y);
	if (y != y1) {
		c3 = gen_D(x0, y, x, y1);
		if (x != x1) c4 = gen_D(x, y, x1, y1);
	}
	
	if (*c1 != 'D' && (c4 == NULL || *c4 == *c1) && (c2 == NULL || *c2 == *c1) && (c3 == NULL || *c3 == *c1))
		return c1;
	
	char *res = new char[LEN(c1) + LEN(c2) + LEN(c3) + LEN(c4) + 5]; res[0] = 'D', res[1] = '\0';
	if (c1 != NULL) strcat(res, c1);
	if (c2 != NULL) strcat(res, c2);
	if (c3 != NULL) strcat(res, c3);
	if (c4 != NULL) strcat(res, c4);
	
	return res;
}
void write_D(char *res) {
	int i = 0;
	while (*res != '\0') {
		printf("%c", *res++);
		if (++i % 50 == 0) printf("\n");
	}
	if (i % 50 != 0) printf("\n");
}

int main() {
	char F;
	while (scanf("%c", &F), F != '#') {
		scanf("%d %d\n", &R, &C);
		if (F == 'B') {
			read_B();
			printf("D%4d%4d\n", R, C);
			write_D(gen_D(0, 0, C, R));
		} else {
			read_D(0, 0, C, R);
			printf("B%4d%4d\n", R, C);
			write_B();
		}
	}
}
