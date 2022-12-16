#include <cstdio>

#define SIZE 100005

class STree {
private:
	int n, *A, *st = new int[SIZE * 4],
		*r_count = new int[SIZE * 4], *l_count = new int[SIZE * 4];
	
	int left(int p) {
		return p << 1;
	}
	int right(int p) {
		return (p << 1) + 1;
	}
	
	void build(int p, int SL, int SR) {
		if (SL == SR) {
			st[p] = r_count[p] = l_count[p] = 1;
			return;
		}
		
		int l_child = left(p), r_child = right(p);
		build(l_child, SL, (SL + SR) / 2);
		build(r_child, (SL + SR) / 2 + 1, SR);
		
		r_count[p] = r_count[r_child];
		if (A[(SL + SR) / 2] == A[SR])
			r_count[p] += r_count[l_child];
		l_count[p] = l_count[l_child];
		if (A[SL] == A[(SL + SR) / 2 + 1])
			l_count[p] += l_count[r_child];
		
		int p1 = st[l_child], p2 = st[r_child];
		if (A[(SL + SR) / 2] == A[(SL + SR) / 2 + 1]) {
			int p3 = r_count[l_child] + l_count[r_child];
			if (p3 > p1 && p3 > p2) {
				st[p] = p3;
				return;
			}
		}
		
		st[p] = p1 > p2 ? p1 : p2;
	}
	int rfmq(int p, int SL, int SR, int l, int r) {
		if (r < SL || SR < l) return -1;
		if (l <= SL && SR <= r) return st[p];
		
		int l_child = left(p), r_child = right(p), mid = (SL + SR) / 2,
			p1 = rfmq(l_child, SL, mid, l, r),
			p2 = rfmq(r_child, mid + 1, SR, l, r);
		
		if (p1 == -1) return p2;
		if (p2 == -1) return p1;
		
		if (A[mid] == A[mid + 1]) {
			int min_l = mid - l + 1;
			min_l = (min_l > r_count[l_child]) ? r_count[l_child] : min_l;
			
			int min_r = r - mid;
			min_r = (min_r > l_count[r_child]) ? l_count[r_child] : min_r;
			
			int p3 = min_l + min_r;
			if (p3 > p1 && p3 > p2) return p3;
		}
		
		return p1 > p2 ? p1 : p2;
	}
public:
	STree(int *_A, int _n) {
		A = _A;
		n = _n;
		build(1, 1, n);
	}
	
	int rfmq(int l, int r) {
		return rfmq(1, 1, n, l, r);
	}
};

int *A = new int[SIZE];

void solve(int n)
{
	int QC;
	scanf("%d", &QC);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	
	STree st(A, n);
	
	int l, r;
	while (QC--) {
		scanf("%d %d", &l, &r);
		printf("%d\n", st.rfmq(l, r));
	}
}

int main()
{
	int n;
	
	while (scanf("%d", &n), n != 0)
		solve(n);
}
