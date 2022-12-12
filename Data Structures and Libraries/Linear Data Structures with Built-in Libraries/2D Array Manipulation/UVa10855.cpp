#include <cstdio>
#include <cstring>

int main()
{
	char mat[500][500], smat1[500][500], smat2[500][500], smat3[500][500], smat4[500][500];
	int n, sn, i, x, y, dif, c1, c2, c3, c4;
	bool f1, f2, f3, f4;
	
	while (scanf("%d %d", &n, &sn), n != 0 || sn != 0) {
		for (i = 0; i < n; i++)
			scanf("%s", mat[i]);
		for (i = 0; i < sn; i++)
			scanf("%s", smat1[i]);
		
		for (y = 0; y < sn; y++)
			for (x = 0; x < sn; x++) {
				smat2[y][x] = smat1[sn - 1 - x][y];
				smat3[y][x] = smat1[sn - 1 - y][sn - 1 - x];
				smat4[y][x] = smat1[x][sn - 1 - y];
			}
		
		dif = n - sn;
		c1 = 0, c2 = 0, c3 = 0, c4 = 0;
		for (y = 0; y <= dif; y++)
			for (x = 0; x <= dif; x++) {
				f1 = true, f2 = true; f3 = true; f4 = true;
				for (i = 0; i < sn; i++) {
					if (f1 && memcmp(mat[i + y] + x, smat1[i], sn))
						f1 = false;
					if (f2 && memcmp(mat[i + y] + x, smat2[i], sn))
						f2 = false;
					if (f3 && memcmp(mat[i + y] + x, smat3[i], sn))
						f3 = false;
					if (f4 && memcmp(mat[i + y] + x, smat4[i], sn))
						f4 = false;
				}
				if (f1) c1++;
				if (f2) c2++;
				if (f3) c3++;
				if (f4) c4++;
			}
		
		printf("%d %d %d %d\n", c1, c2, c3, c4);
	}
}
