#include <cstdio>
#include <cstring>

#define SIZE 100005
#define LSOne(x) (x & (-x))

using namespace std;

class FTree {
private:
	int N, *ft;
	
	int rsq(int i) {
		int sum = 0;
		for ( ; i; i -= LSOne(i))
			sum += ft[i];
		return sum;
	}
public:
	FTree(int _N) {
		N = _N;
		ft = new int[N];
		memset(ft, 0, sizeof(int) * N);
	}
	
	int rsq(int l, int r) {
		return rsq(r) - rsq(l - 1);
	}
	void adjust(int i, int v) {
		for ( ; i < N; i += LSOne(i))
			ft[i] += v;
	}
};

int main() {
	int N, RC, *A = new int[SIZE];
	char *result = new char[SIZE];
	
	while (scanf("%d %d", &N, &RC) != EOF) {
		FTree ft_zeros(++N);
		FTree ft_negatives(N);
		int i, v;
		
		for (i = 1; i < N; i++) {
			scanf("%d", &v);
			A[i] = v;
			
			if (v == 0) ft_zeros.adjust(i, 1);
			else if (v < 0) ft_negatives.adjust(i, 1);
		}
		
		char buf[5];
		int result_i = 0;
		while (RC--) {
			scanf("%s %d %d", buf, &i, &v);
			
			if (*buf == 'P') {
				if (ft_zeros.rsq(i, v)) result[result_i++] = '0';
				else if (ft_negatives.rsq(i, v) % 2) result[result_i++] = '-';
				else result[result_i++] = '+';
				
				continue;
			}
			
			if (v == 0) {
				if (A[i] == 0) continue;
				ft_zeros.adjust(i, 1);
				if (A[i] < 0) ft_negatives.adjust(i, -1);
			} else if (v < 0) {
				if (A[i] < 0) continue;
				ft_negatives.adjust(i, 1);
				if (A[i] == 0) ft_zeros.adjust(i, -1);
			} else {
				if (A[i] > 0) continue;
				if (A[i] == 0) ft_zeros.adjust(i, -1);
				else ft_negatives.adjust(i, -1);
			}
			
			A[i] = v;
		}
		
		result[result_i] = '\0';
		printf("%s\n", result);
	}
}
